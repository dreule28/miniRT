#include "mini_rt.h"

bool	init_mlx_window(t_scene *scene)
{
	scene->mlx = mlx_init(100, 100, "miniRT", true);
	if (!scene->mlx)
	{
		printf("Failed to initialize MLX\n");
		return (false);
	}
	scene->img = mlx_new_image(scene->mlx, 100, 100);
	if (!scene->img)
	{
		printf("Failed to create image\n");
		mlx_terminate(scene->mlx);
		return (false);
	}
	ft_memset(scene->img->pixels, 128, scene->img->width
			* scene->img->height * sizeof(int32_t));
	if (mlx_image_to_window(scene->mlx, scene->img, 0, 0) < 0)
	{
		printf("Failed to display image\n");
		mlx_terminate(scene->mlx);
		return (false);
	}
	return (true);
}

void	scroll_hook(double xdelta, double ydelta , void *param)
{
	t_scene	*scene;

	(void)xdelta;
	scene = (t_scene *)param;
	uint32_t	*pixels;
	pixels = (uint32_t *)scene->img->pixels;
	if (ydelta > 0)
		scene->camera.pos.z +=1;
	else if (ydelta < 0)
		scene->camera.pos.z -=1;
}

void	mlx_custom_hooks(t_scene *scene)
{
	mlx_loop_hook(scene->mlx, &ray_tracing, scene);
	mlx_key_hook(scene->mlx, &key_hook, scene);
	mlx_scroll_hook(scene->mlx, &scroll_hook, scene);
}

uint32_t create_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	uint32_t	*pixels;
	pixels = (uint32_t *)scene->img->pixels;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(scene->mlx);
		if (keydata.key == MLX_KEY_W)
			scene->camera.pos.y += 1;
		if (keydata.key == MLX_KEY_S)
			scene->camera.pos.y -= 1;
		if (keydata.key == MLX_KEY_A)
			scene->camera.pos.x -= 1;
		if (keydata.key == MLX_KEY_D)
			scene->camera.pos.x += 1;
	}
}

t_sphere	*ray_hits_sphere(t_scene *scene, t_ray *ray)
{
    t_obj_node	*curr;

    curr = scene->obj_list->head;
    while (curr)
    {
        if (curr->type == SPHERE)
        {
            // Apply transformations if any
            t_ray *transformed_ray = ray;
            if (curr->data->sphere->matrix)
            {
                t_m4 *inv = ftm_m4_inversion(curr->data->sphere->matrix);
                if (inv)
                {
                    transformed_ray = transform_ray(ray, inv);
                    free(inv);
                }
            }

            double *t = intersect_sphere(transformed_ray, curr->data->sphere);

            if (transformed_ray != ray)
                free_ray(transformed_ray);

            if (t)
            {
                free(t);
                return (curr->data->sphere);
            }
        }
        curr = curr->next;
    }
    return (NULL);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (a << 24 | b << 16 | g << 8 | r);
}

void	ray_tracing(void *param)
{
    t_scene		*scene;
    uint32_t	*pixels;
    int			x, y;

    scene = (t_scene *)param;
    pixels = (uint32_t *)scene->img->pixels;

    // Book's suggested values
    t_tuples	*ray_origin = init_point(scene->camera.pos.x,scene->camera.pos.y, scene->camera.pos.z);
    double		wall_z = 10;
    double		wall_size = 7.0;
    int			canvas_pixels = 100; // Start small for testing
    double		pixel_size = wall_size / canvas_pixels;
    double		half = wall_size / 2;

    // Cast rays for each pixel
    for (y = 0; y < canvas_pixels; y++)
    {
        // Convert canvas y to world y (flip coordinate)
        double world_y = half - pixel_size * y;

        for (x = 0; x < canvas_pixels; x++)
        {
            // Convert canvas x to world x
            double world_x = -half + pixel_size * x;

            // Target point on the wall
            t_tuples *position = init_point(world_x, world_y, wall_z);

            // Direction from ray origin to wall point
            t_tuples *direction = ftm_tup_subtract(position, ray_origin);
            t_tuples *normalized_dir = ftm_tup_norm(direction);
            // Create ray
            t_ray *ray = init_ray(ray_origin, normalized_dir);

            // Test intersection with sphere
            t_sphere *hit = ray_hits_sphere(scene, ray);

            // Set pixel color
            int pixel_index = y * canvas_pixels + x;
            if (pixel_index < (int)scene->img->width * (int)scene->img->height)
            {
                if (hit)
                    pixels[pixel_index] = get_rgba(hit->rgb.r, hit->rgb.g, hit->rgb.b, 255); // Red
                else
                    pixels[pixel_index] = get_rgba(0, 0, 0, 255);   // Black
            }

            // Cleanup
            free(position);
            free(direction);
            free(normalized_dir);
            free_ray(ray);
        }
    }

    free(ray_origin);
}

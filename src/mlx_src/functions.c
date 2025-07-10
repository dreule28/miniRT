#include "mini_rt.h"

bool	init_mlx_window(t_scene *scene)
{
	scene->mlx = mlx_init(WIDTH, HEIGHT, "miniRT", false);
	if (!scene->mlx)
	{
		printf("Failed to initialize MLX\n");
		return (false);
	}
	scene->img = mlx_new_image(scene->mlx,WIDTH, HEIGHT );
	if (!scene->img)
	{
		printf("Failed to create image\n");
		mlx_terminate(scene->mlx);
		return (false);
	}
	if (mlx_image_to_window(scene->mlx, scene->img, 0, 0) < 0)
	{
		printf("Failed to display image\n");
		mlx_terminate(scene->mlx);
		return (false);
	}
	return (true);
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_scene		*scene;
	uint32_t	*pixels;

	(void)xdelta;
	scene = (t_scene *)param;
	pixels = (uint32_t *)scene->img->pixels;
	if (ydelta > 0)
		scene->camera.pos.z += 0.2;
	else if (ydelta < 0)
		scene->camera.pos.z -= 0.2;
}

void	cursor_hook(double xpos, double ypos, void *param)
{
	t_scene		*scene;
	double		center_x;
	double		center_y;
	uint32_t	*pixels;

	scene = (t_scene *)param;
	pixels = (uint32_t *)scene->img->pixels;
	center_x = WIDTH / 2;
	center_y = HEIGHT / 2;
	scene->camera.orientation_vector.x += (xpos - center_x) * 0.001;
	scene->camera.orientation_vector.y += (ypos - center_y) * 0.001;
	mlx_set_mouse_pos(scene->mlx, center_x, center_y);
}

void	print_terminal_update(t_scene *scene)
{
	// Move cursor up 4 lines (to x/y/z of position line)
	printf("\033[4A");

	// Overwrite camera pos line
	printf("\r\033[Kx : %.6f y : %.6f z : %.6f\n",
		scene->camera.pos.x,
		scene->camera.pos.y,
		scene->camera.pos.z);
	printf("camera orientation vecotr");
	// Overwrite camera orientation line
	printf("\r\033[Kx : %.6f y : %.6f z : %.6f\n",
		scene->camera.orientation_vector.x,
		scene->camera.orientation_vector.y,
		scene->camera.orientation_vector.z);

	// Move back down to the line after the === line
	printf("\033[2B");

	fflush(stdout);
}

void	update_camera(void *param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	print_terminal_update(scene);
	if (scene->camera.movement.key_w)
		scene->camera.pos.y += 0.08;
	if (scene->camera.movement.key_s)
		scene->camera.pos.y -= 0.08;
	if (scene->camera.movement.key_a)
		scene->camera.pos.x -= 0.08;
	if (scene->camera.movement.key_d)
		scene->camera.pos.x += 0.08;
}

void	mlx_custom_hooks(t_scene *scene)
{
	mlx_loop_hook(scene->mlx, &ray_tracing, scene);
	mlx_key_hook(scene->mlx, &key_hook, scene);
	mlx_scroll_hook(scene->mlx, &scroll_hook, scene);
	mlx_loop_hook(scene->mlx, &update_camera, scene);
	mlx_set_cursor_mode(scene->mlx, MLX_MOUSE_DISABLED);
	mlx_cursor_hook(scene->mlx, &cursor_hook, scene);
}

uint32_t	create_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(scene->mlx);
	if (keydata.key == MLX_KEY_W)
		scene->camera.movement.key_w = (keydata.action != MLX_RELEASE);
	if (keydata.key == MLX_KEY_S)
		scene->camera.movement.key_s = (keydata.action != MLX_RELEASE);
	if (keydata.key == MLX_KEY_A)
		scene->camera.movement.key_a = (keydata.action != MLX_RELEASE);
	if (keydata.key == MLX_KEY_D)
		scene->camera.movement.key_d = (keydata.action != MLX_RELEASE);
}

t_sphere	*ray_hits_sphere(t_scene *scene, t_ray *ray)
{
	t_obj_node	*curr;
	t_ray		*transformed_ray;
	t_m4		*inv;
	double		*t;

	curr = scene->obj_list->head;
	while (curr)
	{
		if (curr->type == SPHERE)
		{
			// Apply transformations if any
			transformed_ray = ray;
			if (curr->data->sphere->matrix)
			{
				inv = ftm_m4_inversion(curr->data->sphere->matrix);
				if (inv)
				{
					transformed_ray = transform_ray(ray, inv);
					free(inv);
				}
			}
			t = intersect_sphere(transformed_ray, curr->data->sphere);
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
	t_tuples	*ray_origin;
	double		wall_z;
	double		wall_size;
	double		pixel_size;
	double		half;
	double		world_y;
	double		world_x;
	t_tuples	*position;
	t_tuples	*direction;
	t_tuples	*normalized_dir;
	t_ray		*ray;
	t_sphere	*hit;
	int			pixel_index;

	int x, y;
	scene = (t_scene *)param;
	pixels = (uint32_t *)scene->img->pixels;
	// Book's suggested values
	ray_origin = init_point(scene->camera.pos.x, scene->camera.pos.y,
			scene->camera.pos.z);
	wall_z = HEIGHT * 0.1;
	wall_size = WIDTH * 0.07;
	int canvas_pixels = HEIGHT; // Start small for testing
	pixel_size = wall_size / canvas_pixels;
	half = wall_size / 2;
	// Cast rays for each pixel
	for (y = 0; y < canvas_pixels; y++)
	{
		// Convert canvas y to world y (flip coordinate)
		world_y = half - pixel_size * y;
		for (x = 0; x < canvas_pixels; x++)
		{
			// Convert canvas x to world x
			world_x = -half + pixel_size * x;
			// Target point on the wall
			position = init_point(world_x, world_y, wall_z);
			// Direction from ray origin to wall point
			direction = ftm_tup_subtract(position, ray_origin);
			normalized_dir = ftm_tup_norm(direction);
			// Create ray
			ray = init_ray(ray_origin, normalized_dir);
			// Test intersection with sphere
			hit = ray_hits_sphere(scene, ray);
			// Set pixel color
			pixel_index = y * canvas_pixels + x;
			if (pixel_index < (int)scene->img->width * (int)scene->img->height)
			{
				if (hit)
					pixels[pixel_index] = get_rgba(hit->rgb.r, hit->rgb.g,
							hit->rgb.b, 255); // Red
				else
					pixels[pixel_index] = get_rgba(0, 0, 0, 255); // Black
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

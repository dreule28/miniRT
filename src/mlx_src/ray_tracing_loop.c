#include "mini_rt.h"

void	ray_tracing(void *param)
{
	t_scene		*scene;
	t_tuples	*window_cord;
	t_tuples	*world_cord;
	double		pixel_size;
	double		half;

	scene = (t_scene *)param;
	window_cord = init_point(0, 0, HEIGHT * 0.1);
	world_cord = init_point(0, 0, 0);
	pixel_size = WIDTH * 0.07 / HEIGHT;
	half = WIDTH * 0.07 / 2;
	while (window_cord->y < HEIGHT)
	{
		world_cord->y = half - pixel_size * window_cord->y;
		window_cord->x = 0;
		while (window_cord->x < WIDTH)
		{
			world_cord->x = -half + pixel_size * window_cord->x;
			calculate_ray(scene, window_cord, world_cord);
			window_cord->x++;
		}
		window_cord->y++;
	}
}

void	paint_pixel(t_scene *scene, t_ray *ray, int pixel_index)
{
	double		*hit;
	uint32_t	*pixels;

	pixels = (uint32_t *)scene->img->pixels;
	intersect_to_list(scene, ray);
	hit = hit_obj(scene);
	if (pixel_index < (int)scene->img->width * (int)scene->img->height)
	{
		if (hit)
			pixels[pixel_index] = get_rgba(255, 0, 0, 255);
		else
			pixels[pixel_index] = get_rgba(0, 0, 0, 255);
	}
}

t_ray	*setup_shooting_ray(t_tuples *ray_origin, double world_x,
		double world_y, double wall_z)
{
	t_tuples	*position;
	t_tuples	*direction;
	t_tuples	*normalized_dir;
	t_ray		*ray;

	position = init_point(world_x, world_y, wall_z);
	direction = ftm_tup_subtract(position, ray_origin);
	normalized_dir = ftm_tup_norm(direction);
	ray = init_ray(copy_point(ray_origin), normalized_dir);
	free(position);
	free(direction);
	return (ray);
}

void	calculate_ray(t_scene *scene, t_tuples *window_cord,
		t_tuples *world_cord)
{
	t_tuples	*ray_origin;
	t_ray		*ray;
	int			pixel_index;

	ray_origin = copy_point(&scene->camera.pos);
	ray = setup_shooting_ray(ray_origin, world_cord->x, world_cord->y,
			window_cord->z);
	pixel_index = window_cord->y * HEIGHT + window_cord->x;
	paint_pixel(scene, ray, pixel_index);
	// free_ray(ray);
}

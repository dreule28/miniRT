#include "mini_rt.h"

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
}

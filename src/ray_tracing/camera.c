#include "mini_rt.h"

t_ray	*ray_for_pixel(t_camera *camera, double px, double py)
{
	double		xoffset;
	double		yoffset;
	double		world_x;
	double		world_y;
	t_tuples	*origin;
	t_tuples	*pixel;
	t_tuples	*direction;

	xoffset = (px + 0.5) * camera->pixel_size;
	yoffset = (py + 0.5) * camera->pixel_size;
	world_x = camera->half_width - xoffset;
	world_y = camera->half_height - yoffset;
	pixel = ftm_matrix_times_tuple(ftm_m4_inversion(camera->matrix),
			init_point(world_x, world_y, -1));
	origin = ftm_matrix_times_tuple(ftm_m4_inversion(camera->matrix),
			init_point(0, 0, 0));
	direction = ftm_tup_norm(ftm_tup_subtract(pixel, origin));
	return (init_ray(origin, direction));
}


void	render(t_scene *scene)
{
	t_ray	*ray;
	int		y;
	int		x;

	y = 0;
	while (y < scene->camera.vsize)
	{
		x = 0;
		while (x < scene->camera.hsize)
		{
			ray = ray_for_pixel(&scene->camera, x, y);
			paint_pixel(scene, ray, y * scene->camera.hsize + x);
			free_tuple(ray->origin);
			free_tuple(ray->direction);
			x++;
		}
		y++;
	}
}

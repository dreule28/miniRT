#include "mini_rt.h"

t_ray	*calculate_ray_for_pixel(t_camera *camera, double world_x,
	double world_y)
{
	t_tuples	*origin;
	t_tuples	*pixel;
	t_tuples	*direction;

	pixel = ftm_matrix_times_tuple(ftm_m4_inversion(camera->matrix),
			init_point(world_x, world_y, -1));
	origin = ftm_matrix_times_tuple(ftm_m4_inversion(camera->matrix),
			init_point(0, 0, 0));
	direction = ftm_tup_norm(ftm_tup_subtract(pixel, origin));
	return (init_ray(origin, direction));
}

t_ray	*ray_for_pixel(t_camera *camera, double px, double py)
{
	double		xoffset;
	double		yoffset;
	double		world_x;
	double		world_y;
	t_ray		*ray;

	xoffset = (px + 0.5) * camera->pixel_size;
	yoffset = (py + 0.5) * camera->pixel_size;
	world_x = camera->half_width - xoffset;
	world_y = camera->half_height - yoffset;
	ray = calculate_ray_for_pixel(camera, world_x, world_y);
	return (ray);
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
			free_ray(ray);
			x++;
		}
		y++;
	}
}

t_m4	*init_view_transformation(t_scene *scene)
{
	t_tuples	*from;
	t_tuples	*to;
	t_tuples	*up;
	t_m4		*result;

	from = init_point(scene->camera.pos.x, scene->camera.pos.y,
			scene->camera.pos.z);
	to = init_point(scene->camera.pos.x + scene->camera.orientation_vector.x,
			scene->camera.pos.y + scene->camera.orientation_vector.y,
			scene->camera.pos.z + scene->camera.orientation_vector.z);
	up = init_vector(0, 1, 0);
	result = view_transformation(from, to, up);
	return (result);
}

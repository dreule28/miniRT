#include "mini_rt.h"

void	calculate_ray_for_pixel(t_ray *ray, t_m4 inv, double world_x,
		double world_y)
{
	t_tuples	origin;
	t_tuples	pixel;
	t_tuples	direction;
	t_tuples	point;

	init_point(&point, world_x, world_y, -1);
	ftm_matrix_times_tuple(&pixel, inv, point);
	init_point(&point, 0, 0, 0);
	ftm_matrix_times_tuple(&origin, inv, point);
	ftm_tup_subtract(&point, pixel, origin);
	ftm_tup_norm(&direction, point);
	init_ray(ray, origin, direction);
}

void	ray_for_pixel(t_ray *ray, t_camera *camera, t_m4 inv, double px,
		double py)
{
	double	xoffset;
	double	yoffset;
	double	world_x;
	double	world_y;

	xoffset = (px + 0.5) * camera->pixel_size;
	yoffset = (py + 0.5) * camera->pixel_size;
	world_x = camera->half_width - xoffset;
	world_y = camera->half_height - yoffset;
	calculate_ray_for_pixel(ray, inv, world_x, world_y);
}

void	ray_for_sample(t_ray *ray, t_camera *camera, t_m4 inv, double px,
		double py, double sx, double sy)
{
	double	xoffset;
	double	yoffset;
	double	world_x;
	double	world_y;

	xoffset = (px + sx) * camera->pixel_size;
	yoffset = (py + sy) * camera->pixel_size;
	world_x = camera->half_width - xoffset;
	world_y = camera->half_height - yoffset;
	calculate_ray_for_pixel(ray, inv, world_x, world_y);
}

void	shade_single_ray(t_scene *scene, t_ray *ray, t_rgb *out)
{
	t_tuples	normalized;

	init_rgb(out, 0, 0, 0);
	ftm_tup_norm(&normalized, ray->direction);
	ray->direction = normalized;
	intersect_to_list(scene, ray);
	if (scene->obj_list->head && scene->obj_list->head->has_intersection)
	{
		if (!set_comp_to_obj(scene->obj_list->head, ray))
			return ;
		get_shaded_with_shadows(out, scene, 4);
	}
}

void	aa_cal_color(t_rgb *acc)
{
	double	inv_samples;

	inv_samples = 1.0 / (AA_GRID * AA_GRID);
	acc->r *= inv_samples;
	acc->g *= inv_samples;
	acc->b *= inv_samples;
	if (acc->r > 1.0)
		acc->r = 1.0;
	if (acc->g > 1.0)
		acc->g = 1.0;
	if (acc->b > 1.0)
		acc->b = 1.0;
}

void	aa_loop(t_scene *scene, t_ray *ray, t_m4 inv, t_rgb *acc, int x, int y)
{
	int		oy;
	int		ox;
	double	fx;
	double	fy;
			t_rgb sample;

	oy = 0;
	while (oy < AA_GRID)
	{
		ox = 0;
		while (ox < AA_GRID)
		{
			fx = (ox + 0.5) / AA_GRID;
			fy = (oy + 0.5) / AA_GRID;
			ray_for_sample(ray, &scene->camera, inv, x, y, fx, fy);
			shade_single_ray(scene, ray, &sample);
			acc->r += sample.r;
			acc->g += sample.g;
			acc->b += sample.b;
			ox++;
		}
		oy++;
	}
}

void	anti_aliasing(t_scene *scene, t_ray *ray, t_m4 inv, int x, int y)
{
	uint32_t	*pixels;
	int			pixel_index;
	t_rgb		acc;

	pixels = (uint32_t *)scene->img->pixels;
	pixel_index = y * scene->camera.hsize + x;
	init_rgb(&acc, 0, 0, 0);
	aa_loop(scene, ray, inv, &acc, x, y);
	aa_cal_color(&acc);
	pixels[pixel_index] = get_rgba((int)(acc.r * 255.0), (int)(acc.g * 255.0),
			(int)(acc.b * 255.0), 255);
}

void	render(t_scene *scene)
{
	t_ray	ray;
	t_m4	inv;
	int		y;
	int		x;

	ftm_m4_inversion(&inv, scene->camera.matrix);
	y = 0;
	while (y < scene->camera.vsize)
	{
		x = 0;
		while (x < scene->camera.hsize)
		{
			if (AA_GRID == 1)
			{
				ray_for_pixel(&ray, &scene->camera, inv, x, y);
				paint_pixel(scene, &ray, y * scene->camera.hsize + x);
			}
			else
				anti_aliasing(scene, &ray, inv, x, y);
			x++;
		}
		y++;
	}
}

void	init_view_transformation(t_m4 *matrix, t_scene *scene)
{
	t_tuples	from;
	t_tuples	to;
	t_tuples	up;

	init_point(&from, scene->camera.pos.x, scene->camera.pos.y,
		scene->camera.pos.z);
	init_point(&to, scene->camera.pos.x + scene->camera.orientation_vector.x,
		scene->camera.pos.y + scene->camera.orientation_vector.y,
		scene->camera.pos.z + scene->camera.orientation_vector.z);
	init_vector(&up, 0, 1, 0);
	view_transformation(matrix, from, to, up);
}

#include "mini_rt.h"

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
	t_rgb	sample;

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

#include "mini_rt.h"

void	apply_lighting(t_scene *scene, t_ray *ray, double *hit_t,
	int pixel_index)
{
	uint32_t	*pixels;
	t_tuples	*point;
	t_tuples	*normal;
	t_tuples	*eyev;
	t_rgb		shaded;

	pixels = (uint32_t *)scene->img->pixels;
	point = ray_position(ray, *hit_t);
	normal = normal_at(scene->obj_list->head->data->sphere, point);
	eyev = ftm_tup_negate(ray->direction);
	shaded = lighting(scene, point, eyev, normal);
	if (shaded.r > 1.0)
		shaded.r = 1.0;
	if (shaded.g > 1.0)
		shaded.g = 1.0;
	if (shaded.b > 1.0)
		shaded.b = 1.0;
	pixels[pixel_index] = get_rgba((int)(shaded.r * 255),
			(int)(shaded.g * 255), (int)(shaded.b * 255), 255);
	free(point);
	free(normal);
	free(eyev);
}

void	paint_pixel(t_scene *scene, t_ray *ray, int pixel_index)
{
	uint32_t	*pixels;
	double		*hit_t;
	t_tuples	*normalized;

	pixels = (uint32_t *)scene->img->pixels;
	normalized = ftm_tup_norm(ray->direction);
	free(ray->direction);
	ray->direction = normalized;
	intersect_to_list(scene, ray);
	hit_t = hit_obj(scene);
	if (hit_t)
	{
		apply_lighting(scene, ray, hit_t, pixel_index);
		free(hit_t);
	}
	else
		pixels[pixel_index] = get_rgba(0, 0, 0, 255);
}

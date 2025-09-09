#include "mini_rt.h"

void	ftm_rgb_add(t_rgb *new_rgb, t_rgb color1, t_rgb color2)
{
	new_rgb->r = color1.r + color2.r;
	new_rgb->g = color1.g + color2.g;
	new_rgb->b = color1.b + color2.b;
}

void	get_shaded_with_shadows(t_rgb *shaded, t_scene *scene, int remaining)
{
	t_rgb			*temp;
	t_light			*curr;

	curr = scene->light_list->head;
	while (curr)
	{
		temp = shade_hit(scene, *curr, remaining);
		ftm_rgb_add(shaded, *temp, *shaded);
		free(temp);
		curr = curr->next;
	}
	if (shaded->r > 1.0)
		shaded->r = 1.0;
	if (shaded->g > 1.0)
		shaded->g = 1.0;
	if (shaded->b > 1.0)
		shaded->b = 1.0;
}

void	paint_pixel(t_scene *scene, t_ray *ray, int pixel_index)
{
	uint32_t		*pixels;
	t_tuples		normalized;
	t_rgb			color;

	init_rgb(&color, 0, 0, 0);
	pixels = (uint32_t *)scene->img->pixels;
	ftm_tup_norm(&normalized, ray->direction);
	ray->direction = normalized;
	intersect_to_list(scene, ray);
	if (scene->obj_list->head && scene->obj_list->head->has_intersection)
	{
		if (!set_comp_to_obj(scene->obj_list->head, ray))
		{
			pixels[pixel_index] = get_rgba(0, 0, 0, 255);
			return ;
		}
		get_shaded_with_shadows(&color, scene, 4);
		pixels[pixel_index] = get_rgba((int)(color.r * 255), (int)(color.g
					* 255), (int)(color.b * 255), 255);
	}
	else
	{
		pixels[pixel_index] = get_rgba(0, 0, 0, 255);
	}
}

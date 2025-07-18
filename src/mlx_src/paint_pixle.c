#include "mini_rt.h"

t_rgb	*ftm_rgb_add(t_rgb *color1, t_rgb *color2)
{
	t_rgb	*new_rgb;

	new_rgb = ft_calloc(sizeof(t_rgb), 1);
	if (!new_rgb)
		return (NULL);
	new_rgb->r = color1->r + color2->r;
	new_rgb->g = color1->g + color2->g;
	new_rgb->b = color1->b + color2->b;
	return (new_rgb);
}

t_rgb	*get_shaded(t_scene *scene)
{
	t_computations	*comps;
	t_rgb			*shaded;
	t_rgb			*temp;
	t_light			*curr;

	shaded = init_rgb(0, 0, 0);
	curr = scene->light_list->head;
	comps = scene->obj_list->head->comp;
	while (curr)
	{
		temp = lighting(scene, comps, curr);
		shaded = ftm_rgb_add(temp, shaded);
		curr = curr->next;
	}
	return (shaded);
}

void	apply_lighting(t_scene *scene, int pixel_index)
{
	uint32_t	*pixels;
	t_rgb		*shaded;

	pixels = (uint32_t *)scene->img->pixels;
	shaded = get_shaded(scene);
	if (shaded->r > 1.0)
		shaded->r = 1.0;
	if (shaded->g > 1.0)
		shaded->g = 1.0;
	if (shaded->b > 1.0)
		shaded->b = 1.0;
	pixels[pixel_index] = get_rgba((int)(shaded->r * 255),
			(int)(shaded->g * 255), (int)(shaded->b * 255), 255);
}

void	paint_pixel(t_scene *scene, t_ray *ray, int pixel_index)
{
	uint32_t	*pixels;
	t_tuples	*normalized;

	pixels = (uint32_t *)scene->img->pixels;
	normalized = ftm_tup_norm(ray->direction);
	free(ray->direction);
	ray->direction = normalized;
	intersect_to_list(scene, ray);
	if (scene->obj_list->head->t && scene->obj_list->head->t[0] > 0)
		apply_lighting(scene, pixel_index);
	else
		pixels[pixel_index] = get_rgba(0, 0, 0, 255);
}

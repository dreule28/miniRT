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

t_rgb	*get_shaded_with_shadows(t_scene *scene, t_obj_node *obj_node,
			int remaining)
{
	t_computations	*comps;
	t_rgb			*shaded;
	t_rgb			*temp;
	t_light			*curr;

	shaded = init_rgb(0, 0, 0);
	curr = scene->light_list->head;
	comps = obj_node->comp;
	while (curr)
	{
		temp = shade_hit(scene, comps, curr, remaining);
		shaded = ftm_rgb_add(temp, shaded);
		free(temp);
		curr = curr->next;
	}
	if (shaded->r > 1.0)
		shaded->r = 1.0;
	if (shaded->g > 1.0)
		shaded->g = 1.0;
	if (shaded->b > 1.0)
		shaded->b = 1.0;
	return (shaded);
}

void	apply_lighting_with_shadows(t_scene *scene, int pixel_index,
		t_computations *comps)
{
	uint32_t	*pixels;
	t_rgb		*shaded;
	t_rgb		*temp;
	t_light		*curr;

	pixels = (uint32_t *)scene->img->pixels;
	shaded = init_rgb(0, 0, 0);
	curr = scene->light_list->head;
	while (curr)
	{
		temp = shade_hit(scene, comps, curr, 0);
		shaded = ftm_rgb_add(temp, shaded);
		free(temp);
		curr = curr->next;
	}
	if (shaded->r > 1.0)
		shaded->r = 1.0;
	if (shaded->g > 1.0)
		shaded->g = 1.0;
	if (shaded->b > 1.0)
		shaded->b = 1.0;
	pixels[pixel_index] = get_rgba((int)(shaded->r * 255), (int)(shaded->g
				* 255), (int)(shaded->b * 255), 255);
	free(shaded);
}

void	paint_pixel(t_scene *scene, t_ray *ray, int pixel_index)
{
	uint32_t		*pixels;
	t_tuples		*normalized;
	t_rgb			*color;

	pixels = (uint32_t *)scene->img->pixels;
	normalized = ftm_tup_norm(ray->direction);
	free(ray->direction);
	ray->direction = normalized;
	intersect_to_list(scene, ray);
	if (scene->obj_list->head->t)
	{
		if (!set_comp_to_obj(scene->obj_list->head, ray))
		{
			pixels[pixel_index] = get_rgba(0, 0, 0, 255);
			return ;
		}
		color = get_shaded_with_shadows(scene, scene->obj_list->head, 4);
		pixels[pixel_index] = get_rgba((int)(color->r * 255), (int)(color->g
				* 255), (int)(color->b * 255), 255);
		free(color);
	}
	else
		pixels[pixel_index] = get_rgba(0, 0, 0, 255);
}

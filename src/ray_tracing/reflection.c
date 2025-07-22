#include "mini_rt.h"

t_tuples	*reflect(t_tuples *in, t_tuples *normal)
{
	t_tuples	*result;
	t_tuples	*scaled_normal;
	double		dot_product;

	dot_product = 2 * ftm_tup_dot(in, normal);
	scaled_normal = ftm_tup_mult(normal, dot_product);
	if (!scaled_normal)
		return (NULL);
	result = ftm_tup_subtract(in, scaled_normal);
	free(scaled_normal);
	return (result);
}

t_light	*point_light(t_tuples position, t_rgb intensity)
{
	t_light	*light;

	light = ft_calloc(sizeof(t_light), 1);
	if (!light)
		return (NULL);
	light->pos = position;
	light->rgb = intensity;
	light->intensity = 1;
	light->next = NULL;
	return (light);
}

t_material	get_material(void)
{
	t_material	material;

	material.rgb.r = 1;
	material.rgb.g = 1;
	material.rgb.b = 1;
	material.ambient = 0.1;
	material.diffuse = 0.9;
	material.specular = 0.9;
	material.shininess = 200.0;
	material.reflective = 0;
	return (material);
}

t_rgb	*shade_hit(t_scene *scene, t_computations *comps, t_light *curr)
{
	comps->in_shadow = is_shadowed(scene, comps->over_point);
	return (lighting(scene, comps, curr));
}

t_rgb	*reflected_color(t_scene *scene)
{
	t_rgb		*color;
	t_ray		*reflected_ray;
	t_rgb		*finale_reflected;
	t_material	material;

	material = scene->obj_list->head->data->plane->material;
	if (material.reflective == 0)
		return (init_rgb(0, 0, 0));
	reflected_ray = init_ray(curr->comp->over_point, curr->comp->reflectv);
	intersect_to_list(scene, reflected_ray);
	if (!scene->obj_list->head || !scene->obj_list->head->t)
	{
		free_ray(reflected_ray);
		return (init_rgb(0, 0, 0));
	}
	color = get_shaded_with_shadows(scene, scene->obj_list->head);
	finale_reflected = ftm_rgb_mult(color, material.reflective);
	free_ray(reflected_ray);
	free(color);
	return (finale_reflected);
}

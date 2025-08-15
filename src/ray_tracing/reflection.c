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
	material.transparency = 0.0;
	material.refractive_index = 1.0;
	return (material);
}

t_rgb	*shade_hit(t_scene *scene, t_computations *comps, t_light *curr,
			int remaining)
{
	t_rgb	*surface;
	t_rgb	*reflected;
	t_rgb	*result;

	comps->in_shadow = is_shadowed(scene, comps->over_point, curr);
	surface = lighting(scene, comps, curr);
	if (!surface)
		return (NULL);
	reflected = reflected_color(scene, comps, remaining);
	if (!reflected)
		return (NULL);
	result = ftm_rgb_add(surface, reflected);
	if (!result)
		return (NULL);
	free(surface);
	free(reflected);
	return (result);
}

t_rgb	*reflected_color(t_scene *scene, t_computations *comps, int remaining)
{
	t_rgb		*color;
	t_ray		*reflected_ray;
	t_rgb		*finale_reflected;
	t_material	material;

	if (remaining <= 0)
		return (init_rgb(0, 0, 0));
	material = get_material_from_comps(comps, scene->obj_list);
	if (material.reflective == 0)
		return (init_rgb(0, 0, 0));
	reflected_ray = init_ray(comps->over_point, comps->reflectv);
	intersect_to_list(scene, reflected_ray);
	if (!scene->obj_list->head || !scene->obj_list->head->t)
	{
		return (init_rgb(0, 0, 0));
	}
	color = get_shaded_with_shadows(scene, scene->obj_list->head, remaining - 1);
	finale_reflected = ftm_rgb_mult(color, material.reflective);
	free(color);
	return (finale_reflected);
}

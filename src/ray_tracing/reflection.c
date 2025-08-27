#include "mini_rt.h"

void	reflect(t_tuples *result, t_tuples in, t_tuples normal)
{
	t_tuples	scaled_normal;
	double		dot_product;

	dot_product = 2 * ftm_tup_dot(in, normal);
	ftm_tup_mult(&scaled_normal, normal, dot_product);
	ftm_tup_subtract(result, in, scaled_normal);
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

t_rgb	*shade_hit(t_scene *scene, t_light curr, int remaining)
{
	t_rgb			surface;
	t_rgb			reflected;
	t_rgb			*result;
	t_computations	comps;

	result = ft_calloc(sizeof(t_rgb), 1);
	if (!result)
		return (NULL);
	comps = scene->obj_list->head->comp;
	comps.in_shadow = is_shadowed(scene, comps.over_point, curr);
	lighting(&surface, scene, comps, curr);
	reflected_color(&reflected, scene, comps, remaining);
	ftm_rgb_add(result, surface, reflected);
	return (result);
}

void	reflected_color(t_rgb *reflected, t_scene *scene,
			t_computations comps, int remaining)
{
	t_rgb		colr;
	t_ray		reflected_ray;
	t_material	material;

	if (remaining <= 0)
		return ;
	material = get_material_from_comps(comps, scene->obj_list);
	if (material.reflective == 0)
		return ;
	init_ray(&reflected_ray, comps.over_point, comps.reflectv);
	intersect_to_list(scene, &reflected_ray);
	if (!scene->obj_list->head || !scene->obj_list->head->t)
	{
		// init_rgb(reflected, 0, 0, 0);
		return ;
	}
	get_shaded_with_shadows(&colr, scene, remaining - 1);
	ftm_rgb_mult(reflected, colr, material.reflective);
}

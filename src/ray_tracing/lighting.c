#include "mini_rt.h"

void	calculate_lighting_components(t_rgb *result, t_material material, t_light light,
		double light_dot_normal)
{
	t_rgb	effective_color;
	t_rgb	ambient;
	t_rgb	diffuse;

	init_rgb(&ambient, 0, 0, 0);
	effective_color.r = material.rgb.r * light.rgb.r * light.intensity;
	effective_color.g = material.rgb.g * light.rgb.g * light.intensity;
	effective_color.b = material.rgb.b * light.rgb.b * light.intensity;
	ambient.r = effective_color.r * material.ambient;
	ambient.g = effective_color.g * material.ambient;
	ambient.b = effective_color.b * material.ambient;
	if (light_dot_normal < 0)
	{
		init_rgb(result, ambient.r, ambient.g, ambient.b);
		return ;
	}
	diffuse.r = effective_color.r * material.diffuse * light_dot_normal;
	diffuse.g = effective_color.g * material.diffuse * light_dot_normal;
	diffuse.b = effective_color.b * material.diffuse * light_dot_normal;
	init_rgb(result, ambient.r + diffuse.r, ambient.g + diffuse.g, ambient.b
			+ diffuse.b);
}

t_material	get_obj_mat(t_scene *scene)
{
	t_material	mat;

	if (scene->obj_list->head->type == SPHERE)
	{
		mat = scene->obj_list->head->data->sphere->material;
		if (scene->obj_list->head->comp.inside)
			mat.ambient = 1.0;
	}
	else if (scene->obj_list->head->type == PLANE)
		mat = scene->obj_list->head->data->plane->material;
	else if (scene->obj_list->head->type == CYLINDER)
		mat = scene->obj_list->head->data->cylinder->material;
	else if (scene->obj_list->head->type == CUBE)
		mat = scene->obj_list->head->data->cube->material;
	else if (scene->obj_list->head->type == CONE)
		mat = scene->obj_list->head->data->cone->material;
	else
		mat = get_material();
	return (mat);
}

void	calculate_specular(t_rgb *specular, t_scene *scene, t_tuples lightv,
			t_computations comps)
{
	t_material	material;
	t_light		*light;
	double		reflect_dot_eye;
	double		factor;
	t_tuples	refl;

	material = get_obj_mat(scene);
	light = scene->light_list->head;
	ftm_tup_negate(&lightv);
	reflect(&refl, lightv, comps.normalv);
	reflect_dot_eye = ftm_tup_dot(refl, comps.eyev);
	if (reflect_dot_eye <= 0)
		init_rgb(specular, 0, 0, 0);
	else
	{
		factor = pow(reflect_dot_eye, material.shininess);
		specular->r = light->rgb.r * light->intensity * material.specular
			* factor;
		specular->g = light->rgb.g * light->intensity * material.specular
			* factor;
		specular->b = light->rgb.b * light->intensity * material.specular
			* factor;
	}
}

void	ambient_comp(t_rgb *result, t_material material, t_light light)
{
	t_rgb	effective_color;

	effective_color.r = material.rgb.r * light.rgb.r * light.intensity;
	effective_color.g = material.rgb.g * light.rgb.g * light.intensity;
	effective_color.b = material.rgb.b * light.rgb.b * light.intensity;
	init_rgb(result, effective_color.r * material.ambient,
			effective_color.g * material.ambient,
			effective_color.b * material.ambient);
}

void	lighting(t_rgb *res, t_scene *scene, t_computations comps,
			t_light light)
{
	t_material	material;
	t_tuples	lightv;
	double		light_dot_normal;
	t_rgb		specular;

	material = get_material_from_comps(comps, scene->obj_list);
	ftm_tup_subtract(&lightv, light.pos, comps.over_point);
	ftm_tup_norm(&lightv, lightv);
	light_dot_normal = ftm_tup_dot(lightv, comps.normalv);
	if(material.pattern.has_pattern)
		pattern_at_shape(&material.rgb, material.pattern,
			*scene->obj_list->head, scene->obj_list->head->comp.over_point);
	if (comps.in_shadow)
	{
		ambient_comp(res, material, light);
		return ;
	}
	calculate_lighting_components(res, material, light, light_dot_normal);
	if (light_dot_normal >= 0)
	{
		calculate_specular(&specular, scene, lightv, comps);
		res->r += specular.r;
		res->g += specular.g;
		res->b += specular.b;
	}
}

#include "mini_rt.h"

t_rgb	*calculate_lighting_components(t_material material, t_light *light,
		double light_dot_normal)
{
	t_rgb	effective_color;
	t_rgb	*ambient;
	t_rgb	diffuse;
	t_rgb	*result;

	ambient = init_rgb(0, 0, 0);
	effective_color.r = material.rgb.r * light->rgb->r * light->intensity;
	effective_color.g = material.rgb.g * light->rgb->g * light->intensity;
	effective_color.b = material.rgb.b * light->rgb->b * light->intensity;
	ambient->r = effective_color.r * material.ambient;
	ambient->g = effective_color.g * material.ambient;
	ambient->b = effective_color.b * material.ambient;
	if (light_dot_normal < 0)
		return (ambient);
	diffuse.r = effective_color.r * material.diffuse * light_dot_normal;
	diffuse.g = effective_color.g * material.diffuse * light_dot_normal;
	diffuse.b = effective_color.b * material.diffuse * light_dot_normal;
	result = init_rgb(ambient->r + diffuse.r, ambient->g + diffuse.g, ambient->b
			+ diffuse.b);
	return (result);
}

t_rgb	calculate_specular(t_scene *scene, t_tuples *lightv, t_tuples *eyev,
		t_tuples *normalv)
{
	t_material	material;
	t_light		*light;
	double		reflect_dot_eye;
	double		factor;
	t_rgb		specular;

	material = scene->obj_list->head->data->sphere->material;
	light = scene->light_list->head;
	reflect_dot_eye = ftm_tup_dot(reflect(ftm_tup_negate(lightv), normalv),
			eyev);
	if (reflect_dot_eye <= 0)
		specular = *init_rgb(0, 0, 0);
	else
	{
		factor = pow(reflect_dot_eye, material.shininess);
		specular.r = light->rgb->r * light->intensity * material.specular
			* factor;
		specular.g = light->rgb->g * light->intensity * material.specular
			* factor;
		specular.b = light->rgb->b * light->intensity * material.specular
			* factor;
	}
	return (specular);
}

t_material	get_obj_mat(t_scene *scene)
{
	t_material mat;

	if(scene->obj_list->head->type == SPHERE)
	{
		mat = scene->obj_list->head->data->sphere->material;
		if(scene->obj_list->head->comp->inside)
			mat.ambient = 1.0;
	}
	else
		mat = get_material();
	return(mat);
}

t_rgb	*lighting(t_scene *scene, t_computations *comps, t_light *light)
{
	t_material	material;
	t_tuples	*lightv;
	double		light_dot_normal;
	t_rgb		*result;

	material = get_obj_mat(scene);
	lightv = ftm_tup_subtract(light->pos, comps->point);
	lightv = ftm_tup_norm(lightv);
	light_dot_normal = ftm_tup_dot(lightv, comps->normalv);
	result = calculate_lighting_components(material, light, light_dot_normal);
	if (light_dot_normal >= 0)
	{
		result->r += calculate_specular(scene, lightv, comps->eyev,
				comps->normalv).r;
		result->g += calculate_specular(scene, lightv, comps->eyev,
				comps->normalv).g;
		result->b += calculate_specular(scene, lightv, comps->eyev,
				comps->normalv).b;
	}
	free(lightv);
	return (result);
}



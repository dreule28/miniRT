#include "mini_rt.h"

t_rgb	*calculate_lighting_components(t_material material, t_light *light,
		double light_dot_normal)
{
	t_rgb	effective_color;
	t_rgb	*ambient;
	t_rgb	diffuse;
	t_rgb	*result;

	ambient = init_rgb(0, 0, 0);
	effective_color.r = material.rgb.r * light->rgb.r * light->intensity;
	effective_color.g = material.rgb.g * light->rgb.g * light->intensity;
	effective_color.b = material.rgb.b * light->rgb.b * light->intensity;
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

t_rgb	calculate_specular(t_material material, t_light *light, t_tuples *lightv,
		t_tuples *eyev, t_tuples *normalv)
{
	double		reflect_dot_eye;
	double		factor;
	t_rgb		specular;
	t_tuples	*reflect_vec;

	reflect_vec = reflect(ftm_tup_negate(lightv), normalv);
	reflect_dot_eye = ftm_tup_dot(reflect_vec, eyev);
	free(reflect_vec);

	if (reflect_dot_eye <= 0)
		specular = *init_rgb(0, 0, 0);
	else
	{
		factor = pow(reflect_dot_eye, material.shininess);
		specular.r = light->rgb.r * light->intensity * material.specular * factor;
		specular.g = light->rgb.g * light->intensity * material.specular * factor;
		specular.b = light->rgb.b * light->intensity * material.specular * factor;
	}
	return (specular);
}

// Helper function to get material from computations
t_material	get_material_from_computations(t_scene *scene, t_computations *comps)
{
	t_obj_node	*curr;

	// Search for the object that owns these computations
	curr = scene->obj_list->head;
	while (curr)
	{
		if (curr->comp == comps)
		{
			if (curr->type == SPHERE)
			{
				t_material mat = curr->data->sphere->material;
				if (comps->inside)
					mat.ambient = 1.0;
				return (mat);
			}
			else if (curr->type == PLANE)
				return (curr->data->plane->material);
			else if (curr->type == CYLINDER)
				return (curr->data->cylinder->material);
		}
		curr = curr->next;
	}
	return (get_material()); // fallback
}

t_rgb	*ambient_comp(t_tuples **lightv, t_material material, t_light *light)
{
	t_rgb	effective_color;
	t_rgb	*result;

	effective_color.r = material.rgb.r * light->rgb.r * light->intensity;
	effective_color.g = material.rgb.g * light->rgb.g * light->intensity;
	effective_color.b = material.rgb.b * light->rgb.b * light->intensity;
	result = init_rgb(effective_color.r * material.ambient,
			effective_color.g * material.ambient,
			effective_color.b * material.ambient);
	free((*lightv));
	return (result);
}

t_rgb	*lighting(t_scene *scene, t_computations *comps, t_light *light)
{
	t_material	material;
	t_tuples	*lightv;
	double		light_dot_normal;
	t_rgb		*result;
	t_rgb		specular;

	material = get_material_from_computations(scene, comps);
	lightv = ftm_tup_subtract(&light->pos, comps->over_point);
	lightv = ftm_tup_norm(lightv);
	light_dot_normal = ftm_tup_dot(lightv, comps->normalv);

	if (comps->in_shadow)
		return (ambient_comp(&lightv, material, light));

	result = calculate_lighting_components(material, light, light_dot_normal);

	if (light_dot_normal >= 0)
	{
		specular = calculate_specular(material, light, lightv, comps->eyev, comps->normalv);
		result->r += specular.r;
		result->g += specular.g;
		result->b += specular.b;
	}
	free(lightv);
	return (result);
}
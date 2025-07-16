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

t_light	*point_light(t_tuples *position, t_rgb *intensity)
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
	return (material);
}

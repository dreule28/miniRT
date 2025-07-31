#include "mini_rt.h"

double	snells_law(t_computations *comps)
{
	double	n_ratio;
	double	cos_i;

	if (!comps->eyev || !comps->normalv)
	{
		if (!comps->eyev)
			printf("womp womp eyev\n");
		if (!comps->normalv)
			printf("womp womp normalv\n");
		return (0.0);
	}
	n_ratio = comps->n1 / comps->n2;
	cos_i = ftm_tup_dot(comps->eyev, comps->normalv);
	return ((n_ratio * n_ratio) * (1 - cos_i *cos_i));
}

t_tuples	*find_direction(t_computations *comps, double sin2_t)
{
	double		cos_t;
	double		cos_i;
	double		n_ratio;
	t_tuples	*direction;

	cos_t = sqrt(1.0 - sin2_t);
	cos_i = ftm_tup_dot(comps->eyev, comps->normalv);
	n_ratio = comps->n1 / comps->n2;
	direction = ftm_tup_subtract(ftm_tup_mult(comps->over_point,
										(n_ratio * cos_i - cos_t)),
									ftm_tup_mult(comps->eyev, n_ratio));
	return (direction);
}

t_rgb	*refracted_color(t_obj_node *obj_node, t_obj_list *obj_list,
				t_scene *scene, int remaining)
{
	t_material	material;
	double		sin2_t;
	t_tuples	*direction;
	t_ray		*refract_ray;
	t_rgb		*color;

	if (remaining == 0)
		return (init_rgb(0, 0, 0));
	material = get_material_from_comps(obj_node->comp, obj_list);
	if (material.transparency == 0)
		return (init_rgb(0, 0, 0));
	sin2_t = snells_law(obj_node->comp);
	if (sin2_t > 1.0)
		return (init_rgb(0, 0, 0));
	direction = find_direction(obj_node->comp, sin2_t);
	refract_ray = init_ray(obj_node->comp->under_point, direction);
	(void)refract_ray;
	color = get_shaded_with_shadows(scene, obj_node, remaining - 1);
	color = ftm_rgb_mult(color, material.transparency);
	return (color);
}

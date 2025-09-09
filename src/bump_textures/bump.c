#include "mini_rt.h"

t_material	*mat_of(t_obj_node *n)
{
	if (!n || !n->data)
		return (NULL);
	if (n->type == SPHERE)
		return (&n->data->sphere->material);
	if (n->type == PLANE)
		return (&n->data->plane->material);
	if (n->type == CYLINDER)
		return (&n->data->cylinder->material);
	if (n->type == CUBE)
		return (&n->data->cube->material);
	if (n->type == CONE)
		return (&n->data->cone->material);
	return (NULL);
}

void	apply_bump_texture(t_obj_node *curr)
{
	t_material	*mat;
	double		k;

	mat = mat_of(curr);
	if (mat && mat->bump.has_bump)
	{
		t_tuples dv, dv_tan;
		bump_at_shape(&dv, mat->bump, *curr, curr->comp.point);
		k = ftm_tup_dot(curr->comp.normalv, dv);
		ftm_tup_mult(&dv_tan, curr->comp.normalv, k);
		ftm_tup_subtract(&dv, dv, dv_tan);
		ftm_tup_add(&curr->comp.normalv, curr->comp.normalv, dv);
		ftm_tup_norm(&curr->comp.normalv, curr->comp.normalv);
	}
}

void	select_bump(t_tuples *out, t_bump bump, t_tuples p)
{
	init_vector(out, 0, 0, 0);
	if (!bump.has_bump)
		return ;
	if (bump.type == SINE_BUMP)
		bump_sine(out, bump.amplitude, p);
	else if (bump.type == QUILT_BUMP)
		bump_quilt(out, bump.amplitude, p);
	else if (bump.type == CHECKERS_BUMP)
		bump_checkers(out, bump.amplitude, p);
	else if (bump.type == WAVE_BUMP)
		bump_wave(out, bump.amplitude, p);
}

void	bump_at_shape(t_tuples *out, t_bump bump, t_obj_node shape,
		t_tuples world_point)
{
	t_tuples	object_point;
	t_tuples	pattern_point;
	t_m4		inv_shape;
	t_m4		inv_pattern;

	init_vector(out, 0, 0, 0);
	if (!bump.has_bump)
		return ;
	ftm_m4_inversion(&inv_shape, shape.matrix);
	ftm_matrix_times_tuple(&object_point, inv_shape, world_point);
	ftm_m4_inversion(&inv_pattern, bump.transform);
	ftm_matrix_times_tuple(&pattern_point, inv_pattern, object_point);
	select_bump(out, bump, pattern_point);
}

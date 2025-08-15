#include "mini_rt.h"

t_rgb	*select_pattern(t_pattern *pattern, t_tuples *pattern_point)
{
	t_rgb	*pattern_color;

	if (pattern->type == STRIPE_PATTERN)
		pattern_color = stripe_at(pattern, pattern_point);
	else if (pattern->type == TEST_PATTERN)
		pattern_color = test_pattern_at(pattern, pattern_point);
	else if (pattern->type == GRADIENT_PATTERN)
		pattern_color = gradient_at(pattern, pattern_point);
	else if (pattern->type == RING_PATTERN)
		pattern_color = ring_at(pattern, pattern_point);
	else if (pattern->type == CHECKERS_PATTERN)
		pattern_color = checkers_at(pattern, pattern_point);
	else
		pattern_color = init_rgb(1, 1, 1);
	return (pattern_color);
}

t_rgb	*pattern_at_shape(t_pattern *pattern, t_obj_node *shape,
		t_tuples *world_point)
{
	t_tuples	*object_point;
	t_tuples	*pattern_point;
	t_m4		*inv_matrix;
	t_m4		*inv_pattern;
	t_rgb		*color;

	if (shape->matrix)
	{
		inv_matrix = ftm_m4_inversion(shape->matrix);
		object_point = ftm_matrix_times_tuple(inv_matrix, world_point);
		free_matrix_m4(inv_matrix);
	}
	else
		object_point = copy_point(world_point);
	if (pattern->transform)
	{
		inv_pattern = ftm_m4_inversion(pattern->transform);
		pattern_point = ftm_matrix_times_tuple(inv_pattern, object_point);
		free_matrix_m4(inv_pattern);
		free_tuple(object_point);
	}
	else
		pattern_point = object_point;
	color = select_pattern(pattern, pattern_point);
	return (color);
}

void	set_pattern_transform(t_pattern *pattern, t_m4 *transformation)
{
	if (pattern->transform)
		free_matrix_m4(pattern->transform);
	pattern->transform = transformation;
}

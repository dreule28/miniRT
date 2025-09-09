#include "mini_rt.h"

void	select_pattern(t_rgb *pattern_color, t_pattern pattern,
			t_tuples pattern_point)
{
	if (pattern.type == STRIPE_PATTERN)
		stripe_at(pattern_color, pattern, pattern_point);
	else if (pattern.type == GRADIENT_PATTERN)
		gradient_at(pattern_color, pattern, pattern_point);
	else if (pattern.type == RING_PATTERN)
		ring_at(pattern_color, pattern, pattern_point);
	else if (pattern.type == CHECKERS_PATTERN)
		checkers_at(pattern_color, pattern, pattern_point);
	else
		init_rgb(pattern_color, 1, 1, 1);
}

void	pattern_at_shape(t_rgb *rgb, t_pattern pattern, t_obj_node shape,
		t_tuples world_point)
{
	t_tuples	object_point;
	t_tuples	pattern_point;
	t_m4		inv_shape;
	t_m4		inv_pattern;

	ftm_m4_inversion(&inv_shape, shape.matrix);
	ftm_matrix_times_tuple(&object_point, inv_shape, world_point);
	ftm_m4_inversion(&inv_pattern, pattern.transform);
	ftm_matrix_times_tuple(&pattern_point, inv_pattern, object_point);
	select_pattern(rgb, pattern, pattern_point);
}

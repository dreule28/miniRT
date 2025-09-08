#include "mini_rt.h"

void	sine_at(t_tuples *out, t_bump *bump, t_tuples *bump_point)
{
	double	freq;

	freq = 10.0;
	return (init_vector(out, 0.0, bump->amplitude * sin(freq * bump_point->x),
			0.0));
}

void	select_bump(t_tuples *out, t_bump bump, t_tuples bump_point)
{
	init_vector(out, 0, 0, 0);
	if (bump.type == SINE_BUMP)
		sine_at(out, &bump, &bump_point);
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

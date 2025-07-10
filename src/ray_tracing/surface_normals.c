#include "mini_rt.h"

t_tuples	*normal_at(t_sphere *sphere, t_tuples *point)
{
	t_tuples	*raw;
	t_tuples	*normal;

	raw = ftm_tup_subtract(&sphere->pos, point);
	if (!raw)
		return (NULL);
	normal = ftm_tup_norm(raw);
	if (!normal)
		return (NULL);
	free(raw);
	return (normal);
}

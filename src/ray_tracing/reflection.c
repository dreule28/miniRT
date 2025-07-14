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

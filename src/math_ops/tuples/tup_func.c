#include "mini_rt.h"

double	ftm_tup_dot(t_tuples *vec1, t_tuples *vec2)
{
	double	dot;

	dot = 0;
	dot += vec1->w * vec2->w;
	dot += vec1->x * vec2->x;
	dot += vec1->y * vec2->y;
	dot += vec1->z * vec2->z;
	return (dot);
}

t_tuples	*ftm_tup_cross(t_tuples *tup1, t_tuples *tup2)
{
	t_tuples	*new_tuples;

	new_tuples = ft_calloc(1, sizeof(t_tuples));
	if (!new_tuples)
		return (NULL);
	new_tuples->x = tup1->y * tup2->z - tup1->z * tup2->y;
	new_tuples->y = tup1->z * tup2->x - tup1->x * tup2->z;
	new_tuples->z = tup1->x * tup2->y - tup1->y * tup2->x;
	new_tuples->w = VECTOR;
	return (new_tuples);
}

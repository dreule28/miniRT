#include "mini_rt.h"

bool	tupcmp(t_tuples *tuples1, t_tuples *tuples2)
{
	if (tuples1->w != tuples2->w)
		return (true);
	else if (fabs(tuples1->x - tuples2->x) > DBL_EPSILON)
		return (true);
	else if (fabs(tuples1->y - tuples2->y) > DBL_EPSILON)
		return (true);
	else if (fabs(tuples1->z - tuples2->z) > DBL_EPSILON)
		return (true);
	return (false);
}

t_tuples	*tup_add(t_tuples *tuples1, t_tuples *tuples2)
{
	t_tuples	*new_tuples;

	new_tuples = ft_calloc(1, sizeof(t_tuples));
	if (!new_tuples)
		return (NULL);
	new_tuples->x = tuples1->x + tuples2->x;
	new_tuples->y = tuples1->y + tuples2->y;
	new_tuples->z = tuples1->z + tuples2->z;
	new_tuples->w = tuples1->w + tuples2->w;
	return (new_tuples);
}

t_tuples	*tup_subtract(t_tuples *tuples1, t_tuples *tuples2)
{
	t_tuples	*new_tuples;

	new_tuples = ft_calloc(1, sizeof(t_tuples));
	if (!new_tuples)
		return (NULL);
	new_tuples->x = tuples1->x - tuples2->x;
	new_tuples->y = tuples1->y - tuples2->y;
	new_tuples->z = tuples1->z - tuples2->z;
	new_tuples->w = tuples1->w - tuples2->w;
	return (new_tuples);
}


t_tuples	*tup_negate(t_tuples *tuples)
{
	t_tuples	*new_tuples;

	new_tuples = ft_calloc(1, sizeof(t_tuples));
	if (!new_tuples)
		return (NULL);
	new_tuples->x = -tuples->x;
	new_tuples->y = -tuples->y;
	new_tuples->z = -tuples->z;
	new_tuples->w = -tuples->w;
	return (new_tuples);
}

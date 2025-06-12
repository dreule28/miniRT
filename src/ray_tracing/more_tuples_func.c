#include "mini_rt.h"

t_tuples	*tup_mult(t_tuples *tuples, double multiplier)
{
	t_tuples *new_tuples;

	new_tuples = ft_calloc(1, sizeof(t_tuples));
	if(!new_tuples)
		return(NULL);
	new_tuples->x = tuples->x * multiplier; 
	new_tuples->y = tuples->y * multiplier;
	new_tuples->z = tuples->z * multiplier;
	new_tuples->w = tuples->w * multiplier;
	return(new_tuples);
}

t_tuples	*tup_divied(t_tuples *tuples, double divider)
{
	t_tuples *new_tuples;

	new_tuples = ft_calloc(1, sizeof(t_tuples));
	if(!new_tuples)
		return(NULL);
	new_tuples->x = tuples->x / divider; 
	new_tuples->y = tuples->y / divider;
	new_tuples->z = tuples->z / divider;
	new_tuples->w = tuples->w / divider;
	return(new_tuples);
}

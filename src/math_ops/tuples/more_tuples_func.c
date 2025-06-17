#include "mini_rt.h"

/**
 * tup_mult - Multiplies a tuple by a value.
 * @tuples: Pointer to the tuple to be multiplied.
 * @value: The value to multiply the tuple by.
 *
 * Return: A new tuple with each component multiplied by the value.
 *         Returns NULL if memory allocation fails.
 */
t_tuples	*tup_mult(t_tuples *tuples, double value)
{
	t_tuples	*new_tuples;

	new_tuples = ft_calloc(1, sizeof(t_tuples));
	if (!new_tuples)
		return (NULL);
	new_tuples->x = tuples->x * value;
	new_tuples->y = tuples->y * value;
	new_tuples->z = tuples->z * value;
	new_tuples->w = tuples->w * value;
	return (new_tuples);
}

/**
 * tup_divied - Divides a tuple by a value.
 * @tuples: Pointer to the tuple to be divided.
 * @value: The value to divide the tuple by.
 *
 * Return: A new tuple with each component divided by the value .
 *         Returns NULL if memory allocation fails or if value is zero.
 */
t_tuples	*tup_divied(t_tuples *tuples, double value)
{
	t_tuples	*new_tuples;

	if (value == 0)
		return (NULL);
	new_tuples = ft_calloc(1, sizeof(t_tuples));
	if (!new_tuples)
		return (NULL);
	new_tuples->x = tuples->x / value;
	new_tuples->y = tuples->y / value;
	new_tuples->z = tuples->z / value;
	new_tuples->w = tuples->w / value;
	return (new_tuples);
}

double	magnitude_vector(t_tuples *vector)
{
	double sum;
	double magnitude;

	sum = 0;
	sum += vector->x * vector->x;
	sum += vector->y * vector->y;
	sum += vector->z * vector->z;
	magnitude = sqrt(sum);
	return(magnitude);
}

t_tuples	*tup_norm(t_tuples *vector)
{
	t_tuples *new_vector;

	new_vector = ft_calloc(1, sizeof(t_tuples));
	if(!new_vector)
		return(NULL);
	new_vector->w = vector->w / magnitude_vector(vector);
	new_vector->x = vector->x / magnitude_vector(vector);
	new_vector->y = vector->y / magnitude_vector(vector);
	new_vector->z = vector->z / magnitude_vector(vector);
	return(new_vector);
}

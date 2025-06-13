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

void	test_tuples_operations(void)
{
	t_tuples	*vec1;
	t_tuples	*vec2;
	t_tuples	*point1;
	t_tuples	*add_result;
	t_tuples	*sub_result;
	t_tuples	*point_add;
	t_tuples	*neg_result;
	t_tuples	*mult_result;
	t_tuples	*div_result;

	// Test vector and point creation
	vec1 = create_vector(1.0, 2.0, 3.0);
	vec2 = create_vector(2.0, 3.0, 4.0);
	point1 = create_point(1.0, 1.0, 1.0);
	printf("\n=== Test Vector Creation ===\n");
	printf("Vector 1: (%.1f, %.1f, %.1f, %d)\n", vec1->x, vec1->y, vec1->z,
		vec1->w);
	printf("Vector 2: (%.1f, %.1f, %.1f, %d)\n", vec2->x, vec2->y, vec2->z,
		vec2->w);
	printf("Point 1: (%.1f, %.1f, %.1f, %d)\n", point1->x, point1->y, point1->z,
		point1->w);
	// Test vector addition
	add_result = tup_add(vec1, vec2);
	printf("\n=== Test Vector Addition ===\n");
	printf("Vec1 + Vec2: (%.1f, %.1f, %.1f, %d)\n", add_result->x,
		add_result->y, add_result->z, add_result->w);
	// Test vector subtraction
	sub_result = tup_subtract(vec1, vec2);
	printf("\n=== Test Vector Subtraction ===\n");
	printf("Vec1 - Vec2: (%.1f, %.1f, %.1f, %d)\n", sub_result->x,
		sub_result->y, sub_result->z, sub_result->w);
	// Test point-vector operations
	point_add = tup_add(point1, vec1);
	printf("\n=== Test Point-Vector Addition ===\n");
	printf("Point + Vector: (%.1f, %.1f, %.1f, %d)\n", point_add->x,
		point_add->y, point_add->z, point_add->w);
	// Test negation
	neg_result = tup_negate(vec1);
	printf("\n=== Test Vector Negation ===\n");
	printf("Original: (%.1f, %.1f, %.1f, %d)\n", vec1->x, vec1->y, vec1->z,
		vec1->w);
	printf("Negated:  (%.1f, %.1f, %.1f, %d)\n", neg_result->x, neg_result->y,
		neg_result->z, neg_result->w);
	// Test scalar multiplication
	mult_result = tup_mult(vec1, 2.0);
	printf("\n=== Test Scalar Multiplication ===\n");
	printf("Vec1 * 2.0: (%.1f, %.1f, %.1f, %d)\n", mult_result->x,
		mult_result->y, mult_result->z, mult_result->w);
	// Test division
	div_result = tup_divied(vec1, 2.0);
	printf("\n=== Test Scalar Division ===\n");
	printf("Vec1 / 2.0: (%.1f, %.1f, %.1f, %d)\n", div_result->x, div_result->y,
		div_result->z, div_result->w);
	// Test comparison
	printf("\n=== Test Tuple Comparison ===\n");
	printf("Vec1 == Vec2: %s\n", tupcmp(vec1, vec2) ? "different" : "same");
	printf("Vec1 == Vec1: %s\n", tupcmp(vec1, vec1) ? "different" : "same");
	// Cleanup
	free(vec1);
	free(vec2);
	free(point1);
	free(add_result);
	free(sub_result);
	free(point_add);
	free(neg_result);
	free(mult_result);
	free(div_result);
}

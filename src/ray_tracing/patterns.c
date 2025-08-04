#include "mini_rt.h"

t_pattern	*stripe_pattern(t_rgb *color1, t_rgb *color2)
{
	t_pattern	*new_pattern;

	new_pattern = ft_calloc(sizeof(t_pattern), 1);
	new_pattern->color1 = color1;
	new_pattern->color2 = color2;
	new_pattern->transform = NULL;
    new_pattern->type = STRIPE_PATTERN;
	return (new_pattern);
}

t_rgb	*stripe_at(t_pattern *pattern, t_tuples *point)
{
	double floor_x;

	floor_x = floor(point->x);
	if (fmod(floor_x, 2) == 0)
		return (pattern->color1);
	else
		return (pattern->color2);
}

t_rgb	*stripe_at_object(t_pattern *pattern, t_m4 *matrix, t_tuples *world_point)
{
	t_tuples	*object_point;
    t_tuples	*pattern_point;
    t_m4		*inv_matrix;
    t_m4		*inv_pattern;
    t_rgb       *color;

    if (matrix)
    {
        inv_matrix = ftm_m4_inversion(matrix);
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
	return(color);
}

void    set_pattern_transform(t_pattern *pattern, t_m4 *transformation)
{
    if (pattern->transform)
        free_matrix_m4(pattern->transform);
    pattern->transform = transformation;
}

t_pattern *test_pattern(void)
{
    t_pattern *new_pattern;

    new_pattern = ft_calloc(sizeof(t_pattern), 1);
    if (!new_pattern)
        return (NULL);
    new_pattern->color1 = NULL;
    new_pattern->color2 = NULL;
    new_pattern->transform = NULL;
    new_pattern->type = TEST_PATTERN;
    return(new_pattern);
}

#include "mini_rt.h"

t_rgb *select_pattern(t_pattern *pattern, t_tuples *pattern_point)
{
    t_rgb   *pattern_color;

    if(pattern->type == STRIPE_PATTERN)
        pattern_color = stripe_at(pattern, pattern_point);
    else if (pattern->type == TEST_PATTERN)
        pattern_color = test_pattern_at(pattern, pattern_point);
    else if (pattern->type == GRADIENT_PATTERN)
        pattern_color = gradient_at(pattern, pattern_point);
    else if (pattern->type == RING_PATTERN)
        pattern_color = ring_at(pattern, pattern_point);
    else if (pattern->type == CHECKERS_PATTERN) 
        pattern_color = checkers_at(pattern, pattern_point);
    else
        pattern_color = init_rgb(1, 1, 1);
    return(pattern_color);
}

t_rgb *test_pattern_at(t_pattern *pattern, t_tuples *point)
{
    (void)pattern;
    return(init_rgb(point->x,point->y,point->z));
}

t_rgb *pattern_at_shape(t_pattern *pattern, t_obj_node *shape, t_tuples *world_point)
{
	t_tuples	*object_point;
    t_tuples	*pattern_point;
    t_m4		*inv_matrix;
    t_m4		*inv_pattern;
    t_rgb       *color;

    if (shape->matrix)
    {
        inv_matrix = ftm_m4_inversion(shape->matrix);
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

t_pattern   *gradient_pattern(t_rgb *color1, t_rgb *color2)
{
    t_pattern *new_pattern;

    new_pattern = ft_calloc(sizeof(t_pattern), 1);
    if(!new_pattern)
        return(NULL);
    new_pattern->color1 = color1;
    new_pattern->color2 = color2;
    new_pattern->transform = NULL;
    new_pattern->type = GRADIENT_PATTERN;
    return(new_pattern);
}

t_rgb   *gradient_at(t_pattern *pattern, t_tuples *point)
{
    t_rgb *distance;
    t_rgb *result;
    double fraction;

    distance = init_rgb(pattern->color2->r - pattern->color1->r,
                        pattern->color2->g - pattern->color1->g,
                        pattern->color2->b - pattern->color1->b);
    fraction = point->x - floor(point->x);
    result = init_rgb(
        pattern->color1->r + distance->r * fraction,
        pattern->color1->g + distance->g * fraction,
        pattern->color1->b + distance->b * fraction);
    return (result);
}

t_pattern *ring_pattern(t_rgb *color1, t_rgb *color2)
{
    t_pattern *new_pattern;

    new_pattern = ft_calloc(sizeof(t_pattern), 1);
    if(!new_pattern)
        return(NULL);
    new_pattern->color1 = color1;
    new_pattern->color2 = color2;
    new_pattern->transform = NULL;
    new_pattern->type = RING_PATTERN;
    return(new_pattern);
}

t_rgb   *ring_at(t_pattern *pattern, t_tuples *point)
{
    double distance;
    int ring_number;

    distance = sqrt(point->x * point->x + point->z * point->z);
    ring_number = (int)floor(distance);
    if(ring_number % 2 == 0)
        return(pattern->color1);
    else
        return(pattern->color2);
}

t_pattern   *checkers_pattern(t_rgb *color1, t_rgb *color2)
{
        t_pattern *new_pattern;

    new_pattern = ft_calloc(sizeof(t_pattern), 1);
    if(!new_pattern)
        return(NULL);
    new_pattern->color1 = color1;
    new_pattern->color2 = color2;
    new_pattern->transform = NULL;
    new_pattern->type = CHECKERS_PATTERN;
    return(new_pattern);
}

t_rgb *checkers_at(t_pattern *pattern, t_tuples *point)
{
    
}
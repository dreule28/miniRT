// #include "mini_rt.h"

// t_pattern	*test_pattern(void)
// {
// 	t_pattern	*new_pattern;

// 	new_pattern = ft_calloc(sizeof(t_pattern), 1);
// 	if (!new_pattern)
// 		return (NULL);
// 	new_pattern->color1 = NULL;
// 	new_pattern->color2 = NULL;
// 	new_pattern->transform = NULL;
// 	new_pattern->type = TEST_PATTERN;
// 	return (new_pattern);
// }

// t_pattern	*checkers_pattern(t_rgb *color1, t_rgb *color2)
// {
// 	t_pattern	*new_pattern;

// 	new_pattern = ft_calloc(sizeof(t_pattern), 1);
// 	if (!new_pattern)
// 		return (NULL);
// 	new_pattern->color1 = color1;
// 	new_pattern->color2 = color2;
// 	new_pattern->transform = NULL;
// 	new_pattern->type = CHECKERS_PATTERN;
// 	return (new_pattern);
// }

// t_pattern	*ring_pattern(t_rgb *color1, t_rgb *color2)
// {
// 	t_pattern	*new_pattern;

// 	new_pattern = ft_calloc(sizeof(t_pattern), 1);
// 	if (!new_pattern)
// 		return (NULL);
// 	new_pattern->color1 = color1;
// 	new_pattern->color2 = color2;
// 	new_pattern->transform = NULL;
// 	new_pattern->type = RING_PATTERN;
// 	return (new_pattern);
// }

// t_pattern	*gradient_pattern(t_rgb *color1, t_rgb *color2)
// {
// 	t_pattern	*new_pattern;

// 	new_pattern = ft_calloc(sizeof(t_pattern), 1);
// 	if (!new_pattern)
// 		return (NULL);
// 	new_pattern->color1 = color1;
// 	new_pattern->color2 = color2;
// 	new_pattern->transform = NULL;
// 	new_pattern->type = GRADIENT_PATTERN;
// 	return (new_pattern);
// }

// t_pattern	*stripe_pattern(t_rgb *color1, t_rgb *color2)
// {
// 	t_pattern	*new_pattern;

// 	new_pattern = ft_calloc(sizeof(t_pattern), 1);
// 	new_pattern->color1 = color1;
// 	new_pattern->color2 = color2;
// 	new_pattern->transform = NULL;
// 	new_pattern->type = STRIPE_PATTERN;
// 	return (new_pattern);
// }

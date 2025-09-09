/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:59:20 by dreule            #+#    #+#             */
/*   Updated: 2025/09/09 14:59:21 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	stripe_at(t_rgb *color, t_pattern pattern, t_tuples point)
{
	double	floor_x;

	floor_x = floor(point.x);
	if (fmod(floor_x, 2) == 0)
	{
		color->r = pattern.color1.r;
		color->g = pattern.color1.g;
		color->b = pattern.color1.b;
		return ;
	}
	else
	{
		color->r = pattern.color2.r;
		color->g = pattern.color2.g;
		color->b = pattern.color2.b;
		return ;
	}
}

void	gradient_at(t_rgb *result, t_pattern pattern, t_tuples point)
{
	t_rgb	distance;
	double	fraction;

	init_rgb(&distance, pattern.color2.r - pattern.color1.r,
		pattern.color2.g - pattern.color1.g, pattern.color2.b
		- pattern.color1.b);
	fraction = point.x - floor(point.x);
	init_rgb(result, pattern.color1.r + distance.r * fraction,
		pattern.color1.g + distance.g * fraction, pattern.color1.b
		+ distance.b * fraction);
}

void	ring_at(t_rgb *color, t_pattern pattern, t_tuples point)
{
	double	distance;
	int		ring_number;

	distance = sqrt(point.x * point.x + point.z * point.z);
	ring_number = (int)floor(distance);
	if (ring_number % 2 == 0)
	{
		color->r = pattern.color1.r;
		color->g = pattern.color1.g;
		color->b = pattern.color1.b;
		return ;
	}
	else
	{
		color->r = pattern.color2.r;
		color->g = pattern.color2.g;
		color->b = pattern.color2.b;
		return ;
	}
}

void	checkers_at(t_rgb *color, t_pattern pattern, t_tuples point)
{
	int	sum;

	sum = (int)floor(point.x) + (int)floor(point.y) + (int)floor(point.z);
	if (sum % 2 == 0)
	{
		color->r = pattern.color1.r;
		color->g = pattern.color1.g;
		color->b = pattern.color1.b;
		return ;
	}
	else
	{
		color->r = pattern.color2.r;
		color->g = pattern.color2.g;
		color->b = pattern.color2.b;
		return ;
	}
}

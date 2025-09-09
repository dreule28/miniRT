/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_math_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:58:38 by dreule            #+#    #+#             */
/*   Updated: 2025/09/09 14:58:39 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	init_vector(t_tuples *vector, double x, double y, double z)
{
	vector->x = x;
	vector->y = y;
	vector->z = z;
	vector->w = VECTOR;
}

void	init_point(t_tuples *point, double x, double y, double z)
{
	point->x = x;
	point->y = y;
	point->z = z;
	point->w = POINT;
}

void	copy_vector(t_tuples *new, t_tuples old)
{
	new->x = old.x;
	new->y = old.y;
	new->z = old.z;
	new->w = VECTOR;
}

void	copy_point(t_tuples *new, t_tuples old)
{
	new->x = old.x;
	new->y = old.y;
	new->z = old.z;
	new->w = POINT;
}

void	init_rgb(t_rgb *rgb, double r, double g, double b)
{
	rgb->r = r;
	rgb->g = g;
	rgb->b = b;
}

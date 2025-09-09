/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_math.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:03:24 by dreule            #+#    #+#             */
/*   Updated: 2025/09/09 15:03:25 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_MATH_H
# define CUSTOM_MATH_H

# include <stdbool.h>

typedef enum e_tuples_enum
{
	VECTOR,
	POINT
}					t_tuples_enum;

typedef struct s_tuples
{
	double	x;
	double	y;
	double	z;
	double	w;
}			t_tuples;

typedef struct s_rgb
{
	double	r;
	double	g;
	double	b;
}			t_rgb;

// ray_tracing/custom_math_func.c
void	init_vector(t_tuples *vector, double x, double y, double z);
void	init_point(t_tuples *point, double x, double y, double z);
void	copy_vector(t_tuples *new, t_tuples old);
void	copy_point(t_tuples *new, t_tuples old);
void	init_rgb(t_rgb *rgb, double r, double g, double b);

// ray_tracing/tulpes_func.c
/* Compares two tuples for equality with floating-point precision */
bool	ftm_tup_cmp(t_tuples tuples1, t_tuples tuples2);

/* Adds two tuples component-wise */
void	ftm_tup_add(t_tuples *new_tup, t_tuples tup1, t_tuples tup2);

/* Subtracts second tuple from first tuple component-wise */
void	ftm_tup_subtract(t_tuples *new_tup, t_tuples tup1, t_tuples tup2);

/* Negates all components of a tuple */
void	ftm_tup_negate(t_tuples *new_tuples);

// ray_tracing/more_tuples_function.c
/* Multiplies tuple by scalar value */
void	ftm_tup_mult(t_tuples *new_tuples, t_tuples in, double value);

void	ftm_rgb_mult(t_rgb *new_rgb, t_rgb in, double value);

/* Divides tuple by scalar value */
void	ftm_tup_divied(t_tuples *new_tup, t_tuples *tuples, double value);

/* Calculates magnitude (length) of a vector */
double	magnitude_vector(t_tuples vector);

/* Normalizes a vector to unit length */
void	ftm_tup_norm(t_tuples *new_vector, t_tuples in);

/* Calculates cross product of two vectors */
void	ftm_tup_cross(t_tuples *new_tuples, t_tuples tup1, t_tuples tup2);

// tup_func.c
double	ftm_tup_dot(t_tuples vec1, t_tuples vec2);

#endif
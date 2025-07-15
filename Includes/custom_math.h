#ifndef CUSTOM_MATH_H
# define CUSTOM_MATH_H

# include <stdbool.h>

/* Enum to distinguish between vectors and points in 3D space */
typedef enum e_tuples_enum
{
	VECTOR,		/* Represents direction and magnitude (w = 0) */
	POINT
}					t_tuples_enum;

typedef struct s_tuples
{
	double	x;		/* X component */
	double	y;		/* Y component */
	double	z;		/* Z component */
	double	w;		/* W component (0 for vectors, 1 for points) */
}					t_tuples;

/* RGB color structure with double precision for color calculations */
typedef struct s_rgb
{
	double	r;		/* Red component (0.0 - 1.0) */
	double	g;		/* Green component (0.0 - 1.0) */
	double	b;		/* Blue component (0.0 - 1.0) */
}			t_rgb;

// ray_tracing/custom_math_func.c
t_tuples			*init_vector(double x, double y, double z);
t_tuples			*init_point(double x, double y, double z);
t_tuples			*copy_vector(t_tuples *tup);
t_tuples			*copy_point(t_tuples *tup);
t_rgb				*init_rgb(double r, double g, double b);

// ray_tracing/tulpes_func.c
/* Compares two tuples for equality with floating-point precision */
bool				ftm_tup_cmp(t_tuples *tuples1, t_tuples *tuples2);

/* Adds two tuples component-wise */
t_tuples			*ftm_tup_add(t_tuples *tuples1, t_tuples *tuples2);

/* Subtracts second tuple from first tuple component-wise */
t_tuples			*ftm_tup_subtract(t_tuples *tuples1, t_tuples *tuples2);

/* Negates all components of a tuple */
t_tuples			*ftm_tup_negate(t_tuples *tuples);

// ray_tracing/more_tuples_function.c
/* Multiplies tuple by scalar value */
t_tuples			*ftm_tup_mult(t_tuples *tuples, double multiplier);

t_rgb				*ftm_rgb_mult(t_rgb *rgb, double value);

/* Divides tuple by scalar value */
t_tuples			*ftm_tup_divied(t_tuples *tuples, double divider);

/* Calculates magnitude (length) of a vector */
double				magnitude_vector(t_tuples *vector);

/* Normalizes a vector to unit length */
t_tuples			*ftm_tup_norm(t_tuples *vector);

/* Calculates cross product of two vectors */
t_tuples			*ftm_tup_cross(t_tuples *tup1, t_tuples *tup2);

// tup_func.c
double				ftm_tup_dot(t_tuples *vec1, t_tuples *vec2);

#endif
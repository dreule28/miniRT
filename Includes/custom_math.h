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
}					t_tuples;

typedef struct s_rgb
{
	double	r;
	double	g;
	double	b;
}			t_rgb;

// ray_tracing/custom_math_func.c
t_tuples			*init_vector(double x, double y, double z);
t_tuples			*init_point(double x, double y, double z);
t_tuples			*copy_vector(t_tuples *tup);
t_tuples			*copy_point(t_tuples *tup);
t_rgb				*init_rgb(double r, double g, double b);

// ray_tracing/tulpes_func.c
bool				ftm_tup_cmp(t_tuples *tuples1, t_tuples *tuples2);
t_tuples			*ftm_tup_add(t_tuples *tuples1, t_tuples *tuples2);
t_tuples			*ftm_tup_subtract(t_tuples *tuples1, t_tuples *tuples2);
t_tuples			*ftm_tup_negate(t_tuples *tuples);

// ray_tracing/more_tuples_function.c
t_tuples			*ftm_tup_mult(t_tuples *tuples, double multiplier);
t_tuples			*ftm_tup_divied(t_tuples *tuples, double divider);
double				magnitude_vector(t_tuples *vector);
t_tuples			*ftm_tup_norm(t_tuples *vector);
t_tuples			*ftm_tup_cross(t_tuples *tup1, t_tuples *tup2);

// tup_func.c
double				ftm_tup_dot(t_tuples *vec1, t_tuples *vec2);

#endif
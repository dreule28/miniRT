#ifndef MATH_H
# define MATH_H

# include <stdbool.h>

typedef enum e_tuples_enum
{
	VECTOR,
	POINT
}					t_tuples_enum;

typedef struct s_tuples
{
	double			x;
	double			y;
	double			z;
	t_tuples_enum	w;
}					t_tuples;

typedef struct s_rgb
{
	double			r;
	double			g;
	double			b;
}					t_rgb;

// ray_tracing/custom_math_func.c
t_tuples			*create_vector(double x, double y, double z);
t_tuples			*create_point(double x, double y, double z);
t_rgb				*create_rgb(double r, double g, double b);

// ray_tracing/tulpes_func.c
bool		tupcmp(t_tuples *tuples1, t_tuples *tuples2);
t_tuples	*tup_add(t_tuples *tuples1, t_tuples *tuples2);
t_tuples	*tup_subtract(t_tuples *tuples1, t_tuples *tuples2);
t_tuples	*tup_negate(t_tuples *tuples);

// ray_tracing/more_tuples_function.c
t_tuples	*tup_mult(t_tuples *tuples, double multiplier);


#endif
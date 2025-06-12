#ifndef MATH_H
# define MATH_H

# include <stdbool.h>

typedef enum e_tuples_enum
{
	VECTOR,
	POINT
}	t_tuples_enum;

typedef struct s_tuples
{
	double	x;
	double	y;
	double	z;
	t_tuples_enum w;
}			t_tuples;

typedef struct s_rgb
{
	double	r;
	double	g;
	double	b;
}			t_rgb;

#endif
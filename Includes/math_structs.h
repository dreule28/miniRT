#ifndef MATH_STRUCTS_H
# define MATH_STRUCTS_H

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
	bool	w;
}			t_vector;

typedef struct s_rgb
{
	double	r;
	double	g;
	double	b;
}			t_rgb;

#endif
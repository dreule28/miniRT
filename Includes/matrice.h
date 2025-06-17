#ifndef MATRICES_H
# define MATRICES_H

typedef struct s_m4_row
{
	double			x;
	double			y;
	double			z;
	double			w;
	struct s_m4_row		*next;
}					t_m4_row;

typedef struct s_m3_row
{
	double			x;
	double			y;
	double			z;
	struct s_m3_row		*next;
}					t_m3_row;

typedef struct s_m2_row
{
	double			x;
	double			y;
	struct s_m2_row	*next;
}					t_m2_row;

typedef struct s_m2
{
	t_m2_row		*row1;
	t_m2_row		*row2;
}					t_m2;

typedef struct s_m3
{
	t_m3_row		*row1;
	t_m3_row		*row2;
	t_m3_row		*row3;
}					t_m3;

typedef struct s_m4
{
	t_m4_row		*row1;
	t_m4_row		*row2;
	t_m4_row		*row3;
	t_m4_row		*row4;
}					t_m4;


// src/math_ops/init_matices.c
t_m4	*init_m4(void);
t_m3	*init_m3(void);
t_m2	*init_m2(void);

#endif
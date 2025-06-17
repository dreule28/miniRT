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

// src/math_ops/create_matrices_rows.c
t_m4_row	*create_m4_row(double x, double y, double z, double w);
t_m3_row	*create_m3_row(double x, double y, double z);
t_m2_row	*create_m2_row(double x, double y);

// src/math_ops/add_matrices.c
bool	add_row_m4(t_m4 *m4, t_m4_row *new_row);
bool	add_row_m3(t_m3 *m3, t_m3_row *new_row);
bool	add_row_m2(t_m2 *m2, t_m2_row *new_row);

// src/math_ops/matrice_func.c

#endif
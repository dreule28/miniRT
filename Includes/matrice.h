#ifndef MATRICES_H
# define MATRICES_H

typedef struct s_m4_col
{
	double			x;
	double			y;
	double			z;
	double			w;
	struct s_m4_col		*next;
}					t_m4_col;

typedef struct s_m3_col
{
	double			x;
	double			y;
	double			z;
	struct s_m3_col		*next;
}					t_m3_col;

typedef struct s_m2_col
{
	double			x;
	double			y;
	struct s_m2_col	*next;
}					t_m2_col;

typedef struct s_m2
{
	t_m2_col		*col1;
	t_m2_col		*col2;
}					t_m2;

typedef struct s_m3
{
	t_m3_col		*col1;
	t_m3_col		*col2;
	t_m3_col		*col3;
}					t_m3;

typedef struct s_m4
{
	t_m4_col		*col1;
	t_m4_col		*col2;
	t_m4_col		*col3;
	t_m4_col		*col4;
}					t_m4;


// src/math_ops/init_matices.c
t_m4	*init_m4(void);
t_m3	*init_m3(void);
t_m2	*init_m2(void);

// src/math_ops/create_matrices_cols.c
t_m4_col	*create_m4_col(double x, double y, double z, double w);
t_m3_col	*create_m3_col(double x, double y, double z);
t_m2_col	*create_m2_col(double x, double y);

// src/math_ops/add_matrices.c
bool	add_col_m4(t_m4 *m4, t_m4_col *new_col);
bool	add_col_m3(t_m3 *m3, t_m3_col *new_col);
bool	add_col_m2(t_m2 *m2, t_m2_col *new_col);

// src/math_ops/m_cmp.c
bool	m_cmp(void *matrice1, void *matrice2, int size);
bool	m4_cmp(t_m4 *matrice1, t_m4 *matrice2);
bool	m3_cmp(t_m3 *matrice1, t_m3 *matrice2);
bool	m2_cmp(t_m2 *matrice1, t_m2 *matrice2);

// src/math_ops/matrices.c


#endif
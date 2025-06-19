#ifndef MATRICES_H
# define MATRICES_H

#include <sys/types.h>

typedef struct s_m2_col
{
	double			x;
	double			y;
	struct s_m2_col	*next;
}					t_m2_col;

typedef struct s_m3_col
{
	double			x;
	double			y;
	double			z;
	struct s_m3_col	*next;
}					t_m3_col;

typedef struct s_m4_col
{
	double			x;
	double			y;
	double			z;
	double			w;
	struct s_m4_col	*next;
}					t_m4_col;

typedef struct s_m2
{
	t_m2_col	*head;
	t_m2_col	*tail;
	ssize_t		size;
}				t_m2;

typedef struct s_m3
{
	t_m3_col	*head;
	t_m3_col	*tail;
	ssize_t		size;
}				t_m3;

typedef struct s_m4
{
	t_m4_col	*head;
	t_m4_col	*tail;
	ssize_t		size;
}				t_m4;

//add_col.c -- BEGIN
t_m2_col	*add_m2_col(t_m2 *m2, double x, double y);
t_m3_col	*add_m3_col(t_m3 *m3, double x, double y, double z);
t_m4_col	*add_m4_col(double x, double y, double z, double w);
void		append_col(t_m4 *m4, t_m4_col *new_col);
//add_col.c -- END


//init_matrices.c -- BEGIN
t_m4	*init_m4(void);
t_m3	*init_m3(void);
t_m2	*init_m2(void);
//init_matrices.c -- END


// src/math_ops/m_cmp.c
bool	m_cmp(void *matrice1, void *matrice2, int size);
bool	m4_cmp(t_m4 *matrice1, t_m4 *matrice2);
bool	m3_cmp(t_m3 *matrice1, t_m3 *matrice2);
bool	m2_cmp(t_m2 *matrice1, t_m2 *matrice2);

#endif
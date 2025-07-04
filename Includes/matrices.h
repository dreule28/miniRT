#ifndef MATRICES_H
# define MATRICES_H

# include <sys/types.h>

typedef struct s_shear_params
{
	double	xy;
	double	xz;
	double	yx;
	double	yz;
	double	zx;
	double	zy;
}			t_shear_params;

typedef struct s_m2_col
{
	double	x;
	double	y;
}			t_m2_col;

typedef struct s_m3_col
{
	double	x;
	double	y;
	double	z;
}			t_m3_col;

typedef struct s_m4_col
{
	double	x;
	double	y;
	double	z;
	int		w;
}			t_m4_col;

typedef struct s_m2
{
	t_m2_col	*col0;
	t_m2_col	*col1;
}				t_m2;

typedef struct s_m3
{
	t_m3_col	*col0;
	t_m3_col	*col1;
	t_m3_col	*col2;
}				t_m3;

typedef struct s_m4
{
	t_m4_col	*col0;
	t_m4_col	*col1;
	t_m4_col	*col2;
	t_m4_col	*col3;
}				t_m4;

//add_col.c -- BEGIN
t_m2_col	*assign_m2_col(double x, double y);
t_m3_col	*assign_m3_col(double x, double y, double z);
t_m4_col	*assign_m4_col(double x, double y, double z, int w);
//add_col.c -- END

//cmp_col.c -- BEGIN
bool		cmp_m2_col(t_m2_col *col1, t_m2_col *col2);
bool		cmp_m3_col(t_m3_col *col1, t_m3_col *col2);
bool		cmp_m4_col(t_m4_col *col1, t_m4_col *col2);
//cmp_col.c -- END

//cofo.c -- BEGIN
double		ftm_m_minor(t_m3 *m3, int col, int row);
double		ftm_m3_cofactor(t_m3 *m3, int col, int row);
double		ftm_m4_cofactor(t_m4 *m4, int col, int row);
t_m3		*ftm_cofomatrix(t_m3 *m3);
//cofo.c -- END

//determinant.c -- BEGIN
double		ftm_m_dmt(t_m2 *m2);
double		ftm_m3_dmt(t_m3 *m3);
double		ftm_m4_dmt(t_m4 *m4);
//determinant.c -- END

//init_matrices.c -- BEGIN
t_m4		*init_m4(void);
t_m3		*init_m3(void);
t_m2		*init_m2(void);
//init_matrices.c -- END

//inversion.c -- BEGIN
bool		is_inversible(double determinante);
void		apply_col_inversion(t_m4 *m4, t_m4 *new_m4, double dmt);
t_m4		*ftm_m4_inversion(t_m4 *m4);
//inversion.c -- END

//m_cmp.c -- BEGIN
bool		ftm_m_cmp(void *matrice1, void *matrice2, int size);
bool		ftm_m2_cmp(t_m2 *matrice1, t_m2 *matrice2);
bool		ftm_m3_cmp(t_m3 *matrice1, t_m3 *matrice2);
bool		ftm_m4_cmp(t_m4 *matrice1, t_m4 *matrice2);
//m_cmp.c -- END

// m3_sub_matrix.c -- BEGIN
t_m2		*ftm_m3_subm(t_m3 *m3, int col, int row);
void		m3_subm_col_0(t_m3 *m3, t_m2 *m2, int *row);
void		m3_subm_col_1(t_m3 *m3, t_m2 *m2, int *row);
void		m3_subm_col_2(t_m3 *m3, t_m2 *m2, int *row);
// m3_sub_matrix.c -- END

// m4_sub_matrix.c -- BEGIN
t_m3		*ftm_m4_subm(t_m4 *m4, int col, int row);
void		m4_subm_col_0(t_m4 *m4, t_m3 *m3, int *row);
void		m4_subm_col_1(t_m4 *m4, t_m3 *m3, int *row);
void		m4_subm_col_2(t_m4 *m4, t_m3 *m3, int *row);
void		m4_subm_col_3(t_m4 *m4, t_m3 *m3, int *row);
// m4_sub_matrix.c -- END

//matrix-math.c -- BEGIN
t_tuples	*ftm_matrix_times_tuple(t_m4 *matrix, t_tuples *tuple);
double		get_col_component(t_m4_col *col, int row);
double		get_col_val(t_m4 *matrix, int col, int row);
void		set_result_col(t_m4 *matrix, int col_index, double vals[4]);
t_m4		*ftm_matrix_mult(t_m4 *m_a, t_m4 *m_b);
//matrix-math.c -- END

// rotate_matrix.c -- BEGIN
t_m4		*ftm_rotate_x(double radians);
t_m4		*ftm_rotate_y(double radians);
t_m4		*ftm_rotate_z(double radians);
double		radians(double degree);
// rotate_matrix.c -- END

// rotate_tuples.c -- BEGIN
t_tuples	*ftm_rotate_point_x(t_tuples *point, double radians);
t_tuples	*ftm_rotate_point_y(t_tuples *point, double radians);
t_tuples	*ftm_rotate_point_z(t_tuples *point, double radians);
t_tuples	*ftm_shear_point(t_tuples *point, t_shear_params *params);
// rotate_tuples.c -- END

// shearing.c -- BEGIN
t_m4		*ftm_shear_x(double xy, double xz);
t_m4		*ftm_shear_y(double xy, double xz);
t_m4		*ftm_shear_z(double xy, double xz);
t_m4		*ftm_shearing(t_shear_params *params);
// shearing.c -- END

// transformation.c -- BEGIN
t_m4		*ftm_translation(t_m4 *matrix, t_tuples *tuple);
t_m4		*ftm_scaling(t_m4 *matrix, t_tuples *tuple);
// transformation.c -- END

//transpose_matrix.c -- BEGIN
t_m4		*ftm_transpose_matrix(t_m4 *old_matrix);
//transpose_matrix.c -- END

#endif
#ifndef MATRICES_H
# define MATRICES_H

# include <sys/types.h>

/* Structure to hold shearing transformation parameters for all axes */
typedef struct s_shear_params
{
	double	xy;		/* X affected by Y */
	double	xz;		/* X affected by Z */
	double	yx;		/* Y affected by X */
	double	yz;		/* Y affected by Z */
	double	zx;		/* Z affected by X */
	double	zy;		/* Z affected by Y */
}			t_shear_params;

/* 2D column vector with x, y components */
typedef struct s_m2_col
{
	double	x;
	double	y;
}			t_m2_col;

/* 3D column vector with x, y, z components */
typedef struct s_m3_col
{
	double	x;
	double	y;
	double	z;
}			t_m3_col;

/* 4D column vector with x, y, z, w components */
typedef struct s_m4_col
{
	double	x;
	double	y;
	double	z;
	double	w;
}			t_m4_col;

/* 2x2 matrix represented as two column vectors */
typedef struct s_m2
{
	t_m2_col	*col0;
	t_m2_col	*col1;
}				t_m2;

/* 3x3 matrix represented as three column vectors */
typedef struct s_m3
{
	t_m3_col	*col0;
	t_m3_col	*col1;
	t_m3_col	*col2;
}				t_m3;

/* 4x4 matrix represented as four column vectors */
typedef struct s_m4
{
	t_m4_col	*col0;
	t_m4_col	*col1;
	t_m4_col	*col2;
	t_m4_col	*col3;
}				t_m4;

//add_col.c -- BEGIN
/* Creates a new 2D column vector with x, y components */
t_m2_col	*assign_m2_col(double x, double y);

/* Creates a new 3D column vector with x, y, z components */
t_m3_col	*assign_m3_col(double x, double y, double z);

/* Creates a new 4D column vector with x, y, z, w components */
t_m4_col	*assign_m4_col(double x, double y, double z, double w);
//add_col.c -- END

//cmp_col.c -- BEGIN
/* Compares two 2D column vectors for equality */
bool		cmp_m2_col(t_m2_col *col1, t_m2_col *col2);

/* Compares two 3D column vectors for equality */
bool		cmp_m3_col(t_m3_col *col1, t_m3_col *col2);

/* Compares two 4D column vectors for equality */
bool		cmp_m4_col(t_m4_col *col1, t_m4_col *col2);
//cmp_col.c -- END

//cofo.c -- BEGIN
/* Calculates the minor of a 3x3 matrix at given position */
double		ftm_m_minor(t_m3 *m3, int col, int row);

/* Calculates the cofactor of a 3x3 matrix element */
double		ftm_m3_cofactor(t_m3 *m3, int col, int row);

/* Calculates the cofactor of a 4x4 matrix element */
double		ftm_m4_cofactor(t_m4 *m4, int col, int row);

/* Creates the cofactor matrix of a 3x3 matrix */
t_m3		*ftm_cofomatrix(t_m3 *m3);
//cofo.c -- END

//determinant.c -- BEGIN
/* Calculates determinant of a 2x2 matrix */
double		ftm_m_dmt(t_m2 *m2);

/* Calculates determinant of a 3x3 matrix */
double		ftm_m3_dmt(t_m3 *m3);

/* Calculates determinant of a 4x4 matrix */
double		ftm_m4_dmt(t_m4 *m4);
//determinant.c -- END

// free_matrices.c -- BEGIN
void		free_matrix_m2(t_m2 *matrix);
void		free_matrix_m3(t_m3 *matrix);
void		free_matrix_m4(t_m4 *matrix);
// free_matrices.c -- END

//init_matrices.c -- BEGIN
/* Creates a 4x4 identity matrix */
t_m4		*init_identity(void);

/* Initializes an empty 4x4 matrix */
t_m4		*init_m4(void);

/* Initializes an empty 3x3 matrix */
t_m3		*init_m3(void);

/* Initializes an empty 2x2 matrix */
t_m2		*init_m2(void);
//init_matrices.c -- END

//inversion.c -- BEGIN
/* Checks if a matrix is invertible (determinant ≠ 0) */
bool		is_inversible(double determinante);

/* Applies inversion calculation to matrix columns */
void		apply_col_inversion(t_m4 *m4, t_m4 *new_m4, double dmt);

/* Calculates the inverse of a 4x4 matrix */
t_m4		*ftm_m4_inversion(t_m4 *m4);
//inversion.c -- END

//m_cmp.c -- BEGIN
/* Generic matrix comparison function */
bool		ftm_m_cmp(void *matrice1, void *matrice2, int size);

/* Compares two 2x2 matrices for equality */
bool		ftm_m2_cmp(t_m2 *matrice1, t_m2 *matrice2);

/* Compares two 3x3 matrices for equality */
bool		ftm_m3_cmp(t_m3 *matrice1, t_m3 *matrice2);

/* Compares two 4x4 matrices for equality */
bool		ftm_m4_cmp(t_m4 *matrice1, t_m4 *matrice2);
//m_cmp.c -- END

// m3_sub_matrix.c -- BEGIN
/* Creates 2x2 matrix by removing row/column from 3x3 matrix */
t_m2		*ftm_m3_subm(t_m3 *m3, int col, int row);

/* Helper for removing column 0 from 3x3 matrix */
void		m3_subm_col_0(t_m3 *m3, t_m2 *m2, int *row);

/* Helper for removing column 1 from 3x3 matrix */
void		m3_subm_col_1(t_m3 *m3, t_m2 *m2, int *row);

/* Helper for removing column 2 from 3x3 matrix */
void		m3_subm_col_2(t_m3 *m3, t_m2 *m2, int *row);
// m3_sub_matrix.c -- END

// m4_sub_matrix.c -- BEGIN
/* Creates 3x3 matrix by removing row/column from 4x4 matrix */
t_m3		*ftm_m4_subm(t_m4 *m4, int col, int row);

/* Helper for removing column 0 from 4x4 matrix */
void		m4_subm_col_0(t_m4 *m4, t_m3 *m3, int *row);

/* Helper for removing column 1 from 4x4 matrix */
void		m4_subm_col_1(t_m4 *m4, t_m3 *m3, int *row);

/* Helper for removing column 2 from 4x4 matrix */
void		m4_subm_col_2(t_m4 *m4, t_m3 *m3, int *row);

/* Helper for removing column 3 from 4x4 matrix */
void		m4_subm_col_3(t_m4 *m4, t_m3 *m3, int *row);
// m4_sub_matrix.c -- END

//matrix-math.c -- BEGIN
/* Multiplies 4x4 matrix by tuple/vector */
t_tuples	*ftm_matrix_times_tuple(t_m4 *matrix, t_tuples *tuple);

/* Gets specific component from a column vector */
double		get_col_component(t_m4_col *col, int row);

/* Gets value at specific row/column in matrix */
double		get_col_val(t_m4 *matrix, int col, int row);

/* Sets column values in result matrix */
void		set_result_col(t_m4 *matrix, int col_index, double vals[4]);

/* Multiplies two 4x4 matrices together */
t_m4		*ftm_matrix_mult(t_m4 *m_a, t_m4 *m_b);
//matrix-math.c -- END

// rotate_matrix.c -- BEGIN
/* Creates rotation matrix around X-axis */
t_m4		*ftm_rotate_x(double radians);

/* Creates rotation matrix around Y-axis */
t_m4		*ftm_rotate_y(double radians);

/* Creates rotation matrix around Z-axis */
t_m4		*ftm_rotate_z(double radians);

/* Converts degrees to radians */
double		radians(double degree);
// rotate_matrix.c -- END

// rotate_tuples.c -- BEGIN
/* Rotates point around X-axis */
t_tuples	*ftm_rotate_point_x(t_tuples *point, double radians);

/* Rotates point around Y-axis */
t_tuples	*ftm_rotate_point_y(t_tuples *point, double radians);

/* Rotates point around Z-axis */
t_tuples	*ftm_rotate_point_z(t_tuples *point, double radians);

/* Applies shearing transformation to point */
t_tuples	*ftm_shear_point(t_tuples *point, t_shear_params *params);
// rotate_tuples.c -- END

// shearing.c -- BEGIN
/* Creates shearing matrix affecting X-axis */
t_m4		*ftm_shear_x(double xy, double xz);

/* Creates shearing matrix affecting Y-axis */
t_m4		*ftm_shear_y(double yx, double yz);

/* Creates shearing matrix affecting Z-axis */
t_m4		*ftm_shear_z(double zx, double zy);

/* Creates general shearing matrix from parameters */
t_m4		*ftm_shearing(t_shear_params *params);
// shearing.c -- END

// transformation.c -- BEGIN
/* Applies translation to transformation matrix */
t_m4		*ftm_translation(t_tuples *tuple);

/* Applies scaling to transformation matrix */
t_m4		*ftm_scaling(t_tuples *tuple);
// transformation.c -- END

//transpose_matrix.c -- BEGIN
/* Creates transpose of a 4x4 matrix */
t_m4		*ftm_transpose_matrix(t_m4 *old_matrix);
//transpose_matrix.c -- END

#endif
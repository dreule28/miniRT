#include "mini_rt.h"

void	ftm_matrix_times_tuple(t_tuples *res, t_m4 matrix, t_tuples tuple)
{
	res->x = matrix.col0.x * tuple.x + matrix.col1.x * tuple.y
		+ matrix.col2.x * tuple.z + matrix.col3.x * tuple.w;
	res->y = matrix.col0.y * tuple.x + matrix.col1.y * tuple.y
		+ matrix.col2.y * tuple.z + matrix.col3.y * tuple.w;
	res->z = matrix.col0.z * tuple.x + matrix.col1.z * tuple.y
		+ matrix.col2.z * tuple.z + matrix.col3.z * tuple.w;
	res->w = matrix.col0.w * tuple.x + matrix.col1.w * tuple.y
		+ matrix.col2.w * tuple.z + matrix.col3.w * tuple.w;
}

double	get_col_component(t_m4_col col, int row)
{
	if (row == 0)
		return (col.x);
	if (row == 1)
		return (col.y);
	if (row == 2)
		return (col.z);
	if (row == 3)
		return (col.w);
	return (0.0);
}

double	get_col_val(t_m4 matrix, int col, int row)
{
	if (row < 0 || row > 3 || col < 0 || col > 3)
		return (0.0);
	if (col == 0)
		return (get_col_component(matrix.col0, row));
	if (col == 1)
		return (get_col_component(matrix.col1, row));
	if (col == 2)
		return (get_col_component(matrix.col2, row));
	if (col == 3)
		return (get_col_component(matrix.col3, row));
	return (0.0);
}

void	set_result_col(t_m4 *matrix, int col_index, double vals[4])
{
	t_m4_col	new_col;
	t_m4_col	col_values;

	if (!matrix || col_index < 0 || col_index > 3 || !vals)
		return ;
	col_values = (t_m4_col){vals[0], vals[1], vals[2], vals[3]};
	assign_m4_col(&new_col, col_values);
	if (col_index == 0)
		matrix->col0 = new_col;
	if (col_index == 1)
		matrix->col1 = new_col;
	if (col_index == 2)
		matrix->col2 = new_col;
	if (col_index == 3)
		matrix->col3 = new_col;
}

void	ftm_matrix_mult(t_m4 *m_c, t_m4 m_a, t_m4 m_b)
{
	int		col;
	int		row;
	double	vals[4];

	col = -1;
	while (++col < 4)
	{
		row = -1;
		while (++row < 4)
		{
			vals[row] = get_col_val(m_a, 0, row) * get_col_val(m_b, col, 0)
				+ get_col_val(m_a, 1, row) * get_col_val(m_b, col, 1)
				+ get_col_val(m_a, 2, row) * get_col_val(m_b, col, 2)
				+ get_col_val(m_a, 3, row) * get_col_val(m_b, col, 3);
		}
		set_result_col(m_c, col, vals);
	}
}

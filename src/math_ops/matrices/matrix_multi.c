#include "mini_rt.h"

t_tuples	*ftm_matrix_times_tuple(t_m4 *matrix, t_tuples *tuple)
{
	t_tuples	*res;

	res = malloc(sizeof(t_tuples));
	if (!res)
		return (NULL);
	res->x = matrix->col0->x * tuple->x + matrix->col1->x * tuple->y
		+ matrix->col2->x * tuple->z + matrix->col3->x * tuple->w;
	res->y = matrix->col0->y * tuple->x + matrix->col1->y * tuple->y
		+ matrix->col2->y * tuple->z + matrix->col3->y * tuple->w;
	res->z = matrix->col0->z * tuple->x + matrix->col1->z * tuple->y
		+ matrix->col2->z * tuple->z + matrix->col3->z * tuple->w;
	res->w = matrix->col0->w * tuple->x + matrix->col1->w * tuple->y
		+ matrix->col2->w * tuple->z + matrix->col3->w * tuple->w;
	return (res);
}

double	get_col_component(t_m4_col *col, int row)
{
	if (!col)
		return (0.0);
	if (row == 0)
		return (col->x);
	if (row == 1)
		return (col->y);
	if (row == 2)
		return (col->z);
	if (row == 3)
		return (col->w);
	return (0.0);
}

double	get_col_val(t_m4 *matrix, int col, int row)
{
	if (!matrix || row < 0 || row > 3 || col < 0 || col > 3)
		return (0.0);
	if (col == 0)
		return (get_col_component(matrix->col0, row));
	if (col == 1)
		return (get_col_component(matrix->col1, row));
	if (col == 2)
		return (get_col_component(matrix->col2, row));
	if (col == 3)
		return (get_col_component(matrix->col3, row));
	return (0.0);
}

void	set_result_col(t_m4 *matrix, int col_index, double vals[4])
{
	t_m4_col	*new_col;

	if (!matrix || col_index < 0 || col_index > 3 || !vals)
		return ;
	new_col = assign_m4_col(vals[0], vals[1], vals[2], (int)vals[3]);
	if (!new_col)
		return ;
	if (col_index == 0)
		matrix->col0 = new_col;
	if (col_index == 1)
		matrix->col1 = new_col;
	if (col_index == 2)
		matrix->col2 = new_col;
	if (col_index == 3)
		matrix->col3 = new_col;
}

t_m4	*ftm_matrix_mult(t_m4 *m_a, t_m4 *m_b)
{
	t_m4	*m_c;
	int		col;
	int		row;
	double	vals[4];

	m_c = init_m4();
	if (!m_c || !m_a || !m_b)
		return (NULL);
	if (!m_a->col0 || !m_a->col1 || !m_a->col2 || !m_a->col3 || !m_b->col0
		|| !m_b->col1 || !m_b->col2 || !m_b->col3)
		return (m_c);
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
	return (m_c);
}

#include "mini_rt.h"

t_m2	*init_m2(void)
{
	t_m2	*m2;

	m2 = ft_calloc(1, sizeof(t_m2));
	if (!m2)
		return (NULL);
	m2->col0 = NULL;
	m2->col1 = NULL;
	return (m2);
}

t_m3	*init_m3(void)
{
	t_m3	*m3;

	m3 = ft_calloc(1, sizeof(t_m3));
	if (!m3)
		return (NULL);
	m3->col0 = NULL;
	m3->col1 = NULL;
	m3->col2 = NULL;
	return (m3);
}

t_m4	*init_m4(void)
{
	t_m4	*m4;

	m4 = ft_calloc(1, sizeof(t_m4));
	if (!m4)
		return (NULL);
	m4->col0 = NULL;
	m4->col1 = NULL;
	m4->col2 = NULL;
	m4->col3 = NULL;
	return (m4);
}

t_m4	*init_identity(void)
{
	t_m4	*new_matrix;

	new_matrix = init_m4();
	if (!new_matrix)
		return (NULL);
	new_matrix->col0 = assign_m4_col(1, 0, 0, 0);
	new_matrix->col1 = assign_m4_col(0, 1, 0, 0);
	new_matrix->col2 = assign_m4_col(0, 0, 1, 0);
	new_matrix->col3 = assign_m4_col(0, 0, 0, 1);
	return (new_matrix);
}

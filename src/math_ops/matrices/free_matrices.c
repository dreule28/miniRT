#include "mini_rt.h"

void	free_matrix_m4(t_m4 *matrix)
{
	if (matrix)
	{
		free(&matrix->col0);
		free(&matrix->col1);
		free(&matrix->col2);
		free(&matrix->col3);
		free(matrix);
	}
}

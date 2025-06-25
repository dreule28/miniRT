#include "mini_rt.h"

void	free_obj_data(t_obj_data *data, int type)
{
	if (type == SPHERE && data->sphere)
		free(data->sphere);
	else if (type == PLANE && data->plane)
		free(data->plane);
	else if (type == CYLINDER && data->cylinder)
		free(data->cylinder);
	free(data);
}

void	free_obj_list(t_obj_list *obj_list)
{
	t_obj_node	*curr;
	t_obj_node	*next;

	curr = obj_list->head;
	while (curr)
	{
		next = curr->next;
		free_obj_data(curr->data, curr->type);
		free(curr);
		curr = next;
	}
	free(obj_list);
}

void	free_light_list(t_light_list *light_list)
{
	t_light	*curr;
	t_light	*next;

	curr = light_list->head;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	free(light_list);
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
	t_m3 *m3;

	m3 = init_m3();
    m3->col0 = assign_m3_col(1.0, 5.0, 0.0);
    m3->col1 = assign_m3_col(2.0, 6.0, -3.0);
    m3->col2 = assign_m3_col(3.0, 8.0, 4.0);
    // Test Case 1: Identity matrix (should return 1)
// First print the original 3x3 matrix
printf("\nOriginal 3x3 Matrix:\n");
printf("[%.2f  %.2f  %.2f]\n", m3->col0->x, m3->col1->x, m3->col2->x);
printf("[%.2f  %.2f  %.2f]\n", m3->col0->y, m3->col1->y, m3->col2->y);
printf("[%.2f  %.2f  %.2f]\n", m3->col0->z, m3->col1->z, m3->col2->z);

// Get and print the submatrix
int col = 1;
int row = 1;
t_m2 *subm = m3_subm(m3, col, row);  // Example: removing row 0, col 0
printf("\nSubmatrix (removing col %d, row %d):\n", col , row);
printf("[%.2f  %.2f]\n", subm->col0->x, subm->col1->x);
printf("[%.2f  %.2f]\n", subm->col0->y, subm->col1->y);
free(subm->col0);
free(subm->col1);
free(subm);
    return(0);
}

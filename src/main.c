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
    t_m4 *m4;
    t_m3 *subm;

    // Initialize and assign values to 4x4 matrix
    m4 = init_m4();
    m4->col0 = assign_m4_col(1.0, 5.0, 9.0, 13.0);
    m4->col1 = assign_m4_col(2.0, 6.0, 10.0, 14.0);
    m4->col2 = assign_m4_col(3.0, 7.0, 11.0, 15.0);
    m4->col3 = assign_m4_col(4.0, 8.0, 12.0, 16.0);

    // Print original 4x4 matrix
    printf("\nOriginal 4x4 Matrix:\n");
    printf("[%.2f  %.2f  %.2f  %.2f]\n", m4->col0->x, m4->col1->x, m4->col2->x, m4->col3->x);
    printf("[%.2f  %.2f  %.2f  %.2f]\n", m4->col0->y, m4->col1->y, m4->col2->y, m4->col3->y);
    printf("[%.2f  %.2f  %.2f  %.2f]\n", m4->col0->z, m4->col1->z, m4->col2->z, m4->col3->z);
    printf("[%.2d  %.2d  %.2d  %.2d]\n", m4->col0->w, m4->col1->w, m4->col2->w, m4->col3->w);

    // Test submatrix by removing different rows and columns
    int col = 0;  // Try different values 0-3
    int row = 0;  // Try different values 0-3
    
    subm = m4_subm(m4, col, row);
    printf("\nSubmatrix (removing col %d, row %d):\n", col, row);
    printf("[%.2f  %.2f  %.2f]\n", subm->col0->x, subm->col1->x, subm->col2->x);
    printf("[%.2f  %.2f  %.2f]\n", subm->col0->y, subm->col1->y, subm->col2->y);
    printf("[%.2f  %.2f  %.2f]\n", subm->col0->z, subm->col1->z, subm->col2->z);

    // Free memory
    free(m4->col0);
    free(m4->col1);
    free(m4->col2);
    free(m4->col3);
    free(m4);
    free(subm->col0);
    free(subm->col1);
    free(subm->col2);
    free(subm);

    return (0);
}

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

int main(void)
{
    t_m3 *m3;
    t_m3 *cofactor_matrix;

    // Initialize and assign values to 3x3 matrix
    m3 = init_m3();
    m3->col0 = assign_m3_col(3.0, 5.0, 0.0);
    m3->col1 = assign_m3_col(2.0, -1.0, -7.0);
    m3->col2 = assign_m3_col(6.0, -1.0, 5.0);

    // Print original matrix
    printf("\nOriginal Matrix:\n");
    printf("[%.2f  %.2f  %.2f]\n", m3->col0->x, m3->col1->x, m3->col2->x);
    printf("[%.2f  %.2f  %.2f]\n", m3->col0->y, m3->col1->y, m3->col2->y);
    printf("[%.2f  %.2f  %.2f]\n", m3->col0->z, m3->col1->z, m3->col2->z);

    // Get and print cofactor matrix
    cofactor_matrix = ftm_cofomatrix(m3);
    printf("\nCofactor Matrix:\n");
    printf("[%.2f  %.2f  %.2f]\n", cofactor_matrix->col0->x, cofactor_matrix->col1->x, cofactor_matrix->col2->x);
    printf("[%.2f  %.2f  %.2f]\n", cofactor_matrix->col0->y, cofactor_matrix->col1->y, cofactor_matrix->col2->y);
    printf("[%.2f  %.2f  %.2f]\n", cofactor_matrix->col0->z, cofactor_matrix->col1->z, cofactor_matrix->col2->z);

    // Free memory
    free(m3->col0);
    free(m3->col1);
    free(m3->col2);
    free(m3);
    free(cofactor_matrix->col0);
    free(cofactor_matrix->col1);
    free(cofactor_matrix->col2);
    free(cofactor_matrix);

    return (0);
}

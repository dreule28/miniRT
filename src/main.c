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
    t_m4 *m4;
	double det;
	double cofo;
    // Initialize and assign values to 3x3 matrix
    m4 = init_m4();
    m4->col0 = assign_m4_col(-5.0, 1.0, 7.0, 1);
    m4->col1 = assign_m4_col(2.0, -5.0, 7.0, -3);
    m4->col2 = assign_m4_col(6.0, 1.0, -6.0, 7);
    m4->col3 = assign_m4_col(-8.0, 8.0, -7.0, 4);

    // Print original matrix
    printf("\nOriginal invertible Matrix:\n");
    printf("[%.2f  %.2f  %.2f  %.2f]\n", m4->col0->x, m4->col1->x, m4->col2->x, m4->col3->x);
    printf("[%.2f  %.2f  %.2f  %.2f]\n", m4->col0->y, m4->col1->y, m4->col2->y, m4->col3->y);
    printf("[%.2f  %.2f  %.2f  %.2f]\n", m4->col0->z, m4->col1->z, m4->col2->z, m4->col3->z);
    printf("[%d  %d  %d  %d]\n", m4->col0->w, m4->col1->w, m4->col2->w, m4->col3->w);
	// printf("DET: %.2f\n", det);
	// if (is_inversible(m4_dmt(m4)))
	// 	printf("Is inversible\n");
	// else
	// 	printf("Is not inversible\n");
	det = m4_dmt(m4);
	cofo = m4_cofactor(m4, 3, 2);
	printf("cofo(A, 2, 3): %.2f\n", m4_cofactor(m4, 3, 2));
	printf("B[3,2]: %.5f\n", cofo / det);
	cofo = m4_cofactor(m4, 2, 3);
	printf("cofo(A, 3, 2): %.2f\n", m4_cofactor(m4, 2, 3));
	printf("B[2,3]: %.5f\n", cofo / det);

    // m4 = init_m4();
    // m4->col0 = assign_m4_col(6.0, 9.0, 0.0, 0);
    // m4->col1 = assign_m4_col(2.0, 6.0, -5.0, 0);
    // m4->col2 = assign_m4_col(-2.0, 2.0, 1.0, 0);
    // m4->col3 = assign_m4_col(-3.0, 6.0, -5.0, 0);

    // printf("\nOriginal non-invertible Matrix:\n");
    // printf("[%.2f  %.2f  %.2f  %.2f]\n", m4->col0->x, m4->col1->x, m4->col2->x, m4->col3->x);
    // printf("[%.2f  %.2f  %.2f  %.2f]\n", m4->col0->y, m4->col1->y, m4->col2->y, m4->col3->y);
    // printf("[%.2f  %.2f  %.2f  %.2f]\n", m4->col0->z, m4->col1->z, m4->col2->z, m4->col3->z);
    // printf("[%d  %d  %d  %d]\n", m4->col0->w, m4->col1->w, m4->col2->w, m4->col3->w);
	// printf("DET: %.2f\n", m4_dmt(m4));
	// if (is_inversible(m4_dmt(m4)))
	// 	printf("Is inversible\n");
	// else
	// 	printf("Is not inversible\n");
    // Get and print cofactor matrix

    // Free memory
    free(m4->col0);
    free(m4->col1);
    free(m4->col2);
    free(m4->col3);
    free(m4);

    return (0);
}

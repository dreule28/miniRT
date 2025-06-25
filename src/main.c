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
    double minor;

    // Initialize 3x3 matrix with test values
    m3 = init_m3();
    m3->col0 = assign_m3_col(3.0, 2.0, 6.0);
    m3->col1 = assign_m3_col(5.0, -1.0, -1.0);
    m3->col2 = assign_m3_col(0.0, -7.0, 5.0);

    // Print original 3x3 matrix
    printf("\nOriginal 3x3 Matrix:\n");
    printf("[%.2f  %.2f  %.2f]\n", m3->col0->x, m3->col1->x, m3->col2->x);
    printf("[%.2f  %.2f  %.2f]\n", m3->col0->y, m3->col1->y, m3->col2->y);
    printf("[%.2f  %.2f  %.2f]\n", m3->col0->z, m3->col1->z, m3->col2->z);

    // Test minor for different positions
    int col = 0;  // Try different values 0-2
    int row = 1;  // Try different values 0-2
    
    minor = m_minor(m3, col, row);
    printf("\nMinor (col %d, row %d): %.2f\n", col, row, minor);

    // Free memory
    free(m3->col0);
    free(m3->col1);
    free(m3->col2);
    free(m3);

    return (0);
}

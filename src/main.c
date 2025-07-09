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
		free(curr->t);
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

void	print_matrix(t_m4 *m)
{
	if (!m || !m->col0 || !m->col1 || !m->col2 || !m->col3)
	{
		printf("Invalid matrix pointer.\n");
		return;
	}
	
	printf("Matrix:\n");
	printf("| %6.2f %6.2f %6.2f %6.2f |\n", m->col0->x, m->col1->x, m->col2->x, m->col3->x);
	printf("| %6.2f %6.2f %6.2f %6.2f |\n", m->col0->y, m->col1->y, m->col2->y, m->col3->y);
	printf("| %6.2f %6.2f %6.2f %6.2f |\n", m->col0->z, m->col1->z, m->col2->z, m->col3->z);
	printf("| %6.2f %6.2f %6.2f %6.2f |\n", m->col0->w, m->col1->w, m->col2->w, m->col3->w);
}


int	main(int argc, char **argv)
{
	t_scene	*scene;

	scene = ft_calloc(sizeof(t_scene), 1);
	if (!scene)
		return (1);
	if (!parser(scene, argc, argv))
		return (free(scene), 1);

	// t_m4 *m = ftm_translation(init_identity(), init_vector(5, 0, 0));
	t_m4	*new_matrix;

	new_matrix = init_m4();
	// if (!new_matrix)
	// 	return (NULL);
	new_matrix->col0 = assign_m4_col(8, 7, -6, -3);
	new_matrix->col1 = assign_m4_col(-5, 5, 0, 0);
	new_matrix->col2 = assign_m4_col(9, 6, 9, -9);
	new_matrix->col3 = assign_m4_col(2, 1, 6, -4);
	print_matrix(new_matrix);
	t_m4 *inv = ftm_m4_inversion(new_matrix);
	print_matrix(inv);
	t_m4 *result = ftm_matrix_mult(new_matrix, inv);
	print_matrix(result);

	// free_obj_list(scene->obj_list);
	// free_light_list(scene->light_list);
	// free(scene);
	return (0);
}

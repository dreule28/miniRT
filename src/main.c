#include "mini_rt.h"

void	free_obj_data(t_obj_data *data, int type)
{
	if (type == SPHERE && data->sphere)
	{
		if (data->sphere->matrix)
		{
			free(data->sphere->matrix->col0);
			free(data->sphere->matrix->col1);
			free(data->sphere->matrix->col2);
			free(data->sphere->matrix->col3);
			free(data->sphere->matrix);
		}
		free(data->sphere);
	}
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

void print_matrix(t_m4 *matrix)
{
    printf("Matrix:\n");
    printf("| %8.5f | %8.5f | %8.5f | %8.5f |\n", 
           matrix->col0->x, matrix->col1->x, matrix->col2->x, matrix->col3->x);
    printf("| %8.5f | %8.5f | %8.5f | %8.5f |\n", 
           matrix->col0->y, matrix->col1->y, matrix->col2->y, matrix->col3->y);
    printf("| %8.5f | %8.5f | %8.5f | %8.5f |\n", 
           matrix->col0->z, matrix->col1->z, matrix->col2->z, matrix->col3->z);
    printf("| %8.5f | %8.5f | %8.5f | %8.5f |\n", 
           matrix->col0->w, matrix->col1->w, matrix->col2->w, matrix->col3->w);
}

int	main(int argc, char **argv)
{
	t_scene	*scene;

	scene = ft_calloc(sizeof(t_scene), 1);
	if (!scene)
		return (1);
	if (!parser(scene, argc, argv))
		return (free(scene), 1);
		t_tuples *from = init_point(1, 3, 2);
		t_tuples *to = init_point(4, -2, 8);
		t_tuples *up = init_vector(1, 1, 0);
	// if (!init_mlx_window(scene))
	// 	return (1);
	t_m4 *result = view_transformation(from, to, up);
	print_matrix(result);
	// ray_tracing(scene);
	// mlx_key_hook(scene->mlx, &key_hook, scene);
	// mlx_loop(scene->mlx);
	// mlx_terminate(scene->mlx);
	return (0);
}

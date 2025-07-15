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

int	main(int argc, char **argv)
{
	t_scene		*scene;

	scene = ft_calloc(sizeof(t_scene), 1);
	if (!scene)
		return (1);
	if (!parser(scene, argc, argv))
		return (free(scene), 1);


	t_tuples *position = init_point(0, 0, 0);
	t_tuples *eyev = init_vector(0, 0, -1);
	t_tuples *normalv = init_vector(0, 0, -1);
	scene->light_list->head = point_light(*init_point(0, 0, 10), *init_rgb(1, 1, 1));
	t_rgb result = lighting(scene, position, eyev, normalv);

	printf("R: %.1f G: %.1f B: %.1f\n", result.r, result.g, result.b);


	// printf("About to init MLX window...\n");
	// fflush(stdout);

	// if(!init_mlx_window(scene))
	// {
	//     printf("MLX window init failed\n");
	//     return(1);
	// }

	// printf("MLX window init successful\n");
	// printf("About to set custom hooks...\n");
	// fflush(stdout);

	// mlx_custom_hooks(scene);

	// printf("Custom hooks set, starting MLX loop...\n");
	// fflush(stdout);

	// mlx_loop(scene->mlx);

	// mlx_terminate(scene->mlx);
	free_obj_list(scene->obj_list);
	free_light_list(scene->light_list);
	free(scene);
	return(0);
}

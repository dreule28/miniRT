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
	t_material	material;
	t_light		*light;
	t_rgb		result;

	scene = ft_calloc(sizeof(t_scene), 1);
	if (!scene)
		return (1);
	if (!parser(scene, argc, argv))
		return (free(scene), 1);


	scene->obj_list->head->data->sphere->material = get_material();
	scene->light_list->head = point_light(*init_point(0, 0, -10), *init_rgb(1, 1, 1));

	material = scene->obj_list->head->data->sphere->material;
	light = scene->light_list->head;

	result = lighting(scene, )



	// if(!init_mlx_window(scene))
	// 	return(1);
	// mlx_custom_hooks(scene);
	// mlx_loop(scene->mlx);
	// mlx_terminate(scene->mlx);
	// free_obj_list(scene->obj_list);
	// free_light_list(scene->light_list);
	// free(scene);
	return(0);
}

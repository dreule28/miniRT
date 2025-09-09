/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:00:17 by dreule            #+#    #+#             */
/*   Updated: 2025/09/09 15:00:18 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	free_obj_data(t_obj_data *data, int type)
{
	if (type == SPHERE && data->sphere)
		free(data->sphere);
	else if (type == PLANE && data->plane)
		free(data->plane);
	else if (type == CYLINDER && data->cylinder)
		free(data->cylinder);
	else if (type == CUBE && data->cube)
		free(data->cube);
	else if (type == TRIANGLE && data->triangle)
		free(data->triangle);
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

void	handle_syntax_error(t_scene *scene)
{
	if (scene->syntax_count > 2)
		ft_putstr_fd("Error\nToo many Elements\n", 2);
	else
		ft_putstr_fd("Error\nParser failed\n", 2);
}

int	main(int argc, char **argv)
{
	t_scene		*scene;

	scene = ft_calloc(sizeof(t_scene), 1);
	if (!scene)
		return (1);
	if (!parser(scene, argc, argv) || scene->syntax_count > 2)
		return (handle_syntax_error(scene), free(scene), 1);
	translate_objs(scene);
	if (!init_mlx_window(scene))
		return (1);
	bonus_scenes(scene, argv[1]);
	render(scene);
	mlx_key_hook(scene->mlx, &key_hook, scene);
	mlx_loop(scene->mlx);
	mlx_terminate(scene->mlx);
	free_light_list(scene->light_list);
	free_obj_list(scene->obj_list);
	free(scene);
	return (0);
}

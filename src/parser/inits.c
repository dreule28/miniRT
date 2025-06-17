#include "mini_rt.h"

bool	init_lists(t_obj_list **obj_list, t_light_list **light_list)
{
	*obj_list = init_obj_list();
	*light_list = init_light_list();
	if (!(*obj_list) || !(*light_list))
		return (false);
	return (true);
}

t_obj_data	*init_sphere_data(t_obj_data *data)
{
	data->sphere = malloc(sizeof(t_sphere_node));
	if (!data->sphere)
		return (free(data), NULL);
	data->sphere = init_sphere(data->sphere);
	return (data);
}

t_obj_data	*init_plane_data(t_obj_data *data)
{
	data->plane = malloc(sizeof(t_plane_node));
	if (!data->plane)
		return (free(data), NULL);
	data->plane = init_plane(data->plane);
	return (data);
}

t_obj_data	*init_cylinder_data(t_obj_data *data)
{
	data->cylinder = malloc(sizeof(t_cylinder_node));
	if (!data->cylinder)
		return (free(data), NULL);
	data->cylinder = init_cylinder(data->cylinder);
	return (data);
}

void	search_for_objects(t_scene *scene, char *parsed_line)
{
	t_obj_node	*new_node;

	if (!ft_strncmp(parsed_line, "pl", 2))
	{
		new_node = add_obj_node(scene->obj_list, PLANE);
		add_plane(new_node, parsed_line);
	}
	if (!ft_strncmp(parsed_line, "sp", 2))
	{
		new_node = add_obj_node(scene->obj_list, SPHERE);
		add_sphere(new_node, parsed_line);
	}
	if (!ft_strncmp(parsed_line, "cy", 2))
	{
		new_node = add_obj_node(scene->obj_list, CYLINDER);
		add_cylinder(new_node, parsed_line);
	}
}

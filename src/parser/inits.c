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
	data->sphere = init_sphere();
	if (!data->sphere)
		return (free(data), NULL);
	data->sphere->material = get_material();
	data->sphere->material.pattern.has_pattern = false;
	return (data);
}

t_obj_data	*init_plane_data(t_obj_data *data)
{
	data->plane = init_plane();
	if (!data->plane)
		return (free(data), NULL);
	data->plane->material = get_material();
	data->plane->material.pattern.has_pattern = false;
	return (data);
}

t_obj_data	*init_cylinder_data(t_obj_data *data)
{
	data->cylinder = init_cylinder();
	if (!data->cylinder)
		return (free(data), NULL);
	data->cylinder->material = get_material();
	data->cylinder->material.pattern.has_pattern = false;
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
	if (!ft_strncmp(parsed_line, "cb", 2))
	{
		new_node = add_obj_node(scene->obj_list, CUBE);
		add_cube(new_node, parsed_line);
	}
	if (!ft_strncmp(parsed_line, "tr", 2))
		handle_triangle(scene, new_node, parsed_line);
}

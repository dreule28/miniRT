#include "mini_rt.h"

t_obj_list	*init_obj_list(void)
{
	t_obj_list	*obj_list;

	obj_list = ft_calloc(sizeof(t_obj_list), 1);
	if (!obj_list)
		return (NULL);
	obj_list->head = NULL;
	obj_list->tail = NULL;
	obj_list->size = 0;
	return (obj_list);
}

t_obj_node	*add_obj_node(t_obj_list *obj_list, int obj_type)
{
	t_obj_node	*new_node;

	new_node = ft_calloc(sizeof(t_obj_node), 1);
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->type = obj_type;
	init_identity(&new_node->matrix);
	new_node->data = init_obj_data(obj_type);
	if (!new_node->data)
		return (free(new_node), NULL);
	if (!obj_list->head)
		obj_list->head = new_node;
	else
		obj_list->tail->next = new_node;
	obj_list->tail = new_node;
	obj_list->size++;
	return (new_node);
}

t_obj_data	*init_obj_data(int obj_type)
{
	t_obj_data	*new_data;

	new_data = ft_calloc(sizeof(t_obj_data), 1);
	if (!new_data)
		return (NULL);
	if (obj_type == SPHERE)
		return (init_sphere_data(new_data));
	else if (obj_type == PLANE)
		return (init_plane_data(new_data));
	else if (obj_type == CYLINDER)
		return (init_cylinder_data(new_data));
	else if (obj_type == CUBE)
		return (init_cube_data(new_data));
	else if (obj_type == CONE)
		return (init_cone_data(new_data));
	else
		return (free(new_data), NULL);
}

t_light_list	*init_light_list(void)
{
	t_light_list	*light_list;

	light_list = ft_calloc(sizeof(t_light_list), 1);
	if (!light_list)
		return (NULL);
	light_list->head = NULL;
	light_list->tail = NULL;
	light_list->size = 0;
	return (light_list);
}

t_light	*add_light_node(t_light_list *light_list, char *parsed_line)
{
	t_light	*new_node;

	new_node = ft_calloc(sizeof(t_light), 1);
	if (!new_node)
		return (NULL);
	add_light(new_node, parsed_line);
	new_node->next = NULL;
	if (!light_list->head)
		light_list->head = new_node;
	else
		light_list->tail->next = new_node;
	light_list->tail = new_node;
	light_list->size++;
	return (new_node);
}

#include "mini_rt.h"

t_cone	*init_cone(void)
{
	t_cone	*cone;

	cone = ft_calloc(sizeof(t_cone), 1);
	if (!cone)
		return (NULL);
	init_point(&cone->pos, 0, 0, 0);
	init_vector(&cone->axis, 0, 1, 0);
	cone->minimum = -INFINITY;
	cone->maximum = INFINITY;
	cone->closed = true;
	return (cone);
}

t_obj_data	*init_cone_data(t_obj_data *data)
{
	data->cone = init_cone();
	if (!data->cone)
		return (free(data), NULL);
	data->cone->material = get_material();
	data->cone->material.pattern.has_pattern = false;
	return (data);
}

void	add_cone(t_obj_node *obj_node, char *parsed_line)
{
	skip_spaces_or_value(&parsed_line, 1, 0);
	skip_spaces_or_value(&parsed_line, 0, 0);
	obj_node->data->cone->pos.x = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->cone->pos.y = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->cone->pos.z = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 1, 0);
	obj_node->data->cone->axis.x = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->cone->axis.y = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->cone->axis.z = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 1, 0);
	obj_node->data->cone->radius = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 0);
	skip_spaces_or_value(&parsed_line, 1, 0);
	obj_node->data->cone->height = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 0);
	skip_spaces_or_value(&parsed_line, 1, 0);
	obj_node->data->cone->material.rgb.r = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->cone->material.rgb.g = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->cone->material.rgb.b = ft_atof(parsed_line);
}

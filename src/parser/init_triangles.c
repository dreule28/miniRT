#include "mini_rt.h"

t_triangle	*init_triangle(void)
{
	t_triangle	*triangle;

	triangle = ft_calloc(sizeof(t_triangle), 1);
	if (!triangle)
		return (NULL);
	init_point(&triangle->p1, 0, 0, 0);
	init_point(&triangle->p2, 0, 0, 0);
	init_point(&triangle->p3, 0, 0, 0);
	init_vector(&triangle->e1, 0, 0, 0);
	init_vector(&triangle->e2, 0, 0, 0);
	init_vector(&triangle->normal, 0, 0, 0);
	init_rgb(&triangle->material.rgb,0, 0, 0);
	return (triangle);
}

void	add_triangle_p1(t_obj_node *obj_node, char *parsed_line)
{
	skip_spaces_or_value(&parsed_line, 1, 0);
	skip_spaces_or_value(&parsed_line, 0, 0);
	obj_node->data->triangle->p1.x = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->triangle->p1.y = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->triangle->p1.z = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 1, 0);
	obj_node->data->triangle->p2.x = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->triangle->p2.y = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->triangle->p2.z = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 1, 0);
	obj_node->data->triangle->p3.x = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->triangle->p3.y = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->triangle->p3.z = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 1, 0);
	add_triangle_p2(obj_node, parsed_line);
}

void	add_triangle_p2(t_obj_node *obj_node, char *parsed_line)
{
	obj_node->data->triangle->e1.x = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->triangle->e1.y = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->triangle->e1.z = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 1, 0);
	obj_node->data->triangle->e2.x = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->triangle->e2.y = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->triangle->e2.z = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 1, 0);
	obj_node->data->triangle->normal.x = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->triangle->normal.y = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->triangle->normal.z = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 0);
	skip_spaces_or_value(&parsed_line, 1, 0);
	obj_node->data->triangle->material.rgb.r = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->triangle->material.rgb.g = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->triangle->material.rgb.b = ft_atof(parsed_line);
	normalize_rgb_triplet(&obj_node->data->triangle->material.rgb);
}

t_obj_data	*init_triangle_data(t_obj_data *data)
{
	data->triangle = init_triangle();
	if (!data->triangle)
		return (free(data), NULL);
	data->triangle->material = get_material();
	data->triangle->material.pattern.has_pattern = false;
	return (data);
}

void	handle_triangle(t_scene *scene, t_obj_node *new_node, char *parsed_line)
{
	new_node = add_obj_node(scene->obj_list, TRIANGLE);
	add_triangle_p1(new_node, parsed_line);
}

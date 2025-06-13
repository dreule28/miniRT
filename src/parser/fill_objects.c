#include "mini_rt.h"

void	add_plane(t_obj_node *obj_node, char *parsed_line)
{
	skip_spaces_or_value(&parsed_line, 1, 0);
	skip_spaces_or_value(&parsed_line, 0, 0);
	obj_node->data->plane->pos.x = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->plane->pos.y = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->plane->pos.z = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 1, 0);
	obj_node->data->plane->axis.x = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->plane->axis.y = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->plane->axis.z = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 1, 0);
	obj_node->data->plane->rgb.r = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->plane->rgb.g = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->plane->rgb.b = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
}

void	add_cylinder(t_obj_node *obj_node, char *parsed_line)
{
	skip_spaces_or_value(&parsed_line, 1, 0);
	skip_spaces_or_value(&parsed_line, 0, 0);
	obj_node->data->cylinder->pos.x = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->cylinder->pos.y = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->cylinder->pos.z = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 1, 0);
	obj_node->data->cylinder->axis.x = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->cylinder->axis.y = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->cylinder->axis.z = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 1, 0);
	obj_node->data->cylinder->diameter = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 0);
	skip_spaces_or_value(&parsed_line, 1, 0);
	obj_node->data->cylinder->height = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 0);
	skip_spaces_or_value(&parsed_line, 1, 0);
	obj_node->data->cylinder->rgb.r = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->cylinder->rgb.g = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->cylinder->rgb.b = ft_atof(parsed_line);
}

void	add_sphere(t_obj_node *obj_node, char *parsed_line)
{
	skip_spaces_or_value(&parsed_line, 1, 0);
	skip_spaces_or_value(&parsed_line, 0, 0);
	obj_node->data->sphere->pos.x = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->sphere->pos.y = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->sphere->pos.z = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 1, 0);
	obj_node->data->sphere->diameter = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 0);
	skip_spaces_or_value(&parsed_line, 1, 0);
	obj_node->data->sphere->rgb.r = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->sphere->rgb.g = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->sphere->rgb.b = ft_atof(parsed_line);
}

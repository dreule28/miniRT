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
	obj_node->data->plane->material.rgb.r = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->plane->material.rgb.g = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->plane->material.rgb.b = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	normalize_rgb_triplet(&obj_node->data->plane->material.rgb);
	ftm_tup_norm(&obj_node->data->plane->axis, obj_node->data->plane->axis);
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
	obj_node->data->cylinder->radius = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 0);
	skip_spaces_or_value(&parsed_line, 1, 0);
	obj_node->data->cylinder->height = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 0);
	skip_spaces_or_value(&parsed_line, 1, 0);
	obj_node->data->cylinder->material.rgb.r = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->cylinder->material.rgb.g = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->cylinder->material.rgb.b = ft_atof(parsed_line);
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
	obj_node->data->sphere->radius = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 0);
	skip_spaces_or_value(&parsed_line, 1, 0);
	obj_node->data->sphere->material.rgb.r = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->sphere->material.rgb.g = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->sphere->material.rgb.b = ft_atof(parsed_line);
	normalize_rgb_triplet(&obj_node->data->sphere->material.rgb);
}

void	add_cube(t_obj_node *obj_node, char *parsed_line)
{
	skip_spaces_or_value(&parsed_line, 1, 0);
	skip_spaces_or_value(&parsed_line, 0, 0);
	obj_node->data->cube->pos.x = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->cube->pos.y = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->cube->pos.z = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 1, 0);
	obj_node->data->cube->orientation.x = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->cube->orientation.y = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->cube->orientation.z = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 1, 0);
	obj_node->data->cube->scale.x = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->cube->scale.y = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->cube->scale.z = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 1, 0);
	obj_node->data->cube->material.rgb.r = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->cube->material.rgb.g = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->cube->material.rgb.b = ft_atof(parsed_line);
}

void	normalize_rgb_triplet(t_rgb *c)
{
	if (c->r > 1.0 || c->g > 1.0 || c->b > 1.0)
	{
		c->r /= 255.0;
		c->g /= 255.0;
		c->b /= 255.0;
	}
	if (c->r < 0.0)
		c->r = 0.0;
	if (c->r > 1.0)
		c->r = 1.0;
	if (c->g < 0.0)
		c->g = 0.0;
	if (c->g > 1.0)
		c->g = 1.0;
	if (c->b < 0.0)
		c->b = 0.0;
	if (c->b > 1.0)
		c->b = 1.0;
}

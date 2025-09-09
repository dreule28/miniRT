/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_triangles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:58:58 by dreule            #+#    #+#             */
/*   Updated: 2025/09/09 14:58:59 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	init_rgb(&triangle->material.rgb, 0, 0, 0);
	return (triangle);
}

void	add_triangle(t_obj_node *obj_node, char *parsed_line)
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
	obj_node->data->triangle->material.rgb.r = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->triangle->material.rgb.g = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	obj_node->data->triangle->material.rgb.b = ft_atof(parsed_line);
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
	add_triangle(new_node, parsed_line);
	normalize_rgb_triplet(&new_node->data->triangle->material.rgb);
	ftm_tup_subtract(&new_node->data->triangle->e1,
		new_node->data->triangle->p2, new_node->data->triangle->p1);
	ftm_tup_subtract(&new_node->data->triangle->e2,
		new_node->data->triangle->p3, new_node->data->triangle->p1);
	ftm_tup_cross(&new_node->data->triangle->normal,
		new_node->data->triangle->e2, new_node->data->triangle->e1);
	ftm_tup_norm(&new_node->data->triangle->normal,
		new_node->data->triangle->normal);
}

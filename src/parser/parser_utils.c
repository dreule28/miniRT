/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:59:03 by dreule            #+#    #+#             */
/*   Updated: 2025/09/09 14:59:04 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	search_for_bonus_objects(t_scene *scene, char *parsed_line,
		t_obj_node *new_node)
{
	if (!ft_strncmp(parsed_line, "cb", 2))
	{
		new_node = add_obj_node(scene->obj_list, CUBE);
		add_cube(new_node, parsed_line);
		normalize_rgb_triplet(&new_node->data->cube->material.rgb);
	}
	if (!ft_strncmp(parsed_line, "tr", 2))
		handle_triangle(scene, new_node, parsed_line);
	if (!ft_strncmp(parsed_line, "co", 2))
	{
		new_node = add_obj_node(scene->obj_list, CONE);
		add_cone(new_node, parsed_line);
		normalize_rgb_triplet(&new_node->data->cone->material.rgb);
		ftm_tup_norm(&new_node->data->cone->axis, new_node->data->cone->axis);
	}
}

void	rotate_cube_x(t_obj_node *cube)
{
	t_tuples	pos;
	t_tuples	axis;
	t_tuples	scale;
	t_m4		product;

	pos = cube->data->cube->pos;
	axis = cube->data->cube->orientation;
	scale = cube->data->cube->scale;
	ftm_matrix_mult(&product, ftm_translation(pos),
		ftm_rotate_z(radians(axis.z * 90)));
	ftm_matrix_mult(&cube->matrix, product, ftm_scaling(scale));
}

void	rotate_cube_y(t_obj_node *cube)
{
	t_tuples	pos;
	t_tuples	axis;
	t_tuples	scale;
	t_m4		product;

	pos = cube->data->cube->pos;
	axis = cube->data->cube->orientation;
	scale = cube->data->cube->scale;
	ftm_matrix_mult(&product, ftm_translation(pos),
		ftm_rotate_y(radians(axis.y * 90)));
	ftm_matrix_mult(&cube->matrix, product, ftm_scaling(scale));
}

void	rotate_cube_z(t_obj_node *cube)
{
	t_tuples	pos;
	t_tuples	axis;
	t_tuples	scale;
	t_m4		product;

	pos = cube->data->cube->pos;
	axis = cube->data->cube->orientation;
	scale = cube->data->cube->scale;
	ftm_matrix_mult(&product, ftm_translation(pos),
		ftm_rotate_x(radians(axis.x * 90)));
	ftm_matrix_mult(&cube->matrix, product, ftm_scaling(scale));
}

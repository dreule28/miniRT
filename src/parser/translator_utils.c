/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:59:08 by dreule            #+#    #+#             */
/*   Updated: 2025/09/09 14:59:09 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	handle_cyl_axis_x(t_tuples axis, t_tuples pos, t_obj_node *cylinder)
{
	t_m4		product;
	double		height;
	double		radius;
	t_tuples	point;

	height = cylinder->data->cylinder->height / 2;
	radius = cylinder->data->cylinder->radius;
	init_point(&point, radius, height, radius);
	ftm_matrix_mult(&product, ftm_translation(pos),
		ftm_rotate_z(radians(axis.x * 90)));
	ftm_matrix_mult(&cylinder->matrix, product, ftm_scaling(point));
}

void	handle_cyl_axis_y(t_tuples axis, t_tuples pos, t_obj_node *cylinder)
{
	t_m4		product;
	double		height;
	double		radius;
	t_tuples	point;

	height = cylinder->data->cylinder->height / 2;
	radius = cylinder->data->cylinder->radius;
	init_point(&point, radius, height, radius);
	ftm_matrix_mult(&product, ftm_translation(pos),
		ftm_rotate_y(radians(axis.y * 90)));
	ftm_matrix_mult(&cylinder->matrix, product, ftm_scaling(point));
}

void	handle_cyl_axis_z(t_tuples axis, t_tuples pos, t_obj_node *cylinder)
{
	t_m4		product;
	double		height;
	double		radius;
	t_tuples	point;

	height = cylinder->data->cylinder->height / 2;
	radius = cylinder->data->cylinder->radius;
	init_point(&point, radius, height, radius);
	ftm_matrix_mult(&product, ftm_translation(pos),
		ftm_rotate_x(radians(axis.z * 90)));
	ftm_matrix_mult(&cylinder->matrix, product, ftm_scaling(point));
}

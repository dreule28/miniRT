/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:59:06 by dreule            #+#    #+#             */
/*   Updated: 2025/09/09 14:59:07 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	handle_cone_axis_x(t_tuples axis, t_tuples pos, t_obj_node *cone)
{
	t_m4		product;
	double		height;
	double		radius;
	t_tuples	point;

	height = cone->data->cone->height / 2;
	radius = cone->data->cone->radius;
	init_point(&point, radius, height, radius);
	ftm_matrix_mult(&product, ftm_translation(pos),
		ftm_rotate_x(radians(axis.x * 90)));
	ftm_matrix_mult(&cone->matrix, product, ftm_scaling(point));
}

void	handle_cone_axis_y(t_tuples axis, t_tuples pos, t_obj_node *cone)
{
	t_m4		product;
	double		height;
	double		radius;
	t_tuples	point;

	height = cone->data->cone->height / 2;
	radius = cone->data->cone->radius;
	init_point(&point, radius, height, radius);
	ftm_matrix_mult(&product, ftm_translation(pos),
		ftm_rotate_y(radians(axis.y * 90)));
	ftm_matrix_mult(&cone->matrix, product, ftm_scaling(point));
}

void	handle_cone_axis_z(t_tuples axis, t_tuples pos, t_obj_node *cone)
{
	t_m4		product;
	double		height;
	double		radius;
	t_tuples	point;

	height = cone->data->cone->height / 2;
	radius = cone->data->cone->radius;
	init_point(&point, radius, height, radius);
	ftm_matrix_mult(&product, ftm_translation(pos),
		ftm_rotate_z(radians(axis.z * 90)));
	ftm_matrix_mult(&cone->matrix, product, ftm_scaling(point));
}

void	translate_cone(t_obj_node *cone)
{
	t_tuples	pos;
	t_tuples	axis;
	t_tuples	point;

	pos = cone->data->cone->pos;
	axis = cone->data->cone->axis;
	init_point(&point, cone->data->cone->radius,
		cone->data->cone->height / 2, cone->data->cone->radius);
	if (axis.x != 0)
		handle_cyl_axis_x(axis, pos, cone);
	else if (axis.y != 0)
		handle_cyl_axis_y(axis, pos, cone);
	else if (axis.z != 0)
		handle_cyl_axis_z(axis, pos, cone);
	else
		ftm_matrix_mult(&cone->matrix, ftm_translation(pos),
			ftm_scaling(point));
	cone->data->cone->maximum = 1;
	cone->data->cone->minimum = -1;
	cone->data->cone->closed = true;
	init_point(&pos, 0, 0, 0);
}

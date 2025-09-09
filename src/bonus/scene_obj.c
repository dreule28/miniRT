/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:57:53 by dreule            #+#    #+#             */
/*   Updated: 2025/09/09 14:57:54 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	s1_sphere(t_scene *scene)
{
	t_rgb		col1;
	t_rgb		col2;
	t_tuples	point1;
	t_tuples	point2;
	t_obj_node	*s1;

	s1 = scene->obj_list->head->next->next->next;
	init_rgb(&col1, 140, 16, 7);
	normalize_rgb_triplet(&col1);
	init_rgb(&col2, 255, 240, 196);
	normalize_rgb_triplet(&col2);
	init_point(&point1, 1, 1, 1);
	init_point(&point2, 2, 2, 2);
	s1->data->sphere->material.diffuse = 0.7;
	s1->data->sphere->material.specular = 0.5;
	s1->data->sphere->material.ambient = 0.2;
	s1->data->sphere->material.reflective = 0.025;
	gradient_pattern(&s1->data->sphere->material.pattern, col1, col2);
	ftm_matrix_mult(&s1->data->sphere->material.pattern.transform,
		ftm_translation(point1), ftm_scaling(point2));
}

void	s2_sphere(t_scene *scene)
{
	t_rgb		col1;
	t_rgb		col2;
	t_tuples	point1;
	t_tuples	point2;
	t_obj_node	*s2;

	s2 = scene->obj_list->head->next->next->next->next;
	init_rgb(&col1, 140, 16, 7);
	normalize_rgb_triplet(&col1);
	init_rgb(&col2, 255, 240, 196);
	normalize_rgb_triplet(&col2);
	init_point(&point1, 1, 1, 1);
	init_point(&point2, 0.01, 0.01, 0.01);
	s2->data->sphere->material.diffuse = 0.7;
	s2->data->sphere->material.specular = 0.5;
	s2->data->sphere->material.ambient = 0.2;
	s2->data->sphere->material.reflective = 0.1;
	ring_pattern(&s2->data->sphere->material.pattern, col1, col2);
	ftm_matrix_mult(&s2->data->sphere->material.pattern.transform,
		ftm_translation(point1), ftm_scaling(point2));
}

void	s3_sphere(t_scene *scene)
{
	t_rgb		col1;
	t_rgb		col2;
	t_tuples	point1;
	t_tuples	point2;
	t_obj_node	*s3;

	s3 = scene->obj_list->head->next->next->next->next->next;
	init_rgb(&col1, 140, 16, 7);
	normalize_rgb_triplet(&col1);
	init_rgb(&col2, 255, 240, 196);
	normalize_rgb_triplet(&col2);
	init_point(&point1, 0.33, 0.33, 0.33);
	init_point(&point2, 0.1, 0.1, 0.1);
	s3->data->sphere->material.diffuse = 0.7;
	s3->data->sphere->material.specular = 0.3;
	s3->data->sphere->material.ambient = 0.1;
	s3->data->sphere->material.reflective = 0.1;
	ring_pattern(&s3->data->sphere->material.pattern, col1, col2);
	ftm_matrix_mult(&s3->data->sphere->material.pattern.transform,
		ftm_translation(point1), ftm_scaling(point2));
}

void	p1_plane(t_scene *scene)
{
	t_rgb		col1;
	t_rgb		col2;
	t_tuples	point1;
	t_tuples	point2;
	t_obj_node	*p1;

	p1 = scene->obj_list->head;
	init_rgb(&col1, 140, 16, 7);
	normalize_rgb_triplet(&col1);
	init_rgb(&col2, 255, 240, 196);
	normalize_rgb_triplet(&col2);
	init_point(&point1, 3, -1, 0);
	init_point(&point2, 1, 1, 1);
	p1->data->plane->material.ambient = 0.2;
	p1->data->plane->material.diffuse = 0.8;
	p1->data->plane->material.specular = 0.1;
	p1->data->plane->material.shininess = 10.0;
	p1->data->plane->material.reflective = 0.1;
	checkers_pattern(&p1->data->plane->material.pattern, col1, col2);
	ftm_matrix_mult(&p1->data->plane->material.pattern.transform,
		ftm_translation(point1), ftm_scaling(point2));
}

void	p2_plane(t_scene *scene)
{
	t_obj_node	*p2;
	t_tuples	t;
	t_tuples	s;

	p2 = scene->obj_list->head->next;
	p2->data->plane->material.ambient = 0.2;
	p2->data->plane->material.diffuse = 0.8;
	p2->data->plane->material.specular = 0.1;
	p2->data->plane->material.reflective = 0.0;
	p2->data->plane->material.shininess = 1.0;
	p2->data->plane->material.bump.has_bump = true;
	p2->data->plane->material.bump.type = QUILT_BUMP;
	p2->data->plane->material.bump.amplitude = 0.3;
	init_point(&t, 0, 0, 0);
	init_point(&s, 1, 1, 1);
	ftm_matrix_mult(&p2->data->plane->material.bump.transform,
		ftm_translation(t), ftm_scaling(s));
}

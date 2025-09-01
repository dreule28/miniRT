#include "mini_rt.h"

void	p3_plane(t_scene *scene)
{
	t_obj_node	*p3;

	p3 = scene->obj_list->head->next->next;
	p3->data->plane->material.ambient = 0.2;
	p3->data->plane->material.diffuse = 0.8;
	p3->data->plane->material.specular = 0.1;
	p3->data->plane->material.reflective = 0.0;
}

void	c1_cylinder(t_scene *scene)
{
	t_rgb		col1;
	t_rgb		col2;
	t_tuples	point1;
	t_tuples	point2;
	t_obj_node	*c1;

	c1 = scene->obj_list->head->next->next->next->next->next->next;
	init_rgb(&col1, 62, 7, 3);
	normalize_rgb_triplet(&col1);
	init_rgb(&col2, 255, 240, 196);
	normalize_rgb_triplet(&col2);
	init_point(&point1, 3, -1, 0);
	init_point(&point2, 0.1, 0.1, 0.1);
	c1->data->cylinder->material.ambient = 0.2;
	c1->data->cylinder->material.diffuse = 0.8;
	c1->data->cylinder->material.specular = 0.1;
	c1->data->cylinder->material.reflective = 0.1;
	c1->data->cylinder->minimum = 1;
	c1->data->cylinder->maximum = 5;
	c1->data->cylinder->closed = false;
	ring_pattern(&c1->data->cylinder->material.pattern, col1, col2);
	ftm_matrix_mult(&c1->data->cylinder->material.pattern.transform,
		ftm_translation(point1), ftm_scaling(point2));
}

void	c1_cube(t_scene *scene)
{
	t_rgb		col1;
	t_rgb		col2;
	t_tuples	point1;
	t_tuples	point2;
	t_obj_node	*c1;

	c1 = scene->obj_list->head->next->next->next->next->next->next->next;
	init_rgb(&col1, 140, 16, 7);
	normalize_rgb_triplet(&col1);
	init_rgb(&col2, 255, 240, 196);
	normalize_rgb_triplet(&col2);
	init_point(&point1, 3, -1, 0);
	init_point(&point2, 1, 1, 1);
	c1->data->cube->material.ambient = 0.2;
	c1->data->cube->material.diffuse = 0.8;
	c1->data->cube->material.specular = 0.1;
	c1->data->cube->material.reflective = 0.1;
	checkers_pattern(&c1->data->cube->material.pattern, col1, col2);
	ftm_matrix_mult(&c1->data->cube->material.pattern.transform,
		ftm_translation(point1), ftm_scaling(point2));
}

void	c1_cone(t_scene *scene)
{
	t_rgb		col1;
	t_rgb		col2;
	t_tuples	point1;
	t_tuples	point2;
	t_obj_node	*co1;

	co1 = scene->obj_list->tail;
	init_rgb(&col1, 62, 7, 3);
	normalize_rgb_triplet(&col1);
	init_rgb(&col2, 255, 240, 196);
	normalize_rgb_triplet(&col2);
	init_point(&point1,0, 0, 0);
	init_point(&point2, 1, 1, 1);
	co1->data->cone->material.ambient = 0.2;
	co1->data->cone->material.diffuse = 0.8;
	co1->data->cone->material.specular = 0.1;
	co1->data->cone->material.reflective = 0.1;
	co1->data->cone->minimum = 1;
	co1->data->cone->maximum = 5;
	co1->data->cone->closed = false;
	ring_pattern(&co1->data->cone->material.pattern, col1, col2);
	ftm_matrix_mult(&co1->data->cone->material.pattern.transform,
		ftm_translation(point1), ftm_scaling(point2));
}

#include "mini_rt.h"

void	s1_sphere(t_scene *scene)
{
	t_rgb	col1;
	t_rgb	col2;
	t_tuples	point1;
	t_tuples	point2;
	t_obj_node 	*s1;

	s1 = scene->obj_list->head->next->next->next;
	init_rgb(&col1, 140, 16, 7);
	normalize_rgb_triplet(&col1);
	init_rgb(&col2, 255, 240, 196);
	normalize_rgb_triplet(&col2);
	init_point(&point1,1,1,1);
	init_point(&point2, 2, 2, 2);
    s1->data->sphere->material.diffuse = 0.7;
    s1->data->sphere->material.specular = 0.1;
    s1->data->sphere->material.ambient = 0.2;
	s1->data->sphere->material.reflective= 0.0;
	gradient_pattern(&s1->data->sphere->material.pattern, col1, col2);
	ftm_matrix_mult(&s1->data->sphere->material.pattern.transform, ftm_translation(point1), ftm_scaling(point2));
}

void	s2_sphere(t_scene *scene)
{
	t_rgb	col1;
	t_rgb	col2;
	t_tuples	point1;
	t_tuples	point2;
	t_obj_node 	*s2;

	s2 = scene->obj_list->head->next->next->next->next;
	init_rgb(&col1, 0.8, 1, 0.2);
	init_rgb(&col2, 0.2, 0.3, 0.6);
	init_point(&point1, 0.33, 0.33, 0.33);
	init_point(&point2, 1, 1, 1);
    s2->data->sphere->material.diffuse = 0.7;
    s2->data->sphere->material.specular = 0.1;
    s2->data->sphere->material.ambient = 0.2;
	s2->data->sphere->material.reflective= 0.1;
	stripe_pattern(&s2->data->sphere->material.pattern, col1, col2);
	ftm_matrix_mult(&s2->data->sphere->material.pattern.transform, ftm_translation(point1), ftm_scaling(point2));
}

void	s3_sphere(t_scene *scene)
{
	t_rgb	col1;
	t_rgb	col2;
	t_tuples	point1;
	t_tuples	point2;
	t_obj_node 	*s3;

	s3 = scene->obj_list->head->next->next->next->next->next;
	init_rgb(&col1, 0.8, 1, 0.2);
	init_rgb(&col2, 0.2, 0.3, 0.6);
	init_point(&point1, 0.33, 0.33, 0.33);
	init_point(&point2, 0.1, 0.1, 0.1);
	s3->data->sphere->material.diffuse = 0.7;
	s3->data->sphere->material.specular = 0.3;
	s3->data->sphere->material.ambient = 0.1;
	s3->data->sphere->material.reflective= 0.3;
	ring_pattern(&s3->data->sphere->material.pattern, col1, col2);
	ftm_matrix_mult(&s3->data->sphere->material.pattern.transform, ftm_translation(point1), ftm_scaling(point2));
}

void	p1_plane(t_scene *scene)
{
	t_rgb	col1;
	t_rgb	col2;
	t_tuples	point1;
	t_tuples	point2;
	t_obj_node 	*p1;

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
	p1->data->plane->material.reflective= 0.1;
	checkers_pattern(&p1->data->plane->material.pattern, col1, col2);
	ftm_matrix_mult(&p1->data->plane->material.pattern.transform, ftm_translation(point1), ftm_scaling(point2));
}

void	p2_plane(t_scene *scene)
{
	t_obj_node 	*p2;

	p2 = scene->obj_list->head->next;
    p2->data->plane->material.ambient = 0.2;
    p2->data->plane->material.diffuse = 0.8;
    p2->data->plane->material.specular = 0.1;
	p2->data->plane->material.reflective= 0.0;
    p2->data->plane->material.shininess = 1.0;
}

void	p3_plane(t_scene *scene)
{
	t_obj_node 	*p3;

	p3 = scene->obj_list->head->next->next;
	p3->data->plane->material.ambient = 0.2;
    p3->data->plane->material.diffuse = 0.8;
    p3->data->plane->material.specular = 0.1;
    p3->data->plane->material.reflective= 0.0;
}

void	c1_cylinder(t_scene *scene)
{
	t_rgb	col1;
	t_rgb	col2;
	t_tuples	point1;
	t_tuples	point2;
	t_obj_node 	*c1;

	c1 = scene->obj_list->head->next->next->next->next->next->next;
	init_rgb(&col1, 62, 7, 3);
	normalize_rgb_triplet(&col1);
	init_rgb(&col2, 255, 240, 196);
	normalize_rgb_triplet(&col2);
	init_point(&point1, 3, -1, 0);
	init_point(&point2, 1, 1, 1);
	c1->data->cylinder->material.ambient = 0.2;
    c1->data->cylinder->material.diffuse = 0.8;
    c1->data->cylinder->material.specular = 0.1;
    c1->data->cylinder->material.reflective= 0.2;
	c1->data->cylinder->minimum = 1;
	c1->data->cylinder->maximum = 5;
	c1->data->cylinder->closed = false;
	ring_pattern(&c1->data->cylinder->material.pattern, col1, col2);
	ftm_matrix_mult(&c1->data->cylinder->material.pattern.transform, ftm_translation(point1), ftm_scaling(point2));
}

void	c1_cube(t_scene *scene)
{
	t_rgb	col1;
	t_rgb	col2;
	t_tuples	point1;
	t_tuples	point2;
	t_obj_node 	*c1;

	c1 = scene->obj_list->tail;
	init_rgb(&col1, 0, 1, 0);
	init_rgb(&col2, 1, 0, 0);
	init_point(&point1, 3, -1, 0);
	init_point(&point2, 2, 2, 2);
	c1->data->cube->material.ambient = 0.2;
    c1->data->cube->material.diffuse = 0.8;
    c1->data->cube->material.specular = 0.1;
    c1->data->cube->material.reflective= 0.2;
	gradient_pattern(&c1->data->cube->material.pattern, col1, col2);
	ftm_matrix_mult(&c1->data->cube->material.pattern.transform, ftm_translation(point1), ftm_scaling(point2));
}
void bonus_scene(t_scene *scene)
{
	s1_sphere(scene);
	s2_sphere(scene);
	s3_sphere(scene);
	p1_plane(scene);
	p2_plane(scene);
	p3_plane(scene);
	c1_cylinder(scene);
	c1_cube(scene);
}

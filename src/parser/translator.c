#include "mini_rt.h"

void	translate_plane(t_obj_node *plane)
{
	t_tuples pos;
	t_tuples axis;

	pos = plane->data->plane->pos;
	axis = plane->data->plane->axis;
	if(!check_norm_vec(&axis))
		return ;
	if (axis.z != 0)
		plane->matrix = ftm_matrix_mult(ftm_translation(&pos),
						ftm_rotate_x(radians(axis.z * 90)));
	else if (axis.y != 0)
		plane->matrix = ftm_matrix_mult(ftm_translation(&pos),
						ftm_rotate_y(radians(axis.y * 90)));
	else if (axis.x != 0)
		plane->matrix = ftm_matrix_mult(ftm_translation(&pos),
						ftm_rotate_z(radians(-axis.x * 90)));
	else
		plane->matrix = ftm_translation(&pos);
	plane->data->plane->pos = *init_point(0, 0, 0);
	plane->data->plane->axis = *init_vector(0, 0, 0);
}

void	translate_cylinder(t_obj_node *cylinder)
{
	t_tuples	pos;
	t_tuples	axis;
	double		height;
	double		radius;

	pos = cylinder->data->cylinder->pos;
	axis = cylinder->data->cylinder->axis;
	height = cylinder->data->cylinder->height / 2;
	radius = cylinder->data->cylinder->radius;
	if (axis.x != 0)
		cylinder->matrix = ftm_matrix_mult(ftm_matrix_mult(
							ftm_translation(&pos), ftm_rotate_z(radians(90))),
							ftm_scaling(init_point(radius, height, radius)));
	else if (axis.y != 0)
		cylinder->matrix = ftm_matrix_mult(ftm_matrix_mult(
							ftm_translation(&pos), ftm_rotate_y(radians(90))),
							ftm_scaling(init_point(radius, height, radius)));
	else if (axis.z != 0)
		cylinder->matrix = ftm_matrix_mult(ftm_matrix_mult(
							ftm_translation(&pos), ftm_rotate_x(radians(90))),
							ftm_scaling(init_point(radius, height, radius)));
	else
		cylinder->matrix = ftm_matrix_mult(ftm_translation(&pos),
						ftm_scaling(init_point(radius, height, radius)));
	cylinder->data->cylinder->maximum = 1;
	cylinder->data->cylinder->minimum = -1;
	cylinder->data->cylinder->closed = true;
	cylinder->data->cylinder->pos = *init_point(0, 0, 0);
}


void	translate_cube(t_obj_node *cube)
{
	t_tuples	pos;
	t_tuples	axis;
	t_tuples	scale;

	pos = cube->data->cube->pos;
	axis = cube->data->cube->orientation;
	scale = cube->data->cube->scale;
	if (axis.x != 0)
		cube->matrix = ftm_matrix_mult(ftm_matrix_mult(ftm_translation(&pos),
						ftm_rotate_x(radians(axis.x * 90))),
						ftm_scaling(init_point(scale.x, scale.y, scale.z)));
	else if (axis.y != 0)
		cube->matrix = ftm_matrix_mult(ftm_matrix_mult(ftm_translation(&pos),
						ftm_rotate_y(radians(axis.y * 90))),
						ftm_scaling(init_point(scale.x, scale.y, scale.z)));
	else if (axis.z != 0)
		cube->matrix = ftm_matrix_mult(ftm_matrix_mult(ftm_translation(&pos),
						ftm_rotate_z(radians(axis.z * 90))),
						ftm_scaling(init_point(scale.x, scale.y, scale.z)));
	else
		cube->matrix = ftm_matrix_mult(ftm_translation(&pos),
						ftm_scaling(init_point(scale.x, scale.y, scale.z)));
	cube->data->cube->scale = *init_point(1, 1, 1);
}

void	translate_objs(t_scene *scene)
{
	t_obj_node	*curr;

	curr = scene->obj_list->head;
	translate_camera(scene->camera);
	while (curr)
	{
		if (curr->type == SPHERE)
			translate_sphere(curr);
		else if (curr->type == PLANE)
			translate_plane(curr);
		else if (curr->type == CYLINDER)
			translate_cylinder(curr);
		else if (curr->type == CUBE)
			translate_cube(curr);
		curr = curr->next;
	}
}

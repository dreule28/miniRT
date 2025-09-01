#include "mini_rt.h"

void	translate_sphere(t_obj_node *sphere)
{
	t_tuples	pos;
	t_tuples	scalar;
	double		radius;

	pos = sphere->data->sphere->pos;
	radius = sphere->data->sphere->radius;
	init_point(&scalar, radius, radius, radius);
	ftm_matrix_mult(&sphere->matrix, ftm_translation(pos), ftm_scaling(scalar));
	init_point(&sphere->data->sphere->pos, 0, 0, 0);
	sphere->data->sphere->radius = 1.0;
}

void	translate_plane(t_obj_node *plane)
{
	t_tuples	pos;
	t_tuples	axis;

	pos = plane->data->plane->pos;
	axis = plane->data->plane->axis;
	if (axis.x != 0)
		ftm_matrix_mult(&plane->matrix, ftm_translation(pos),
						ftm_rotate_x(radians(axis.x * 90)));
	else if (axis.y != 0)
		ftm_matrix_mult(&plane->matrix, ftm_translation(pos),
						ftm_rotate_y(radians(axis.y * 90)));
	else if (axis.z != 0)
		ftm_matrix_mult(&plane->matrix, ftm_translation(pos),
						ftm_rotate_z(radians(axis.z * 90)));
	else
		plane->matrix = ftm_translation(pos);
	init_point(&plane->data->plane->pos, 0, 0, 0);
	init_vector(&plane->data->plane->axis, 0, 0, 0);
}

void	translate_cylinder(t_obj_node *cylinder)
{
	t_tuples	pos;
	t_tuples	axis;
	t_tuples	point;

	pos = cylinder->data->cylinder->pos;
	axis = cylinder->data->cylinder->axis;
	init_point(&point, cylinder->data->cylinder->radius,
		cylinder->data->cylinder->height / 2, cylinder->data->cylinder->radius);
	if (axis.x != 0)
		handle_cyl_axis_x(axis, pos, cylinder);
	else if (axis.y != 0)
		handle_cyl_axis_y(axis, pos, cylinder);
	else if (axis.z != 0)
		handle_cyl_axis_z(axis, pos, cylinder);
	else
		ftm_matrix_mult(&cylinder->matrix, ftm_translation(pos),
			ftm_scaling(point));
	cylinder->data->cylinder->maximum = 1;
	cylinder->data->cylinder->minimum = -1;
	cylinder->data->cylinder->closed = true;
	init_point(&pos, 0, 0, 0);
}

void	translate_cube(t_obj_node *cube)
{
	t_tuples	pos;
	t_tuples	axis;
	t_tuples	scale;
	t_m4		product;

	pos = cube->data->cube->pos;
	axis = cube->data->cube->orientation;
	scale = cube->data->cube->scale;
	if (axis.x != 0)
	{
		ftm_matrix_mult(&product, ftm_translation(pos),
			ftm_rotate_x(radians(axis.x * 90)));
		ftm_matrix_mult(&cube->matrix, product, ftm_scaling(scale));
	}
	else if (axis.y != 0)
	{
		ftm_matrix_mult(&product, ftm_translation(pos),
			ftm_rotate_x(radians(axis.y * 90)));
		ftm_matrix_mult(&cube->matrix, product, ftm_scaling(scale));
	}
	else if (axis.z != 0)
	{
		ftm_matrix_mult(&product, ftm_translation(pos),
			ftm_rotate_x(radians(axis.z * 90)));
		ftm_matrix_mult(&cube->matrix, product, ftm_scaling(scale));
	}
	else
		ftm_matrix_mult(&cube->matrix, ftm_translation(pos), ftm_scaling(scale));
	init_point(&cube->data->cube->scale, 1, 1, 1);
}

void	translate_objs(t_scene *scene)
{
	t_obj_node	*curr;

	curr = scene->obj_list->head;
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
		else if (curr->type == CONE)
			translate_cone(curr);
		curr = curr->next;
	}
}

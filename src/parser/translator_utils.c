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
		ftm_rotate_x(radians(axis.x * 90)));
	ftm_matrix_mult(&cylinder->matrix, product,ftm_scaling(point));
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
	ftm_matrix_mult(&cylinder->matrix, product,ftm_scaling(point));
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
		ftm_rotate_z(radians(axis.z * 90)));
	ftm_matrix_mult(&cylinder->matrix, product,ftm_scaling(point));
}

#include "mini_rt.h"

bool	check_norm_vec(t_tuples *vec)
{
	double	mag;

	mag = magnitude_vector(vec);
	if (mag != 1)
	{
		printf("Error\nOrientation components must be in [-1,1]\n");
		return (false);
	}
	return (true);
}

void	translate_sphere(t_obj_node *sphere)
{
	t_tuples	pos;
	double		radius;

	pos = sphere->data->sphere->pos;
	radius = sphere->data->sphere->radius;
	sphere->matrix = ftm_matrix_mult(ftm_translation(&pos),
			ftm_scaling(init_point(radius, radius, radius)));
	sphere->data->sphere->pos = *init_point(0, 0, 0);
	sphere->data->sphere->radius = 1.0;
}

void	translate_camera(t_camera camera)
{
	t_tuples	pos;
	t_tuples	ov;

	pos = camera.pos;
	ov = camera.orientation_vector;
	camera.matrix = view_transformation(&pos, init_point(0, 1, 0), &ov);
}

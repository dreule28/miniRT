/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:59:31 by dreule            #+#    #+#             */
/*   Updated: 2025/09/09 14:59:32 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	calculate_ray_for_pixel(t_ray *ray, t_m4 inv, double world_x,
		double world_y)
{
	t_tuples	origin;
	t_tuples	pixel;
	t_tuples	direction;
	t_tuples	point;

	init_point(&point, world_x, world_y, -1);
	ftm_matrix_times_tuple(&pixel, inv, point);
	init_point(&point, 0, 0, 0);
	ftm_matrix_times_tuple(&origin, inv, point);
	ftm_tup_subtract(&point, pixel, origin);
	ftm_tup_norm(&direction, point);
	init_ray(ray, origin, direction);
}

void	ray_for_pixel(t_ray_params *ray_params, double px, double py)
{
	double	xoffset;
	double	yoffset;
	double	world_x;
	double	world_y;

	xoffset = (px + 0.5) * ray_params->scene.camera.pixel_size;
	yoffset = (py + 0.5) * ray_params->scene.camera.pixel_size;
	world_x = ray_params->scene.camera.half_width - xoffset;
	world_y = ray_params->scene.camera.half_height - yoffset;
	calculate_ray_for_pixel(&ray_params->ray, ray_params->inv, world_x,
		world_y);
}

void	render(t_scene *scene)
{
	t_ray			ray;
	t_m4			inv;
	int				y;
	int				x;
	t_ray_params	ray_params;

	ftm_m4_inversion(&inv, scene->camera.matrix);
	init_ray_params(&ray_params, scene, &ray, inv);
	y = 0;
	while (y < scene->camera.vsize)
	{
		x = 0;
		while (x < scene->camera.hsize)
		{
			if (AA_GRID == 1)
				normal_rendering(&ray_params, x, y);
			else
				anti_aliasing(&ray_params, x, y);
			x++;
		}
		y++;
	}
}

void	init_view_transformation(t_m4 *matrix, t_scene *scene)
{
	t_tuples	from;
	t_tuples	to;
	t_tuples	up;

	init_point(&from, scene->camera.pos.x, scene->camera.pos.y,
		scene->camera.pos.z);
	init_point(&to, scene->camera.pos.x + scene->camera.orientation_vector.x,
		scene->camera.pos.y + scene->camera.orientation_vector.y,
		scene->camera.pos.z + scene->camera.orientation_vector.z);
	init_vector(&up, 0, 1, 0);
	view_transformation(matrix, from, to, up);
}

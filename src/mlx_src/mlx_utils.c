/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:58:47 by dreule            #+#    #+#             */
/*   Updated: 2025/09/09 14:58:48 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

bool	init_mlx_window(t_scene *scene)
{
	scene->mlx = mlx_init(WIDTH, HEIGHT, "miniRT", false);
	if (!scene->mlx)
	{
		printf("Failed to initialize MLX\n");
		return (false);
	}
	scene->img = mlx_new_image(scene->mlx, WIDTH, HEIGHT);
	if (!scene->img)
	{
		printf("Failed to create image\n");
		mlx_terminate(scene->mlx);
		return (false);
	}
	if (mlx_image_to_window(scene->mlx, scene->img, 0, 0) < 0)
	{
		printf("Failed to display image\n");
		mlx_terminate(scene->mlx);
		return (false);
	}
	return (true);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (a << 24 | b << 16 | g << 8 | r);
}

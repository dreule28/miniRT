/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cubes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:58:57 by dreule            #+#    #+#             */
/*   Updated: 2025/09/09 14:58:58 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_cube	*init_cube(void)
{
	t_cube	*cube;

	cube = ft_calloc(sizeof(t_cube), 1);
	if (!cube)
		return (NULL);
	cube->pos.x = 0;
	cube->pos.y = 0;
	cube->pos.z = 0;
	cube->pos.w = 0;
	cube->material.rgb.r = 0;
	cube->material.rgb.g = 0;
	cube->material.rgb.b = 0;
	return (cube);
}

t_obj_data	*init_cube_data(t_obj_data *data)
{
	data->cube = init_cube();
	if (!data->cube)
		return (free(data), NULL);
	data->cube->material = get_material();
	data->cube->material.pattern.has_pattern = false;
	return (data);
}

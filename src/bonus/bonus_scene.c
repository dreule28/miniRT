/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:57:44 by dreule            #+#    #+#             */
/*   Updated: 2025/09/09 14:57:45 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	bonus_scene1(t_scene *scene)
{
	s1_sphere(scene);
	s2_sphere(scene);
	s3_sphere(scene);
	p1_plane(scene);
	p2_plane(scene);
	p3_plane(scene);
	c1_cylinder(scene);
	c1_cube(scene);
	c1_cone(scene);
}

void	bonus_scenes(t_scene *scene, char *str)
{
	if (!ft_strcmp(str, "scenes/bonus1.rt"))
		bonus_scene1(scene);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:57:59 by dreule            #+#    #+#             */
/*   Updated: 2025/09/09 14:58:00 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	bump_quilt(t_tuples *out, double amp, t_tuples p)
{
	double		f;
	t_tuples	s;
	t_tuples	c;

	f = 8.0;
	s.x = sin(f * p.x);
	s.y = sin(f * p.y);
	s.z = sin(f * p.z);
	s.x = sin(f * p.x);
	c.x = cos(f * p.x);
	s.y = sin(f * p.y);
	c.y = cos(f * p.y);
	s.z = sin(f * p.z);
	c.z = cos(f * p.z);
	init_vector(out, amp * s.x * c.y, amp * s.y * c.z, amp * c.x * s.z);
}

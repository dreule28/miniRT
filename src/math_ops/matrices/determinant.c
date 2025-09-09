/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:58:13 by dreule            #+#    #+#             */
/*   Updated: 2025/09/09 14:58:14 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

double	ftm_m_dmt(t_m2 m2)
{
	double	x;
	double	y;
	double	result;

	x = m2.col0.x * m2.col1.y;
	y = m2.col0.y * m2.col1.x;
	result = x - y;
	return (result);
}

double	ftm_m3_dmt(t_m3 m3)
{
	double	result;
	double	x;
	double	y;
	double	z;

	x = m3.col0.x * ftm_m3_cofactor(m3, 0, 0);
	y = m3.col1.x * ftm_m3_cofactor(m3, 1, 0);
	z = m3.col2.x * ftm_m3_cofactor(m3, 2, 0);
	result = x + y + z;
	return (result);
}

double	ftm_m4_dmt(t_m4 m4)
{
	double	result;
	double	x;
	double	y;
	double	z;
	double	w;

	x = m4.col0.x * ftm_m4_cofactor(m4, 0, 0);
	y = m4.col1.x * ftm_m4_cofactor(m4, 1, 0);
	z = m4.col2.x * ftm_m4_cofactor(m4, 2, 0);
	w = m4.col3.x * ftm_m4_cofactor(m4, 3, 0);
	result = x + y + z + w;
	return (result);
}

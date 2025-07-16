/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:14:11 by danielreule       #+#    #+#             */
/*   Updated: 2024/12/16 10:07:58 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	handle_fraction(const char *str, int *i, double *result)
{
	double	fraction;

	if (str[*i] == '.')
	{
		(*i)++;
		fraction = 0.1;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			*result += (str[*i] - '0') * fraction;
			fraction /= 10.0;
			(*i)++;
		}
	}
}

static void	handle_minus(const char *str, int *i, int *min_count)
{
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			(*min_count)++;
		(*i)++;
	}
}

double	ft_atof(const char *str)
{
	int		i;
	int		min_count;
	double	result;

	i = 0;
	min_count = 0;
	result = 0.0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	handle_minus(str, &i, &min_count);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	handle_fraction(str, &i, &result);
	if (min_count % 2 != 0)
		result = -result;
	return (result);
}

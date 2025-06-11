/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:52:55 by dreule            #+#    #+#             */
/*   Updated: 2025/06/11 15:27:48 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_overflow(int result, int digit, int sign)
{
	if (sign == 1)
	{
		if (result > (INT_MAX - digit) / 10)
			return (INT_MAX);
	}
	else
	{
		if (result > (INT_MAX - digit) / 10)
			return (INT_MIN);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	digit;
	int	overflow_check;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		digit = *str - '0';
		overflow_check = check_overflow(result, digit, sign);
		if (overflow_check != 0)
			return (overflow_check);
		result = result * 10 + digit;
		str++;
	}
	return (sign * result);
}

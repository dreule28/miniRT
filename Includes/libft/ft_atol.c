/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:03:15 by dreule            #+#    #+#             */
/*   Updated: 2025/01/28 14:22:56 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (result > (LONG_MAX - (*str - '0' )) / 10)
		{
			if (sign == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		result = result * 10 + *str++ - '0';
	}
	return (sign * result);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main()
// {
// 	printf("%ld\n", ft_atol("12345"));
// 	printf("%ld\n", ft_atol("12345"));
// 	printf("%ld\n", ft_atol("12345"));
//     printf("%ld\n", ft_atol("-6789"));
//     printf("%ld\n", ft_atol("   42"));
//     printf("%ld\n", ft_atol(" +100"));
//     printf("%ld\n", ft_atol(" -100"));
//     printf("%ld\n", ft_atol("999999999999999999999999999999"));
//     printf("%ld\n", ft_atol("-999999999999999999999999999999"));
// 	return (0);
// }
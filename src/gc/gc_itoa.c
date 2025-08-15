/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:42:50 by gzovkic           #+#    #+#             */
/*   Updated: 2025/05/04 11:42:51 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"
#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*handle_zero(int n, char *str)
{
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	return (str);
}

static unsigned int	handle_neg(int n, char *str)
{
	if (n < 0)
	{
		str[0] = '-';
		return (-n);
	}
	return (n);
}

char	*gc_itoa(int n)
{
	int				len;
	char			*str;
	int				i;
	unsigned int	num;

	len = count_digits(n);
	str = ft_malloc(len + 1, 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		return (handle_zero(n, str));
	num = handle_neg(n, str);
	i = len - 1;
	while (num > 0)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	return (str);
}

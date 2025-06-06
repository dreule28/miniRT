/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_un_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:37:16 by dreule            #+#    #+#             */
/*   Updated: 2025/02/04 11:32:33 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(unsigned int n)
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

static char	*handle_zero(unsigned int n, char *str)
{
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	return (str);
}

static unsigned int	handle_neg(unsigned int n)
{
	return (n);
}

char	*unint_itoa(unsigned int n)
{
	int				len;
	char			*str;
	int				i;
	unsigned int	num;

	len = count_digits(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		return (handle_zero(n, str));
	num = handle_neg(n);
	i = len - 1;
	while (num > 0)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	return (str);
}

int	print_un_int(unsigned int n)
{
	char	*str;
	int		res;

	str = unint_itoa(n);
	if (str == NULL)
		return (-1);
	res = ft_putstr_print_itoa(str);
	if (res == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (res);
}

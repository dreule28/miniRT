/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_low.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:04:55 by dreule            #+#    #+#             */
/*   Updated: 2024/10/25 13:36:08 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	to_hex(unsigned int nb)
{
	char	*hex;
	int		counter;
	int		ret;

	counter = 0;
	hex = "0123456789abcdef";
	if (nb == 0)
	{
		if (write (1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	if (nb >= 16)
	{
		ret = to_hex(nb / 16);
		if (ret == -1)
			return (-1);
		counter += ret;
	}
	if (write(1, &hex[nb % 16], 1) == -1)
		return (-1);
	counter += 1;
	return (counter);
}

int	print_low(unsigned long nb)
{
	int		counter;

	counter = to_hex(nb);
	if (counter == -1)
		return (-1);
	return (counter);
}

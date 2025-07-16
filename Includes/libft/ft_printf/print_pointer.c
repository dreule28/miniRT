/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:37:40 by dreule            #+#    #+#             */
/*   Updated: 2024/10/25 18:47:10 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	to_hex(unsigned long nb)
{
	char	*hex;
	int		counter;
	int		res;

	counter = 0;
	hex = "0123456789abcdef";
	if (nb >= 16)
	{
		res = to_hex(nb / 16);
		if (res == -1)
			return (-1);
		counter += res;
	}
	res = write(1, &hex[nb % 16], 1);
	if (res == -1)
		return (-1);
	return (counter + 1);
}

int	print_pointer(void *ptr)
{
	unsigned long	nb;
	int				res;
	int				ptr_len;

	nb = (unsigned long)ptr;
	if (nb == 0)
		return (print_str("0x0"));
	res = print_str("0x");
	if (res == -1)
		return (-1);
	ptr_len = res;
	res = to_hex(nb);
	if (res == -1)
		return (-1);
	return (ptr_len + res);
}

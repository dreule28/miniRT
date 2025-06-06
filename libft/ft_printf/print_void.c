/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_void.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:46:00 by dreule            #+#    #+#             */
/*   Updated: 2024/11/26 09:07:45 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

static void	to_hex(unsigned long nb, int fd)
{
	if (nb >= 16)
		to_hex(nb / 16, fd);
	ft_putchar_fd("0123456789abcdef"[nb % 16], fd);
}

int	print_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
	return (i);
}

int	print_void(const void *ptr, int fd)
{
	unsigned long	nb;
	int				ptr_len;
	unsigned long	temp;

	nb = (unsigned long)ptr;
	ptr_len = 0;
	if (nb == 0)
		return (print_putstr_fd("0x0", fd));
	ptr_len += print_putstr_fd("0x", fd);
	to_hex(nb, fd);
	temp = nb;
	while (temp > 0)
	{
		temp /= 16;
		ptr_len++;
	}
	return (ptr_len);
}

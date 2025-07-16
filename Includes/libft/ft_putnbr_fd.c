/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:27:33 by dreule            #+#    #+#             */
/*   Updated: 2024/10/18 19:15:36 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	handle_intmin(int fd)
{
	write (fd, "-2147483648", 11);
}

static void	handle_neg_putnbr(int *n, int fd)
{
	if (*n < 0)
	{
		write (fd, "-", 1);
		*n = -(*n);
		return ;
	}
	return ;
}

static void	handle_zero_putnbr(int fd)
{
	write (fd, "0", 1);
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	char			str[11];
	int				len;
	unsigned int	num;

	if (n == -2147483648)
		return (handle_intmin(fd));
	if (n == 0)
		return (handle_zero_putnbr(fd));
	if (n < 0)
		handle_neg_putnbr(&n, fd);
	num = n;
	len = 0;
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	str[len] = '\0';
	num = n;
	while (len > 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	write (fd, str, ft_strlen(str));
}

//TODO:
// int main(void)
// {
// 	;
// }
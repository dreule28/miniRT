/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:39:51 by dreule            #+#    #+#             */
/*   Updated: 2024/10/25 18:50:31 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	cases(const char *format, int i, va_list args)
{
	if (format[i] == 'c')
		return (print_char((char)va_arg(args, int)));
	else if (format[i] == 's')
		return (print_str(va_arg(args, char *)));
	else if (format[i] == 'p')
		return (print_pointer(va_arg(args, void *)));
	else if (format[i] == 'i' || format[i] == 'd')
		return (print_inti(va_arg(args, int)));
	else if (format[i] == 'u')
		return (print_un_int(va_arg(args, unsigned int)));
	else if (format[i] == 'x')
		return (print_low(va_arg(args, unsigned long)));
	else if (format[i] == 'X')
		return (print_upp(va_arg(args, long)));
	else if (format[i] == '%')
		return (print_percenti());
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len_now;
	int		len_end;

	i = 0;
	len_now = 0;
	len_end = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			len_now = cases(format, i, args);
		}
		else
			len_now = print_char(format[i]);
		if (len_now == -1)
			return (-1);
		i++;
		len_end += len_now;
	}
	va_end(args);
	return (len_end);
}

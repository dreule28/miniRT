/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:45:42 by dreule            #+#    #+#             */
/*   Updated: 2024/11/26 09:06:08 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int n)
{
	char	*str;
	size_t	len;
	int		fd;

	str = ft_itoa(n);
	len = ft_strlen_print(str);
	ft_putstr_fd(str, fd);
	free(str);
	return (len);
}

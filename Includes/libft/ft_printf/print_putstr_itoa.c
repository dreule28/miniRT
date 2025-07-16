/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_print_itoa.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:18:07 by dreule            #+#    #+#             */
/*   Updated: 2024/10/25 20:23:03 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_print_itoa(char *s)
{
	int	i;
	int	res;

	i = 0;
	while (s[i] != '\0')
	{
		res = write (1, &s[i], 1);
		if (res == -1)
			return (-1);
		i++;
	}
	return (i);
}

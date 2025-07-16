/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:45:42 by dreule            #+#    #+#             */
/*   Updated: 2024/11/26 09:07:01 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putstr_print(char *s)
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

int	print_inti(int n)
{
	char	*str;
	int		res;

	str = ft_itoa_print(n);
	if (str == NULL)
		return (-1);
	res = ft_putstr_print(str);
	if (res == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (res);
}

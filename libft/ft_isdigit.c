/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:41:22 by dreule            #+#    #+#             */
/*   Updated: 2024/10/09 08:22:53 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

// int	main(void)
// {
// 	char digit;

// 	digit = '1';
// 	if (ft_isdigit(digit))
// 		printf("'%c' ist eine Zahl.\n", digit);
// 	else
// 		printf("'%c' ist keine Zahl.\n", digit);
// }
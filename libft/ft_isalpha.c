/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:16:18 by dreule            #+#    #+#             */
/*   Updated: 2024/10/09 08:19:30 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
		return (0);
	return (1);
}

// int	main(void)
// {
// 	char alpha;

// 	alpha = 'A';
// 	if (ft_isalpha(alpha))
// 		printf("'%c' ist ein Buchstabe.\n", alpha);
// 	else
// 		printf("'%c' ist kein Buchstabe.\n", alpha);
// }
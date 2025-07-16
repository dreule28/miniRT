/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:39:22 by dreule            #+#    #+#             */
/*   Updated: 2024/10/09 08:41:37 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (!(c >= 0 && c <= 127))
		return (0);
	return (1);
}

// int main(void)
// {
// 	char ascii;

// 	ascii = 127;
// 	if (ft_isascii(ascii))
// 		printf("'%d' ist ein Ascii-Character.\n", ascii);
// 	else
// 		printf("'%d' ist kein Ascii-Character.\n", ascii);
// }
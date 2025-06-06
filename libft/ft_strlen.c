/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:45:48 by dreule            #+#    #+#             */
/*   Updated: 2025/05/06 12:18:09 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (str == NULL)
		return ((size_t) NULL);
	while (*str != '\0')
	{
		str++;
		len++;
	}
	return (len);
}

// int	main(void)
// {
// 	const char *stri = "Hello";

// 	printf("Der String \"%s\" ist %zu lang.\n",stri, ft_strlen(stri));
// }
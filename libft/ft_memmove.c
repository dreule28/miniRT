/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:48:08 by dreule            #+#    #+#             */
/*   Updated: 2024/10/18 20:45:37 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*else_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*surc;

	dest = (unsigned char *)dst;
	surc = (unsigned char *)src;
	if (surc > dest)
	{
		while (len > 0)
		{
			*dest++ = *surc++;
			len--;
		}
	}
	return (0);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*surc;

	dest = (unsigned char *)dst;
	surc = (unsigned char *)src;
	if (!dst && !src)
		return (dst);
	if (surc < dest)
	{
		dest += len - 1;
		surc += len - 1;
		while (len > 0)
		{
			*dest-- = *surc--;
			len--;
		}
	}
	else
		else_memmove(dst, src, len);
	return (dst);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	unsigned char	*dest_og;
// 	unsigned char	*dest_me;
// 	const void		*src;

// 	// src = "Hallo Test";
// 	src = "Hallo Test";
// 	dest_og = NULL;
// 	dest_me = NULL;
// 	printf("OG: %s\n", memmove(dest_og, src, 5));
// 	printf("MY: %s\n", ft_memmove(dest_me, src, 5));
// 	return (0);
// }
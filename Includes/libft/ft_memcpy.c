/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:29:11 by dreule            #+#    #+#             */
/*   Updated: 2024/10/18 19:27:13 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*surc;

	if (!dst && !src)
		return (dst);
	dest = (unsigned char *)dst;
	surc = (unsigned char *)src;
	while (n > 0)
	{
		*dest = *surc;
		dest++;
		surc++;
		n--;
	}
	return (dst);
}

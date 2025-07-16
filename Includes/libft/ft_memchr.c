/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:24:07 by dreule            #+#    #+#             */
/*   Updated: 2024/10/09 12:53:07 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	ce;

	ptr = (unsigned char *)s;
	ce = c;
	while (n > 0)
	{
		if (*ptr == ce)
			return (ptr);
		ptr++;
		n--;
	}
	return (NULL);
}

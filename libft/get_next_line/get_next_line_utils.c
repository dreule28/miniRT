/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 07:59:27 by dreule            #+#    #+#             */
/*   Updated: 2024/11/04 15:39:03 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (*str != '\0')
	{
		str++;
		len++;
	}
	return (len);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len1;
	size_t	len2;

	if (!s1)
		s1 = NULL;
	if (!s2)
		s2 = NULL;
	len1 = ft_strlen_gnl(s1);
	len2 = ft_strlen_gnl(s2);
	new_str = malloc(len1 + len2 + 1);
	if (!new_str)
		return (NULL);
	ft_strlcpy_gnl(new_str, s1, len1 + 1);
	ft_strlcpy_gnl(new_str + len1, s2, len2 +1);
	return (new_str);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!src)
		return (0);
	if (!dst || dstsize == 0)
		return (ft_strlen_gnl(src));
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < dstsize -1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[len] != '\0')
		len++;
	return (len);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen_gnl(s);
	if (start >= str_len)
		return (ft_strdup_gnl(""));
	if (len > str_len - start)
		len = str_len - start;
	if (len == 0)
		return (ft_strdup_gnl(""));
	substr = malloc(len +1);
	if (!substr)
		return (NULL);
	ft_strlcpy_gnl(substr, s + start, len + 1);
	return (substr);
}

void	set_leftovers_null(char **leftovers)
{
	if (leftovers && *leftovers)
	{
		free(*leftovers);
		*leftovers = NULL;
	}
}

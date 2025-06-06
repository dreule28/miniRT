/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:46:48 by danielreule       #+#    #+#             */
/*   Updated: 2024/11/04 13:35:55 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

	if (!s1 && !s2)
		return (ft_strdup_gnl(""));
	if (!s1)
		return (ft_strdup_gnl(s2));
	if (!s2)
		return (ft_strdup_gnl(s1));
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
	size_t	substr_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen_gnl(s);
	if (start >= str_len)
		return (ft_strdup_gnl(""));
	substr_len = str_len - start;
	if (len < substr_len)
		substr_len = len;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy_gnl(substr, s + start, substr_len + 1);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_gc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:42:55 by gzovkic           #+#    #+#             */
/*   Updated: 2025/05/04 11:42:56 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "garbage_collector.h"

int	gc_fill_words(char **str, const char *s, char c)
{
	const char	*start;
	char		*temp;
	int			i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			start = s;
			while (*s && *s != c)
				s++;
			temp = gc_split_substr(start, s);
			if (!temp)
			{
				gc_free_words(str, i);
				return (0);
			}
			str[i++] = temp;
		}
	}
	str[i] = NULL;
	return (1);
}

char	*gc_split_substr(char const *start, char const *end)
{
	int		len;
	char	*word;

	len = end - start;
	word = ft_malloc(len + 1, sizeof(char));
	if (!word)
		return (NULL);
	ft_memcpy(word, start, len);
	return (word[len] = '\0', word);
}

void	gc_free_words(char **str, int i)
{
	while (i--)
		free(str[i]);
	free(str);
}

char	*gc_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = ft_malloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, len1 + 1);
	ft_strlcpy(new_str + len1, s2, len2 + 1);
	return (new_str);
}

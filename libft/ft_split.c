/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:17:00 by dreule            #+#    #+#             */
/*   Updated: 2024/10/17 11:50:23 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	counter;
	int	in_word;

	counter = 0;
	in_word = 0;
	while (*s != '\0')
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			counter++;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (counter);
}

static char	*substr(char const *start, char const *end)
{
	int		len;
	char	*word;

	len = end - start;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, start, len);
	return (word[len] = '\0', word);
}

static void	free_words(char **str, int i)
{
	while (i--)
		free(str[i]);
	free(str);
}

static int	fill_words(char **str, const char *s, char c)
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
			temp = substr(start, s);
			if (!temp)
			{
				free_words(str, i);
				return (0);
			}
			str[i++] = temp;
		}
	}
	str[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		word_count;

	if (!s)
		return (NULL);
	if (*s == '\0')
	{
		str = malloc(sizeof(char *));
		if (!str)
			return (NULL);
		str[0] = NULL;
		return (str);
	}
	word_count = count_words(s, c);
	str = malloc((word_count + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	if (!fill_words(str, s, c))
	{
		return (NULL);
	}
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char **result = ft_split("This,is a,test", ',');
// 	for (int i = 0; result[i]; i++)
// 	{
// 		printf("%s\n", result[i]);
// 		free(result[i]);
// 	}
// 	free(result);
// 	return (0);
// }

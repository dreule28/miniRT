/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 07:59:13 by dreule            #+#    #+#             */
/*   Updated: 2024/11/04 15:40:11 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_strdup_gnl(const char *s1)
{
	char		*store;
	size_t		i;
	size_t		len;
	const char	*temp;

	if (!s1)
		return (NULL);
	i = 0;
	len = 0;
	temp = s1;
	while (*temp != '\0')
	{
		temp++;
		len++;
	}
	store = malloc(len + 1);
	if (!store)
		return (NULL);
	while (s1[i] != '\0')
	{
		store[i] = s1[i];
		i++;
	}
	store[i] = '\0';
	return (store);
}

char	*extract_line(char **leftovers)
{
	char	*ext_line;
	char	*line_pos;
	char	*temp_leftovers;

	if (!leftovers || !*leftovers || !**leftovers)
		return (set_leftovers_null(leftovers), NULL);
	line_pos = ft_strchr_gnl(*leftovers, '\n');
	if (line_pos)
	{
		ext_line = ft_substr_gnl(*leftovers, 0, line_pos - *leftovers + 1);
		if (!ext_line)
			return (set_leftovers_null(leftovers), NULL);
		temp_leftovers = ft_strdup_gnl(line_pos + 1);
		free(*leftovers);
		*leftovers = temp_leftovers;
	}
	else
	{
		ext_line = ft_strdup_gnl(*leftovers);
		free(*leftovers);
		*leftovers = NULL;
	}
	if (ext_line && !*ext_line)
		return (free(ext_line), NULL);
	return (ext_line);
}

char	*find_line(int fd, char *buffer, char **leftovers)
{
	char	*combined;
	ssize_t	bytes_read;

	if (!buffer || !leftovers)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (set_leftovers_null(leftovers), NULL);
	if (bytes_read == 0)
		return (extract_line(leftovers));
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		combined = ft_strjoin_gnl(*leftovers, buffer);
		if (!combined)
			return (set_leftovers_null(leftovers), NULL);
		free(*leftovers);
		*leftovers = combined;
		if (ft_strchr_gnl(buffer, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (set_leftovers_null(leftovers), NULL);
	}
	return (extract_line(leftovers));
}

char	*get_next_line(int fd)
{
	static char	*leftovers;
	char		*buffer;
	char		*line;
	ssize_t		bytes_read;

	bytes_read = read(fd, NULL, 0);
	if (fd < 0 || BUFFER_SIZE <= 0 || bytes_read < 0)
	{
		free(leftovers);
		leftovers = NULL;
		return (NULL);
	}
	if (leftovers && ft_strchr_gnl(leftovers, '\n'))
		return (extract_line(&leftovers));
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(leftovers);
		leftovers = NULL;
		return (NULL);
	}
	line = find_line(fd, buffer, &leftovers);
	free(buffer);
	return (line);
}

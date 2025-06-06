/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:45:56 by danielreule       #+#    #+#             */
/*   Updated: 2024/11/05 09:59:00 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*extract_line(char **leftovers, int fd)
{
	char	*ex_line;
	char	*line_pos;
	char	*temp_leftovers;

	if (!leftovers || !leftovers[fd] || !*leftovers[fd])
		return (set_leftovers_null(&leftovers[fd]), NULL);
	line_pos = ft_strchr_gnl(leftovers[fd], '\n');
	if (line_pos)
	{
		ex_line = ft_substr_gnl(leftovers[fd], 0,
				(line_pos - leftovers[fd]) + 1);
		if (!ex_line)
			return (set_leftovers_null(&leftovers[fd]), NULL);
		temp_leftovers = ft_strdup_gnl(line_pos + 1);
		free(leftovers[fd]);
		return (leftovers[fd] = temp_leftovers, ex_line);
	}
	else
		ex_line = ft_strdup_gnl(leftovers[fd]);
	free(leftovers[fd]);
	leftovers[fd] = NULL;
	if (ex_line && !*ex_line)
		return (free(ex_line), NULL);
	return (ex_line);
}

char	*find_line(int fd, char *buffer, char *leftovers[])
{
	char	*combined;
	ssize_t	bytes_read;

	if (!buffer || !leftovers || fd >= 10240)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (set_leftovers_null(&leftovers[fd]), NULL);
	if (bytes_read == 0)
		return (extract_line(leftovers, fd));
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		combined = ft_strjoin_gnl(leftovers[fd], buffer);
		if (!combined)
			return (set_leftovers_null(&leftovers[fd]), NULL);
		free(leftovers[fd]);
		leftovers[fd] = combined;
		if (ft_strchr_gnl(leftovers[fd], '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (set_leftovers_null(&leftovers[fd]), NULL);
	}
	return (extract_line(leftovers, fd));
}

char	*get_next_line(int fd)
{
	static char	*leftovers[10240];
	char		*buffer;
	char		*line;
	ssize_t		bytes_read;

	bytes_read = read(fd, NULL, 0);
	if (fd < 0 || BUFFER_SIZE <= 0 || bytes_read < 0 || fd > 10240)
	{
		free(leftovers[fd]);
		leftovers[fd] = NULL;
		return (NULL);
	}
	if (leftovers[fd] && ft_strchr_gnl(leftovers[fd], '\n'))
		return (extract_line(leftovers, fd));
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(leftovers[fd]);
		leftovers[fd] = NULL;
		return (NULL);
	}
	line = find_line(fd, buffer, leftovers);
	free(buffer);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:43:05 by gzovkic           #+#    #+#             */
/*   Updated: 2025/05/04 11:43:06 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

// Includes
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Structs
typedef struct s_gc_node
{
	void				*data;
	struct s_gc_node	*next;
}						t_gc_node;

typedef struct s_gc_list
{
	t_gc_node			*head;
	t_gc_node			*tail;
	size_t				size;
}						t_gc_list;

// Funcitons in ft_malloc.c
void					*ft_malloc(size_t count, size_t size);
char					*gc_strjoin(char const *s1, char const *s2);

// Functions in gc_untils.c
void					gc_add(void *ptr);
void					gc_free(void);
void					gc_init(void);
void					clean_up(void);
t_gc_list				*get_gc(void);

// Functions in gc_libft_functions.c
char					*gc_substr(char const *s, unsigned int start,
							size_t len);
char					*gc_strdup(const char *s1);
char					**gc_split(char const *s, char c);
int						gc_count_words(char const *s, char c);
int						gc_fill_words(char **str, const char *s, char c);
char					*gc_split_substr(char const *start, char const *end);
void					gc_free_words(char **str, int i);
char					*gc_itoa(int n);
char					*gc_strjoin(char const *s1, char const *s2);

#endif
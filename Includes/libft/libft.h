/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:25:46 by dreule            #+#    #+#             */
/*   Updated: 2025/06/11 12:27:44 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>

/* The s_list structure represents a node in ft_ singly linked list. */
// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }					t_list;

/* Checks if the given character is alphabetic (A-Z or a-z). */
int		ft_isalpha(int c);

/* Checks if the given character is a decimal digit (0-9). */
int		ft_isdigit(int c);

/* Checks if the given character is alphanumeric (A-Z, a-z, 0-9). */
int		ft_isalnum(int c);

/* Checks if the given character is an ASCII character (0-127). */
int		ft_isascii(int c);

/* Checks if the given character is printable, including space. */
int		ft_isprint(int c);

/*Checks if a character is a whitespace character. */
int		ft_is_space(char c);

/* Returns the length of a null-terminated string. */
size_t	ft_strlen(const char *str);

/* Fills the first len bytes of memory at b with the constant byte c. */
void	*ft_memset(void *b, int c, size_t len);

/* Converts a lowercase character to uppercase. */
int		ft_toupper(int c);

/* Converts an uppercase character to lowercase. */
int		ft_tolower(int c);

/* Finds the first occurrence of c in the string str. */
char	*ft_strchr(const char *str, int c);

/* Finds the last occurrence of c in the string str. */
char	*ft_strrchr(const char *str, int c);

/* Compares at most n characters of two null-terminated strings. */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* Compares two null-terminated strings. */
int		ft_strcmp(char *s1, char *s2);

/* Writes n zero bytes to the memory area s. */
void	ft_bzero(void *s, size_t n);

/* Locates the first occurrence of c in the memory area s. */
void	*ft_memchr(const void *s, int c, size_t n);

/* Copies n bytes from src to dst. Undefined if they overlap. */
void	*ft_memcpy(void *dst, const void *src, size_t n);

/* Compares n bytes of two memory areas. */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/* Copies len bytes from src to dst, safely handling overlaps. */
void	*ft_memmove(void *dst, const void *src, size_t len);

/* Copies up to dstsize - 1 characters from src to dst. */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/* Searches for needle in haystack, stopping after len characters. */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/* Appends src to dst, ensuring the result is null-terminated. */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/* Converts a string to an integer. */
int		ft_atoi(const char *str);

/* Converts a string to a floating-point number. */
double	ft_atof(const char *str);

/* Converts a string to a long type*/
long	ft_atol(char *str);

/* Allocates memory for an array and initializes it to zero. */
void	*ft_calloc(size_t count, size_t size);

/* Allocates memory and duplicates the given string. */
char	*ft_strdup(const char *s1);

/* Returns a substring from the string s, starting at start, with length len. */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* Concatenates s1 and s2 into a newly allocated string. */
char	*ft_strjoin(char const *s1, char const *s2);

/* Trims characters in set from the beginning and end of s1. */
char	*ft_strtrim(char const *s1, char const *set);

/* Splits the string s into an array of strings using delimiter c. */
char	**ft_split(char const *s, char c);

/* Converts an integer to a null-terminated string. */
char	*ft_itoa(int n);

/* Applies function f to each character of s, creating a new string. */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* Applies function f to each character of s by modifying it in place. */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/* Writes the character c to the given file descriptor. */
void	ft_putchar_fd(char c, int fd);

/* Writes the string s to the given file descriptor. */
void	ft_putstr_fd(char *s, int fd);

/* Writes the string s, followed by a newline, to the given file descriptor. */
void	ft_putendl_fd(char *s, int fd);

/* Writes the integer n to the given file descriptor. */
void	ft_putnbr_fd(int n, int fd);

/* Creates a new list node with the given content. */
// t_list	*ft_lstnew(void *content);

// // /* Adds a new node at the beginning of the list. */
// void	ft_lstadd_front(t_list **lst, t_list *new);

// // /* Returns the number of nodes in the list. */
// int		ft_lstsize(t_list *lst);

// // /* Returns the last node of the list. */
// t_list	*ft_lstlast(t_list *lst);

// // /* Adds a new node at the end of the list. */
// void	ft_lstadd_back(t_list **lst, t_list *new);

// // /* Frees the memory of a node's content using del, and the node itself. */
// void	ft_lstdelone(t_list *lst, void (*del)(void*));

// // /* Frees all nodes of the list and sets the pointer to NULL. */
// void	ft_lstclear(t_list **lst, void (*del)(void*));

// // /* Applies the function f to each node in the list. */
// void	ft_lstiter(t_list *lst, void (*f)(void *));

// // /* Creates a new list by applying f to each node, using del if needed. */
// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
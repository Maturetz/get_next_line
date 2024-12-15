/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maturetz <maturetz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:08:18 by maturetz          #+#    #+#             */
/*   Updated: 2024/12/11 11:09:34 by maturetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);
char		*ft_read_file(int fd, char *tab);
char		*ft_join_free(char *tab, char *buff);
char		*ft_get_line(char *tab);
char		*ft_next_line(char *tab);

size_t		ft_strlen(const char *str);

void		ft_bzero(void *s, size_t n);
void		*ft_calloc(unsigned int nmemb, unsigned int size);

char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(const char *s1, const char *s2);

#endif
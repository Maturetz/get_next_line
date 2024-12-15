/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maturetz <maturetz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:07:26 by maturetz          #+#    #+#             */
/*   Updated: 2024/12/11 23:20:21 by maturetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join_free(char *tab, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(tab, buff);
	return (free(tab), tab = NULL, tmp);
}

char	*ft_read_file(int fd, char *tab)
{
	int		i;
	char	*buff;

	if (!tab)
		tab = ft_calloc(1, 1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (free(tab), tab = NULL, NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			return (free(tab), tab = NULL, free(buff), buff = NULL, NULL);
		buff[i] = 0;
		tab = ft_join_free(tab, buff);
		if (ft_strchr(tab, '\n'))
			break ;
	}
	return (free(buff), tab);
}

char	*ft_get_line(char *tab)
{
	int		i;
	char	*str;

	i = 0;
	if (!tab[i])
		return (NULL);
	while (tab[i] && tab[i] != '\n')
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (tab[i] && tab[i] != '\n')
	{
		str[i] = tab[i];
		i++;
	}
	if (tab[i] && tab[i] == '\n')
		str[i++] = '\n';
	return (str);
}

char	*ft_next_line(char *tab)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (tab[i] && tab[i] != '\n')
		i++;
	if (!tab[i])
		return (free(tab), NULL);
	str = ft_calloc((ft_strlen(tab) - i + 1), sizeof(*tab));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (tab[i])
		str[j++] = tab[i++];
	str[j] = '\0';
	free(tab);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*tab;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tab = ft_read_file(fd, tab);
	if (!tab)
		return (NULL);
	line = ft_get_line(tab);
	tab = ft_next_line(tab);
	return (line);
}

// int main()
// {
// 	int fd = open("a.txt", O_RDONLY);
// 	char *a;

// 	while ((a = get_next_line(fd)))
// 	{
// 		printf("%s", a);
// 	}

// 	// printf("%s", get_next_line(fd));

// 	return 0;
// }
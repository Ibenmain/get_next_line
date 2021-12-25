/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 23:43:25 by ibenmain          #+#    #+#             */
/*   Updated: 2021/12/21 19:51:36 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*get_rest(char *str)
{
	char	*new_str;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	new_str = ft_substr(str, i + 1, (ft_strlen(str) - i) + 1);
	free(str);
	str = NULL;
	return (new_str);
}

char	*get_line(char *str)
{
	char	*new_str;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	new_str = ft_substr(str, 0, i + 1);
	return (new_str);
}

int	find_new_line(char *string)
{
	int	i;

	if (!string)
		return (0);
	i = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	int			size_read;
	char		*line;
	char		buff[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (find_new_line(str[fd]) == 1)
		return (line = get_line(str[fd]), str[fd] = get_rest(str[fd]), line);
	size_read = read(fd, buff, BUFFER_SIZE);
	if (size_read <= 0)
	{
		if (!str[fd])
			return (NULL);
		if (!*str[fd])
			return (free(str[fd]), str[fd] = NULL, NULL);
		line = ft_strdup(str[fd]);
		return (free(str[fd]), str[fd] = NULL, line);
	}
	buff[size_read] = '\0';
	str[fd] = ft_strjoin(str[fd], buff);
	return (get_next_line(fd));
}

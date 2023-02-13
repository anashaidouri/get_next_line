/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:29:29 by ahaidour          #+#    #+#             */
/*   Updated: 2022/11/17 21:14:10 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*after(char *buf)
{
	char	*new_line;
	int		j;
	int		i;

	i = 0;
	if (!buf)
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\0' || buf[i + 1] == '\0')
	{
		free(buf);
		return (NULL);
	}
	new_line = malloc(ft_strlen(&buf[i]) + 1);
	if (!new_line)
		return (NULL);
	i++;
	j = 0;
	while (buf[i])
		new_line[j++] = buf[i++];
	new_line[j] = '\0';
	free(buf);
	return (new_line);
}

static char	*before(char *buf)
{
	char	*str;
	int		i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	str = malloc(i + 1);
	if (!str)
	{
		free(buf);
		return (NULL);
	}
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		str[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*read_join(char *buf, int fd)
{
	int		i;
	char	*s;

	i = 1;
	s = malloc((BUFFER_SIZE + 1));
	if (!s)
		return (NULL);
	while (i > 0)
	{
		i = read(fd, s, BUFFER_SIZE);
		if (!i)
			break ;
		if (i == -1)
		{
			free(s);
			free(buf);
			return (NULL);
		}
		s[i] = 0;
		buf = ft_strjoin(buf, s);
		if (ft_strchr(s, '\n') != NULL)
			break ;
	}
	free(s);
	return (buf);
}

char	*get_next_line(int fd)
{
	char		*s;
	static char	*buf[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buf[fd] = read_join(buf[fd], fd);
	if (!buf[fd])
		return (NULL);
	s = before(buf[fd]);
	buf[fd] = after(buf[fd]);
	return (s);
}

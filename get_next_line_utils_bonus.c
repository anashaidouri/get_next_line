/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:33:12 by ahaidour          #+#    #+#             */
/*   Updated: 2022/11/14 21:34:19 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*join;

	if (!s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!join)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		join[i++] = s2[j++];
	}
	join[i] = '\0';
	free(s1);
	return (join);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;
	int		len;

	len = ft_strlen(s);
	p = (char *)malloc(sizeof(char) * len + 1);
	if (p != NULL)
	{
		i = 0;
		while (i < len)
		{
			p[i] = s[i];
			i++;
		}
		p[i] = '\0';
		return (p);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <sghunmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:02:08 by sghunmin          #+#    #+#             */
/*   Updated: 2025/10/01 12:31:36 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*until_newline(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	res = malloc(i + 1);
	if (!res)
		return (NULL);
	while (j < i)
	{
		res[j] = str[j];
		j++;
	}
	free(str);
	res[j] = '\0';
	return (res);
}

static void	*ft_memcpy_g(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	if (dest == NULL && src == NULL)
		return (NULL);
	p1 = (unsigned char *)src;
	p2 = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		p2[i] = p1[i];
		i++;
	}
	return (dest);
}

static int	init(char *buffer, ssize_t *bytes, int fd)
{
	char	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (buffer[0] != '\0')
	{
		if (!ft_strchr_g(buffer, '\n'))
			return (0);
		temp = ft_strchr_g(buffer, '\n') + 1;
		if (!ft_memcpy_g(buffer, temp, ft_strlen_g(temp)))
			return (0);
		buffer[ft_strlen_g(temp)] = '\0';
	}
	else
	{
		*bytes = read(fd, buffer, BUFFER_SIZE);
		if (*bytes <= 0)
		{
			buffer[0] = '\0';
			return (0);
		}
		buffer[*bytes] = '\0';
	}
	return (1);
}

static int	read_line(char *buffer, char **line, ssize_t *bytes, int fd)
{
	while (*bytes > 0)
	{
		*line = ft_strjoin_g(*line, buffer);
		if (!*line)
		{
			buffer[0] = '\0';
			return (0);
		}
		if (ft_strchr_g(*line, '\n'))
			break ;
		*bytes = read(fd, buffer, BUFFER_SIZE);
		if ((*bytes < 0) || (*bytes == 0 && *line[0] == '\0'))
		{
			buffer[0] = '\0';
			free(*line);
			return (0);
		}
		else if (*bytes == 0 && *line[0] != '\0')
			break ;
		if (*bytes < BUFFER_SIZE)
			buffer[*bytes] = '\0';
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	static ssize_t	bytes;
	char			*line;

	if (!init(buffer, &bytes, fd))
		return (NULL);
	line = ft_strdup_g("");
	if (!line)
		return (NULL);
	if (!(read_line(buffer, &line, &bytes, fd)))
		return (NULL);
	return (until_newline(line));
}

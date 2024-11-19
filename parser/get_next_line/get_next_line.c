/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:00:36 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/19 13:19:58 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joint;
	int		i;

	if (s1 == NULL && s2)
		return (strdup(s2));
	if (s2 == NULL && s1)
		return (strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	i = -1;
	joint = (char *)malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
	if (!joint)
		return (NULL);
	while (s1[++i])
		joint[i] = s1[i];
	while (*s2)
		joint[i++] = *s2++;
	joint[i] = '\0';
	return (joint);
}

char	*ysubstr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		size;
	size_t	substr_len;
	int		i;

	if (!s)
		return (0);
	if (strlen(s) < start)
		return (strdup(""));
	substr_len = strlen(s + start);
	if (substr_len < len)
		len = substr_len;
	size = sizeof(char) * (len + 1);
	substr = (char *)malloc(size);
	if (!substr)
		return (0);
	i = 0;
	while (s[start] && i < size - 1)
	{
		substr[i] = s[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

int	fill_line(char **line, char *reader, char *remainder)
{
	char	*fr_line;
	char	*new_line_ptr;

	fr_line = *line;
	*line = ft_strjoin(*line, reader);
	if (!*line)
		return (free(fr_line), 0);
	free(fr_line);
	new_line_ptr = strchr(*line, '\n');
	if (new_line_ptr)
	{
		while (*reader != '\n')
			reader++;
		reader++;
		while (*reader)
			*remainder++ = *reader++;
		*remainder = '\0';
		fr_line = *line;
		*line = ysubstr(*line, 0, (new_line_ptr + 1) - *line);
		if (!*line)
			return (free(fr_line), 0);
		free(fr_line);
	}
	return (1);
}

char	*yget_line(int fd, char *remainder, char *reader, char **line)
{
	ssize_t	rd;

	while (1)
	{
		rd = read(fd, reader, BUFFER_SIZE);
		if (rd == 0)
		{
			if (strlen(*line) > 0)
				return (memset(remainder, 0, BUFFER_SIZE),
					memset(reader, 0, BUFFER_SIZE), *line);
			else
				return (memset(remainder, 0, BUFFER_SIZE),
					memset(reader, 0, BUFFER_SIZE), free(*line), NULL);
		}
		if (rd < 0)
			return (free(*line), NULL);
		reader[rd] = '\0';
		if (!fill_line(line, reader, remainder) || !line)
			return (NULL);
		if (strchr(*line, '\n'))
			break ;
	}
	return (memset(reader, 0, BUFFER_SIZE), *line);
}

char	*get_next_line(int fd)
{
	static char	r[2][BUFFER_SIZE + (size_t)1];
	char		*line;
	size_t		i;

	if (BUFFER_SIZE == 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (memset(r[1], 0, BUFFER_SIZE), NULL);
	line = NULL;
	i = 0;
	while (!r[1][i] && i < BUFFER_SIZE)
		i++;
	if (!strchr(&r[1][i], '\n'))
	{
		line = strdup(&r[1][i]);
		memset(r[1], 0, BUFFER_SIZE);
		if (!line)
			return (NULL);
	}
	else if (strchr(&r[1][i], '\n'))
	{
		line = ysubstr(&r[1][i], 0, (strchr(&r[1][i], '\n') + 1) - &r[1][i]);
		memset(&r[1][i], 0, (strchr(&r[1][i], '\n') + 1) - &r[1][i]);
		return (memset(r[0], 0, BUFFER_SIZE), line);
	}
	return (yget_line(fd, r[1], r[0], &line));
}

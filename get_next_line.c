/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:22:40 by adi-nata          #+#    #+#             */
/*   Updated: 2023/01/16 17:55:14 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*stat;
	char			*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, &buffer, 0) < 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!stat)
	{
		stat = (char *)malloc(1);
		stat[0] = '\0';
	}
	line = get_line(fd, &stat, buffer);
	free (buffer);
	return (line);
}


char	*get_line(int fd, char **stat, char *buffer)
{
	int		bytesread;
	char	*tmpstat;
	char	*line;

	bytesread = 1;
	while (bytesread)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
			return (NULL);
		buffer[bytesread] = '\0';
		tmpstat = *stat;
		*stat = ft_strjoin(tmpstat, buffer);
		free (tmpstat);
		if (endornewline(*stat, bytesread) > 0)
		{
			line = ft_substr(*stat, 0, endornewline(*stat, bytesread));
			free (*stat);
			*stat = ft_substr(buffer, (int)endornewline(buffer, bytesread), (ft_strlen(buffer) - endornewline(buffer, bytesread)));
			return (line);
		}
		
	}
	return (0);
}

size_t	endornewline(char *buffer, int bytesread)
{
	int		i;

	if (buffer == NULL)
		return (0);
	if (bytesread == 0)
		return (ft_strlen(buffer));
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

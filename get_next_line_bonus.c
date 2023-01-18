/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:22:40 by adi-nata          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/18 19:08:07 by adi-nata         ###   ########.fr       */
=======
/*   Updated: 2023/01/18 18:53:27 by adi-nata         ###   ########.fr       */
>>>>>>> 553d65121a71b88e0a9ae54e4d1b0db79ad56a4e
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char		*stat[1024];
	char			*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, &buffer, 0) < 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!stat[fd])
	{
		stat[fd] = (char *)malloc(1 * sizeof(char));
		stat[fd][0] = '\0';
	}
	line = zeline(fd, &stat[fd], buffer);
<<<<<<< HEAD
	/*if (line == NULL)
	{
		free (stat);
		//stat = NULL;
	}*/
=======
	if (line == NULL)
	{
		free (stat);
		*stat = NULL;
	}
>>>>>>> 553d65121a71b88e0a9ae54e4d1b0db79ad56a4e
	free (buffer);
	return (line);
}

char	*zeline(int fd, char **stat, char *buffer)
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
			tmpstat = *stat;
			*stat = ft_substr(tmpstat, (int)endornewline(tmpstat, bytesread),
					(ft_strlen(tmpstat) - endornewline(tmpstat, bytesread)));
			free (tmpstat);
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
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i + 1);
		i++;
	}
	if (bytesread == 0 && buffer[0] != '\0')
		return (ft_strlen(buffer));
	return (0);
}

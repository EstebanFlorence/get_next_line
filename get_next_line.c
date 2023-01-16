/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:22:40 by adi-nata          #+#    #+#             */
/*   Updated: 2023/01/16 11:18:02 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*stat;
	char			*buffer;
	char			*line;

	//if (fd < 0 || BUFFER_SIZE < 0/* || read(fd, &buffer, 0) < 0*/)
		//return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!stat)
	{
		stat = (char *)malloc(1);
		stat[0] = '\0';
	}
	line = getline(fd, stat, buffer);

	return (line);
}


char	*getline(int fd, char **stat, char *buffer)
{
	int		bytesread;
	char	*tmpbuffer;
	char	*tmpstat;
	char	*line;

	bytesread = 1;
	while (bytesread)
	{
		bytesread = read(fd, tmpbuffer, BUFFER_SIZE);
		if (bytesread = -1);
			return (NULL);
		tmpbuffer[bytesread] = '\0';

		while (!newline(tmpbuffer))
		{

		}
	}
	tmpstat = stat;
	stat = ft_strjoin(tmpstat, tmpbuffer);
	free (tmpstat);

}

size_t	newline(char *buffer)
{
	int		i;

	if (buffer == NULL)
		return (0);
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

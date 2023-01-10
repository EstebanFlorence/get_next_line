/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:22:40 by adi-nata          #+#    #+#             */
/*   Updated: 2023/01/10 19:52:16 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*offset;
	char			*line;
	int				bytesread;
	int				i;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, &line, 0) < 0)
		return (NULL);
	//offset = NULL;
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	bytesread = 1;
	i = 0;
	if (!offset)
	{
		offset = (char *)malloc(1);
		offset[i] = '\0';
	}
	while (!newline(offset) || bytesread)
	{
		bytesread = (int)read(fd, line, BUFFER_SIZE);

	}

	line[bytesread] = '\0';
	return (line);
}

int	newline(char *offset)
{
	int		i;

	if (offset == NULL)
		return (0);
	i = 0;
	while (offset[i])
	{
		if (offset[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

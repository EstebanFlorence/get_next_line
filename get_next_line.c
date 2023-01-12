/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:22:40 by adi-nata          #+#    #+#             */
/*   Updated: 2023/01/12 12:01:27 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*offset;
	char			*line;
	char			*stat;
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
	stat = offset;
	//	Finche read non da 0 = arriva a fine file
	while (bytesread)
	{
		//	line ha il contenuto di size BUFFER
		bytesread = (int)read(fd, line, BUFFER_SIZE);
		//	se incontro \n -> ritorno line fino a \n, eventuale resto (BUFFERSIZE - len fino a \n) nella statica
		if (ft_strchr(line, '\n'))
		{
			
		}


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

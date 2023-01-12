/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:22:40 by adi-nata          #+#    #+#             */
/*   Updated: 2023/01/12 18:11:16 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*offset;
	char			*sup;
	char			*line;
	char			*tmp;
	int				bytesread;

	//if (fd < 0 || BUFFER_SIZE < 0/* || read(fd, &tmp, 0) < 0*/)
		//return (NULL);
	//offset = NULL;
	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	bytesread = 1;
	if (!offset)
	{
		offset = (char *)malloc(1);
		offset[0] = '\0';
	}
	//	Finche read non da 0 = arriva a fine file
	while (bytesread)
	{
		//	line ha il contenuto di size BUFFER
		bytesread = (int)read(fd, tmp, BUFFER_SIZE);
		tmp[bytesread] = '\0';
		//	se tmp contiene \n => tmp = da 0 a \n		salvare da \n a fine BUFFER in offset
		








		//	se incontro \n -> ritorno line fino a \n, eventuale resto (BUFFERSIZE - len fino a \n) nella statica
		sup = offset;
		offset = ft_strjoin(sup, tmp);
		free (sup);
		if (endornewline(tmp, bytesread))
		{
			line = ft_substr(offset, 0, (BUFFER_SIZE - ft_strlen(offset)));
			sup = offset;
			offset = ft_substr(sup, endornewline(offset), (BUFFER_SIZE - endornewline(offset)));
			free (sup);
			return (line);
		}

	}
	free (offset);
	free (tmp);
}

size_t	endorendornewline(char *tmp, int bytesread)
{
	int		i;

	if (tmp == NULL)
		return (0);
	if (bytesread == 0)
		return (ft_strlen(tmp));
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

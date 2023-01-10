/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:22:40 by adi-nata          #+#    #+#             */
/*   Updated: 2023/01/09 23:30:26 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*offset;
	char			*line;
	int				bytesread;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, &line, 0) < 0)
		return (NULL);
	offset = NULL;
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytesread = (int)read(fd, line, BUFFER_SIZE);
	if (line == NULL || bytesread == -1)
		return (NULL);
	line[bytesread] = '\0';
	
}

int	newline(t_list *offset)
{
	int		i;
	t_list	*last;

	if (offset == NULL)
		return (0);
	i = 0;
	last = ft_lstlast(offset);
	while (last->line)
	{
		if (last->line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

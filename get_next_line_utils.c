/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:57:15 by adi-nata          #+#    #+#             */
/*   Updated: 2023/01/09 00:52:25 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char		*s;
	size_t		n;

	n = ft_strlen(s1) + 1;
	s = (char *)malloc(sizeof(*s) * n);
	if (!s)
		return (NULL);
	return ((char *)ft_memcpy(s, s1, n));
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	s = (char *)malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s)
		return (NULL);
	while (i < (int)ft_strlen(s1))
	{
		s[i] = s1[i];
		i++;
	}
	while (j < (int)ft_strlen(s2))
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = '\0';
	return (s);
}
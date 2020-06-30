/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Smeeblin <kvm1986@yandex.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 14:23:24 by Smeeblin          #+#    #+#             */
/*   Updated: 2020/06/30 20:33:22 by Smeeblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_checkline(char *back)
{
	int i;

	i = 0;
	while (back[i] != '\0')
	{
		if (back[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		spit_line(char **back, int checkline, char **line, char **buffer)
{
	char *point;

	(*back)[checkline] = '\0';
	*line = ft_strdup(*back);
	point = ft_strdup(*back + checkline + 1);
	free(*back);
	free(*buffer);
	*back = point;
	return (1);
}

int		return_all(char **back, char **line, int read_size, char **buffer)
{
	int checkline;

	if (read_size < 0)
	{
		free(*buffer);
		return (-1);
	}
	if (*back && (checkline = ft_checkline(*back)) >= 0)
		return (spit_line(back, checkline, line, buffer));
	else if (*back)
	{
		*line = *back;
		*back = 0;
		free(*buffer);
		return (0);
	}
	free(*back);
	free(*buffer);
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*back[100];
	ssize_t			sizeofread;
	char			*buffer;
	int				checkline;
	char			*tmp;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 ||
		(!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	while ((sizeofread = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[sizeofread] = '\0';
		if (back[fd] == NULL)
			back[fd] = ft_strdup("");
		tmp = ft_strjoin(back[fd], buffer);
		free(back[fd]);
		back[fd] = tmp;
		if ((checkline = ft_checkline(back[fd])) >= 0)
			return (spit_line(&back[fd], checkline, line, &buffer));
	}
	return (return_all(&back[fd], line, sizeofread, &buffer));
}

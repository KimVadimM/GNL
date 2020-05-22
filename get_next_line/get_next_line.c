/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Smeeblin <kvm1986@yandex.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 14:23:24 by Smeeblin          #+#    #+#             */
/*   Updated: 2020/05/21 17:08:37 by Smeeblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int		return_all(char **backup, char **line, int read_size, char **buffer)
{
	int checkline;

	if (read_size < 0)
		return (-1);
	if (*backup && (checkline = ft_checkline(*backup)) >= 0)
		return (spit_line(backup, checkline, line, buffer));
	else if (*backup)
	{
		*line = *backup;
		*backup = 0;
		return (0);
	}
	*line = ft_strdup("");
	free(*backup);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*back[10];
	ssize_t			sizeofread;
	char			*buffer;
	int				checkline;

	if (fd < 0 || line == NULL)
		return (-1);
	if (BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((sizeofread = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[sizeofread] = '\0';
		if (back[fd] == NULL)
			back[fd] = ft_strdup("");
		back[fd] = ft_strjoin(back[fd], buffer);
		if ((checkline = ft_checkline(back[fd])) >= 0)
			return (spit_line(&back[fd], checkline, line, &buffer));
	}
	return (return_all(&back[fd], line, sizeofread, &buffer));
}

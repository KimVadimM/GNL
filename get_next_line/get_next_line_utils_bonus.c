/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Smeeblin <kvm1986@yandex.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 14:23:13 by Smeeblin          #+#    #+#             */
/*   Updated: 2020/06/28 21:52:08 by Smeeblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t			di;
	size_t			si;
	unsigned int	i;

	di = 0;
	si = 0;
	i = 0;
	while (src[si] != '\0')
		si++;
	if (size == 0)
		return (si);
	while (dest[di] && di < size)
		++di;
	if (size <= di)
		return (size + si);
	i = 0;
	while (src[i] && (--size - di))
	{
		dest[di + i] = src[i];
		i++;
	}
	dest[di + i] = '\0';
	return (si + di);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	res;

	i = 0;
	if (!dst)
		return (0);
	res = ft_strlen(src);
	while (src[i] != '\0' && i < ((int)size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	if (size)
		dst[i] = '\0';
	return (res);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*fresh;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	fresh = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (fresh == 0)
		return (0);
	ft_strlcpy(fresh, s1, s1_len + 1);
	ft_strlcat(fresh + (s1_len), s2, s2_len + 1);
	free((char *)s1);
	return (fresh);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*fin;

	i = 0;
	fin = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (fin == 0)
		return (0);
	while (src[i] != '\0')
	{
		fin[i] = src[i];
		i++;
	}
	fin[i] = '\0';
	return (fin);
}

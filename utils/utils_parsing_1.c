/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 15:25:08 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/25 14:59:14 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_int_strstr(char *str, char *needle)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (needle[j] == str[i + j])
		{
			if (needle[j + 1] == '\0')
				return (1);
			j++;
		}
		i++;
	}
	if (str[i])
		return (0);
	return (0);
}

int	ft_int_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	if (str[i] || (char)c == '\0')
		return (0);
	return (0);
}

char	*ft_strdup_map_line(char *str, int length)
{
	int		i;
	int		size;
	char	*dst;

	i = 0;
	size = ft_strlen(str);
	dst = (char *)malloc(sizeof(*dst) * (length + 1));
	if (dst == NULL)
		return (NULL);
	while (i < size)
	{
		dst[i] = str[i];
		i++;
	}
	while (i < length)
	{
		dst[i] = ' ';
		i++;
	}
	dst[i] = (char) NULL;
	return (dst);
}

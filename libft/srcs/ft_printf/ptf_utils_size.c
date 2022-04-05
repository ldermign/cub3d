/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:59:15 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/25 14:08:04 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_with_c(char *str, char c, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
}

void	*fill_from_end(char *dst, char *src, size_t n)
{
	size_t	from_last;

	from_last = n;
	if (!dst && !src)
		return (NULL);
	while (from_last > 0)
	{
		dst[from_last] = src[from_last];
		from_last--;
	}
	return (dst);
}

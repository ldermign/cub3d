/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:23:45 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/15 13:42:49 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_random(int max)
{
	int		i;
	int		fd_rand;
	long	random;
	char	str[11 + 1];

	i = 0;
	random = 1;
	fd_rand = open("/dev/random", O_RDONLY);
	if (fd_rand == -1)
		return (-1);
	if (read(fd_rand, str, 11) > 0)
	{
		str[11] = '\0';
		while (i < 11)
		{
			random += str[i];
			i++;
		}
	}
	close(fd_rand);
	if (random < 0)
		random *= -1;
	while (random > max)
		random /= 10;
	return (random);
}

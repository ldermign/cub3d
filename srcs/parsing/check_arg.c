/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:49:37 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/14 09:59:17 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_name_map(char *arg)
{
	char	*name_map;
	int		len;

	name_map = arg;
	len = ft_strlen(name_map);
	if (name_map[len - 1] != 'b' || name_map[len - 2] != 'u'
		|| name_map[len - 3] != 'c' || name_map[len - 4] != '.')
	{
		printf("Error\nWrong map\'s name.\n");
		return (-1);
	}
	return (0);
}

int	ft_check_arg(int ac, char **ag)
{
	if (ac == 1)
	{
		printf("Error\nIt's missing at least one argument : the map.\n");
		exit (0);
	}
	else if (ac == 2)
	{
		if (ft_check_name_map(ag[1]) == -1)
			exit (0);
	}
	else
	{
		printf("Error\nToo many arguments.\n");
		exit (0);
	}
	return (1);
}

int	check_textures(t_arg *data)
{
	int	fd;

	fd = open(data->north, O_RDONLY);
	if (fd < 0)
		return (-1);
	close (fd);
	fd = open(data->south, O_RDONLY);
	if (fd < 0)
		return (-1);
	close (fd);
	fd = open(data->east, O_RDONLY);
	if (fd < 0)
		return (-1);
	close (fd);
	fd = open(data->west, O_RDONLY);
	if (fd < 0)
		return (-1);
	close (fd);
	return (1);
}

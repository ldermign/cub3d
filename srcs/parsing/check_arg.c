/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:49:37 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/05 15:15:56 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_save(char *arg)
{
	char	*ag_save;
	int		len;

	ag_save = arg;
	len = ft_strlen(ag_save);
	if (ft_strcmp(ag_save, "--save") != 0)
	{
		printf("Error\nThird argument must be \"--save\".\n");
		exit(0);
	}
	else
		return (0);
	return (1);
}

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
		return (1);
	}
	return (0);
}

void	ft_check_arg(int ac, char **ag)
{
	if (ac == 1)
	{
		printf("Error\nIt's missing at least one argument : the map.\n");
		exit (0);
	}
	else if (ac >= 2 && ac < 4)
	{
		if (ft_check_name_map(ag[1]) == 1)
			exit (0);
		if (ac == 3 && (ft_save(ag[2]) == 1))
			exit (0);
	}
	else
	{
		printf("Error\nToo many arguments.\n");
		exit (0);
	}
}

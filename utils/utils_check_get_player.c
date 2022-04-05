/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_get_player.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:46:12 by ldermign          #+#    #+#             */
/*   Updated: 2021/05/06 13:52:09 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	return_player(char **map)
{
	int	i;
	int	j;
	int	plr;

	i = 0;
	j = 0;
	plr = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_is_player(map[i][j]) == 1)
			{
				plr = map[i][j];
				break ;
			}
			j++;
		}
		i++;
	}
	return (plr);
}

int	how_many_player(t_arg *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->tmp = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_is_player((int)map[i][j]))
				data->tmp++;
			j++;
		}
		i++;
	}
	return (data->tmp);
}

void	get_position_player(t_arg *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == data->player)
			{
				data->plrX = i;
				data->plrY = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

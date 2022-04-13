/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_get_player_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:46:12 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/13 22:40:53 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

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
				data->plr_x = i;
				data->plr_y = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

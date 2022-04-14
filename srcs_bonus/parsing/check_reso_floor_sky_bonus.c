/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reso_floor_sky_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 10:03:46 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/14 13:13:05 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

int	check_space_in_split(t_arg *data, char *tmp)
{
	int	i;

	i = 0;
	if (tmp == NULL)
		return (quit_parsing(data,
				"It's missing some numbers in sky or floor.\n", 0, 0));
	while (tmp[i])
	{
		while (tmp[i] == ' ')
			i++;
		while (ft_isdigit(tmp[i]))
			i++;
		while (tmp[i] == ' ')
			i++;
		if (tmp[i] != '\0')
			return (quit_parsing(data,
					"Something's wrong in sky or floor.\n", 0, 0));
	}
	return (1);
}

int	check_infos_inside_split(t_arg *data, char **tmp)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (tmp[++i])
	{
		j = 0;
		data->tmp = 0;
		while (tmp[i][j])
		{
			if (ft_isdigit(tmp[i][j]))
				data->tmp++;
			if (tmp[i][j] != '\0' || tmp[i][j] == ' '
				|| tmp[i][j] != 'F' || tmp[i][j] != 'C')
				j++;
		}
		if (data->tmp == 0)
			return (quit_parsing(data,
					"It's missing numbers in sky or floor.\n", 0, 0));
	}
	if (i != 3)
		return (quit_parsing(data,
				"It's missing some info in sky or floor.\n", 0, 0));
	return (1);
}

int	check_floor_sky(t_arg *data, char *str)
{
	int		j;
	char	**tmp;

	j = 0;
	tmp = ft_split(str, ',');
	while (tmp[0][j] == ' ')
		j++;
	if ((ft_strncmp(&tmp[0][j], "C ", 2) != 0)
		&& (ft_strncmp(&tmp[0][j], "F ", 2) != 0))
		return (quit_parsing(data, "Wrong info in sky or floor.\n", 0, 0));
	if (check_space_in_split(data, &tmp[0][j + 1]) == -1
	|| check_space_in_split(data, tmp[1]) == -1
	|| check_space_in_split(data, tmp[2]) == -1
	|| check_infos_inside_split(data, tmp) == -1)
	{
		free_str(tmp);
		return (-1);
	}
	free_str(tmp);
	return (1);
}

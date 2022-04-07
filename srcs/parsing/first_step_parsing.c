/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 10:12:31 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/07 15:04:46 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map(t_arg *data)
{
	if (ft_strchr_tab_wrong_cara(data->map))
		return (quit_parsing(data, "Something's wrong in the map.\n", 0, 0));
	if (!get_position(data->map, 'N')
		&& !get_position(data->map, 'S')
		&& !get_position(data->map, 'E')
		&& !get_position(data->map, 'W'))
		return (quit_parsing(data, "Where is your player ? :(\n", 0, 0));
	data->tmp = how_many_player(data, data->map);
	if (data->tmp > 1)
		return (quit_parsing(data, "There can be only one....\n", 0, 0));
	data->player = return_player(data->map);
	if (check_start_end_map(data, data->map, data->player) == -1
		|| check_interior_map(data, data->map, data->player) == -1
		|| check_space_sprite_and_plr_map(data, data->map, '0') == -1
		|| check_space_sprite_and_plr_map(data, data->map, '2') == -1
		|| check_space_sprite_and_plr_map(data, data->map, data->player) == -1)
		return (-1);
	get_position_player(data);
	return (1);
}

int	recup_map(t_arg *data)
{
	int	start;
	int	end;
	int	len;
	int	larger;

	start = 0;
	end = data->len_fd - 1;
	while (data->fd[start] != NULL
		&& (ft_is_either(data->fd[start]) || data->fd[start][0] == '\0'))
		start++;
	while (data->fd[end][0] == '\0')
		end--;
	len = end - start + 1;
	if (len <= 2)
		return (quit_parsing(data, "This is not a map...\n", 0, 0));
	larger = which_is_larger(data->fd);
	ft_fill_map(data, len, start, larger);
	return (1);
}

int	recup_data(t_arg *data, char *str)
{
	if (ft_int_strstr(str, "F ") == 1)
		return (get_floor(data, str));
	else if (ft_int_strstr(str, "C ") == 1)
		return (get_sky(data, str));
	else if (ft_int_strstr(str, "NO ") == 1)
		data->north = get_texture(data, str, "NO ");
	else if (ft_int_strstr(str, "SO ") == 1)
		data->south = get_texture(data, str, "SO ");
	else if (ft_int_strstr(str, "EA "))
		data->east = get_texture(data, str, "EA ");
	else if (ft_int_strstr(str, "WE "))
		data->west = get_texture(data, str, "WE ");
	else if (ft_int_strstr(str, "S  "))
		data->sprite = get_texture(data, str, "S ");
	return (1);
}

int	check_wrong_data_and_recup(t_arg *data)
{
	int	i;

	i = 0;
	while (data->fd[i])
	{
		if (!ft_is_either(data->fd[i]) && data->fd[i][0] != '\0')
		{
			if (!ft_is_either(data->fd[i]) && is_map(data->fd[i]) == -1)
				return (quit_parsing(data, "Wrong info line ", 1, i + 1));
			else if (is_map(data->fd[i]) == 1)
				break ;
		}
		else if (recup_data(data, data->fd[i]) == -1)
			return (-1);
		i++;
	}
	if (data->flr_r < 0 || data->flr_g < 0 || data->flr_b < 0
		|| data->ciel_r < 0 || data->ciel_g < 0 || data->ciel_b < 0
		|| data->flr_r > 255 || data->flr_g > 255 || data->flr_b > 255
		|| data->ciel_r > 255 || data->ciel_g > 255 || data->ciel_b > 255)
		return (quit_parsing(data, "Check floor or sky's color.\n", 0, 0));
	if (data->north == NULL || data->south == NULL || data->east == NULL
		|| data->west == NULL || data->sprite == NULL)
		return (quit_parsing(data, "It's missing some info.\n", 0, 0));
	return (1);
}

int	gnl_mapcub(t_arg *data, char *arg)
{
	int		ret;
	int		fd_map;
	char	*line;

	fd_map = open(arg, O_RDONLY);
	line = NULL;
	if (fd_map < 0)
		return (quit_parsing(data, "Wrong name for .cub. Check that.\n", 0, 0));
	while (1)
	{
		ret = get_next_line(fd_map, &line);
		if (ret == -1)
			return (quit_parsing(data, "Petit malin...\n", 0, 0));
		if (ret <= 0)
			break ;
		data->len_fd++;
		free(line);
	}
	data->len_fd++;
	free(line);
	close(fd_map);
	save_mapcub_in_char(data, arg);
	return (1);
}

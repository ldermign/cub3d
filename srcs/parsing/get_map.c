/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 09:46:18 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/26 09:47:52 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_space_sprite_and_plr_map(t_arg *data, char **map, char c)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (map[i][j])
	{
		j = 0;
		if (ft_int_strchr(map[i], c))
		{
			while (j < which_is_larger(map) - 1)
			{
				if (map[i][j] == c && ((i != 0 && map[i - 1][j] == ' ')
						|| (j != 0 && map[i][j - 1] == ' ')
						|| map[i][j + 1] == ' ' || map[i + 1][j] == ' '))
					quit(data, "It's missing some wall line ", 2, i + 1);
				j++;
			}
		}
		i++;
		if (i == size_tab_char(map) - 1)
			break ;
	}
}

void	check_start_end_map(t_arg *data, char **map, int plr)
{
	int	i;
	int	len;

	i = 0;
	len = size_tab_char(data->map) - 1;
	if (ft_int_strchr(map[0], plr)
		|| ft_int_strchr(map[0], '0') || ft_int_strchr(map[0], '2'))
		quit(data, "Something's wrong in the first line of the map.\n", 0, 0);
	while (map[i])
	{
		if (ft_is_either(map[i]))
			quit(data, "No info at the end of the file.\n", 0, 0);
		i++;
	}
	if (ft_int_strchr(map[0], plr)
		|| ft_int_strchr(map[len], '0') || ft_int_strchr(map[len], '2'))
		quit(data, "Something's wrong in the last line of the map.\n", 0, 0);
}

void	check_interior_map(t_arg *data, char **map, int plr)
{
	int	i;
	int	size_str;

	i = 0;
	while (map[i])
	{
		size_str = ft_strlen(map[i]) - 1;
		if (!ft_int_strchr(map[i], '1')
			|| map[i][0] == plr || map[i][size_str] == plr
			|| map[i][0] == '0' || map[i][size_str] == '0'
			|| map[i][0] == '2' || map[i][size_str] == '2')
			quit(data, "Check line ", 2, i + 1);
		i++;
	}
}

void	ft_fill_map(t_arg *data, int len, int start, int larger)
{
	int	i;

	i = 0;
	data->map = (char **)malloc(sizeof (char *) * (len + 1));
	if (data->map == NULL)
		return ;
	while (i < len)
	{
		data->map[i] = ft_strdup_map_line(data->fd[start], larger);
		i++;
		start++;
	}
	data->map[i] = NULL;
}

void	save_mapcub_in_char(t_arg *data, char *arg)
{
	int		i;
	int		ret;
	int		fd_map;
	char	*line;

	i = 0;
	fd_map = open(arg, O_RDONLY);
	line = 0;
	data->fd = (char **)malloc(sizeof (char *) * (data->len_fd + 1));
	if (data->fd == NULL)
		return ;
	while (1)
	{
		ret = get_next_line(fd_map, &line);
		if (ret <= 0)
			break ;
		data->fd[i] = ft_strdup(line);
		i++;
		free(line);
	}
	data->fd[i] = ft_strdup(line);
	free(line);
	data->fd[++i] = NULL;
	close(fd_map);
}

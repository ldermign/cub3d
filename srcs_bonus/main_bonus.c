/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:37:45 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/13 22:39:15 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

int	parsing(int ac, char **ag, t_arg *data)
{
	init_struct_arg(data);
	if (ft_check_arg(ac, ag) == -1 || gnl_mapcub(data, ag[1]) == -1
		|| check_wrong_data_and_recup(data) == -1 || recup_map(data) == -1
		|| check_map(data) == -1)
		return (-1);
	if (check_textures(data) == -1)
	{
		quit_parsing(data, "One of the textures cannot be opened.\n", 0, 0);
		return (-1);
	}
	return (1);
}

int	main(int ac, char **ag)
{
	t_struct	all;

	if (parsing(ac, ag, &all.data) == -1)
		exit (1);
	init_cub(&all.cub, &(all.img), &all.data);
	print(all.cub);
	window(&all);
	return (0);
}

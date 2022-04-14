/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:05:49 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/14 02:46:57 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct_arg(t_arg *data)
{
	data->check_f = 0;
	data->check_c = 0;
	data->tmp = 0;
	data->last = 0;
	data->len_fd = 0;
	data->flr_r = 0;
	data->flr_g = 0;
	data->flr_b = 0;
	data->ciel_r = 0;
	data->ciel_g = 0;
	data->ciel_b = 0;
	data->north = NULL;
	data->south = NULL;
	data->west = NULL;
	data->east = NULL;
	data->fd = NULL;
	data->map = NULL;
	data->player = 0;
	data->plr_x = 0;
	data->plr_y = 0;
}

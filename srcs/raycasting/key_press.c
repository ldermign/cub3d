/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:11:38 by ejahan            #+#    #+#             */
/*   Updated: 2022/04/10 16:16:06 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_press_w(t_cub *cub)
{
	if (cub->args->map[(int)(cub->pos_x + cub->dir_x * 0.2)][(int)(cub->pos_y)]
			!= '1')
		cub->pos_x += cub->dir_x * 0.2;
	if (cub->args->map[(int)(cub->pos_x)][(int)(cub->pos_y + cub->dir_y * 0.2)]
			!= '1')
		cub->pos_y += cub->dir_y * 0.2;
	draw_img(cub);
}

void	key_press_left(t_cub *cub)
{
	cub->olddir_x = cub->dir_x;
	cub->dir_x = cub->dir_x * cos(0.1) - cub->dir_y * sin(0.1);
	cub->dir_y = cub->olddir_x * sin(0.1) + cub->dir_y * cos(0.1);
	cub->oldplane_x = cub->plane_x;
	cub->plane_x = cub->plane_x * cos(0.1) - cub->plane_y * sin(0.1);
	cub->plane_y = cub->oldplane_x * sin(0.1) + cub->plane_y * cos(0.1);
	draw_img(cub);
}

void	key_press_right(t_cub *cub)
{
	cub->olddir_x = cub->dir_x;
	cub->dir_x = cub->dir_x * cos(-0.1) - cub->dir_y * sin(-0.1);
	cub->dir_y = cub->olddir_x * sin(-0.1) + cub->dir_y * cos(-0.1);
	cub->oldplane_x = cub->plane_x;
	cub->plane_x = cub->plane_x * cos(-0.1) - cub->plane_y * sin(-0.1);
	cub->plane_y = cub->oldplane_x * sin(-0.1) + cub->plane_y * cos(-0.1);
	draw_img(cub);
}

void	key_press_s(t_cub *cub)
{
	if (cub->args->map[(int)(cub->pos_x - cub->dir_x * 0.2)][(int)(cub->pos_y)]
			!= '1')
		cub->pos_x -= cub->dir_x * 0.2;
	if (cub->args->map[(int)(cub->pos_x)][(int)(cub->pos_y - cub->dir_y * 0.2)]
			!= '1')
		cub->pos_y -= cub->dir_y * 0.2;
	draw_img(cub);
}

int	key_press(int key_code, t_struct *all)
{
	if (key_code == KL_ESC)
		ft_quit(all);
	if (key_code == KL_M)
		key_press_m(&(all->cub));
	if (key_code == KL_A)
		key_press_a(&(all->cub));
	if (key_code == KL_S)
		key_press_s(&(all->cub));
	if (key_code == KL_D)
		key_press_d(&(all->cub));
	if (key_code == KL_W)
		key_press_w(&(all->cub));
	if (key_code == KL_LEFT)
		key_press_left(&(all->cub));
	if (key_code == KL_RIGHT)
		key_press_right(&(all->cub));
	return (0);
}

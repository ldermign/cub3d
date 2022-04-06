/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:11:38 by ejahan            #+#    #+#             */
/*   Updated: 2022/04/06 22:42:12 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_press_w(t_cub *cub)
{
	if (cub->map[(int)(cub->posX + cub->dirX * 0.2)][(int)(cub->posY)]
			!= '1')
		cub->posX += cub->dirX * 0.2;
	if (cub->map[(int)(cub->posX)][(int)(cub->posY + cub->dirY * 0.2)]
			!= '1')
		cub->posY += cub->dirY * 0.2;
	test(cub);
}

void	key_press_left(t_cub *cub)
{
	cub->oldDirX = cub->dirX;
	cub->dirX = cub->dirX * cos(0.1) - cub->dirY * sin(0.1);
	cub->dirY = cub->oldDirX * sin(0.1) + cub->dirY * cos(0.1);
	cub->oldPlaneX = cub->planeX;
	cub->planeX = cub->planeX * cos(0.1) - cub->planeY * sin(0.1);
	cub->planeY = cub->oldPlaneX * sin(0.1) + cub->planeY * cos(0.1);
	test(cub);
}

void	key_press_right(t_cub *cub)
{
	cub->oldDirX = cub->dirX;
	cub->dirX = cub->dirX * cos(-0.1) - cub->dirY * sin(-0.1);
	cub->dirY = cub->oldDirX * sin(-0.1) + cub->dirY * cos(-0.1);
	cub->oldPlaneX = cub->planeX;
	cub->planeX = cub->planeX * cos(-0.1) - cub->planeY * sin(-0.1);
	cub->planeY = cub->oldPlaneX * sin(-0.1) + cub->planeY * cos(-0.1);
	test(cub);
}

void	key_press_s(t_cub *cub)
{
	if (cub->map[(int)(cub->posX - cub->dirX * 0.2)][(int)(cub->posY)]
			!= '1')
		cub->posX -= cub->dirX * 0.2;
	if (cub->map[(int)(cub->posX)][(int)(cub->posY - cub->dirY * 0.2)]
			!= '1')
		cub->posY -= cub->dirY * 0.2;
	test(cub);
}

int	key_press(int key_code, t_cub *cub)
{
	if (key_code == KL_ESC)
		ft_quit(cub);
	if (key_code == KL_M)
		key_press_m(cub);
	if (key_code == KL_A)
		key_press_a(cub);
	if (key_code == KL_S)
		key_press_s(cub);
	if (key_code == KL_D)
		key_press_d(cub);
	if (key_code == KL_W)
		key_press_w(cub);
	if (key_code == KL_LEFT)
		key_press_left(cub);
	if (key_code == KL_RIGHT)
		key_press_right(cub);
	return (0);
}

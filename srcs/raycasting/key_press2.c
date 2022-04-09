/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:40:45 by ejahan            #+#    #+#             */
/*   Updated: 2022/04/09 18:41:59 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_press_m(t_cub *cub)
{
	if (cub->mini == 1)
		cub->mini = 0;
	else
		cub->mini = 1;
	draw_img(cub);
}

void	key_press_a(t_cub *cub)
{
	double	a;
	double	b;
	double	c;
	double	d;

	a = acos(cub->dirX);
	if (cub->dirY < 0)
		a = -a;
	b = a - M_PI / 2;
	c = cos(b);
	d = sin(b);
	if (cub->map[(int)(cub->posX - c * 0.2)][(int)(cub->posY
			- d * 0.2)] != '1')
	{
		cub->posX -= c * 0.2;
		cub->posY -= d * 0.2;
	}
	// if (cub->map[(int)(cub->posX)][(int)(cub->posY + cub->dirY * 0.2)]
	// 		!= '1')
	// 	cub->posY += cub->dirY * 0.2;
	draw_img(cub);
}

void	key_press_d(t_cub *cub)
{
	double	a;
	double	b;
	double	c;
	double	d;

	a = acos(cub->dirX);
	if (cub->dirY < 0)
		a = -a;
	b = a - M_PI / 2;
	c = cos(b);
	d = sin(b);
	if (cub->map[(int)(cub->posX + c * 0.2)][(int)(cub->posY + d * 0.2)]
			!= '1')
	{
		cub->posX += c * 0.2;
		cub->posY += d * 0.2;
	}
	// if (cub->map[(int)(cub->posX)][(int)(cub->posY + cub->dirY * 0.2)]
			// != '1')
		// cub->posY += cub->dirY * 0.2;
	draw_img(cub);
}

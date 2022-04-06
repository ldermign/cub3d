/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:08:34 by ejahan            #+#    #+#             */
/*   Updated: 2022/04/06 21:10:46 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_raycast2(t_cub *cub)
{
	if (cub->player == 'W')
	{
		cub->dirX = 0;
		cub->dirY = -1;
		cub->planeX = -0.66;
		cub->planeY = 0;
	}
	else if (cub->player == 'E')
	{
		cub->dirX = 0;
		cub->dirY = 1;
		cub->planeX = 0.66;
		cub->planeY = 0;
	}
}

void	init_raycast(t_cub *cub)
{
	if (cub->player == 'N')
	{
		cub->dirX = -1;
		cub->dirY = 0;
		cub->planeX = 0;
		cub->planeY = 0.66;
	}
	else if (cub->player == 'S')
	{
		cub->dirX = 1;
		cub->dirY = 0;
		cub->planeX = 0;
		cub->planeY = -0.66;
	}
	else
		init_raycast2(cub);
}

void	init2(t_cub *cub, int x)
{
	cub->cameraX = 2 * x / (double)cub->x - 1;
	cub->raydirX = cub->dirX + cub->planeX * cub->cameraX;
	cub->raydirY = cub->dirY + cub->planeY * cub->cameraX;
	cub->mapX = (int)cub->posX;
	cub->mapY = (int)cub->posY;
	cub->hit = 0;
	if (cub->raydirX == 0)
		cub->deltaDistY = 0;
	else
		cub->deltaDistX = fabs(1 / cub->raydirX);
	if (cub->raydirY == 0)
		cub->deltaDistY = 0;
	else
		cub->deltaDistY = fabs(1 / cub->raydirY);
}

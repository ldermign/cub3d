/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:32:54 by ejahan            #+#    #+#             */
/*   Updated: 2022/04/06 21:08:59 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	recup_pos(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == cub->player)
			{
				cub->map[i][j] = '0';
				cub->posX = (double)i + 0.5;
				cub->posY = (double)j + 0.5;
				printf("\033[1;30mposX :\033[0m %f\n", cub->posX);
				printf("\033[1;30mposY :\033[0m %f\n\n", cub->posY);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	step_sidedist(t_cub *cub)
{
	if (cub->raydirX < 0)
	{
		cub->stepX = -1;
		cub->sideDistX = (cub->posX - cub->mapX) * cub->deltaDistX;
	}
	else
	{
		cub->stepX = 1;
		cub->sideDistX = (cub->mapX + 1.0 - cub->posX) * cub->deltaDistX;
	}
	if (cub->raydirY < 0)
	{
		cub->stepY = -1;
		cub->sideDistY = (cub->posY - cub->mapY) * cub->deltaDistY;
	}
	else
	{
		cub->stepY = 1;
		cub->sideDistY = (cub->mapY + 1.0 - cub->posY) * cub->deltaDistY;
	}
}

void	check_wall(t_cub *cub)
{
	while (cub->hit == 0)
	{
		if ((cub->sideDistY <= 0 && cub->sideDistX >= 0)
			|| cub->sideDistX < cub->sideDistY)
		{
			cub->sideDistX += cub->deltaDistX;
			cub->mapX += cub->stepX;
			cub->side = 0;
		}
		else
		{
			cub->sideDistY += cub->deltaDistY;
			cub->mapY += cub->stepY;
			cub->side = 1;
		}
		if (cub->map[cub->mapX][cub->mapY] == '1')
			cub->hit = 1;
	}
}

void	raycast2(t_cub *cub, int color, int x)
{
	if (cub->side == 0)
	{
		cub->perpWallDist = ((double)cub->mapX - cub->posX
				+ (1 - (double)cub->stepX) / 2) / cub->raydirX;
	}
	else
	{
		cub->perpWallDist = ((double)cub->mapY - cub->posY
				+ (1 - (double)cub->stepY) / 2) / cub->raydirY;
	}
	cub->lineHeight = (int)(cub->y / cub->perpWallDist);
	cub->drawStart = -(cub->lineHeight) / 2 + cub->y / 2;
	if (cub->drawStart < 0)
		cub->drawStart = 0;
	cub->drawEnd = cub->lineHeight / 2 + cub->y / 2;
	if (cub->drawEnd >= cub->y)
		cub->drawEnd = cub->y - 1;
	if (cub->side == 1)
		color /= 2;
	while (cub->drawStart < cub->drawEnd)
	{
		my_mlx_pixel_put(cub, x, cub->drawStart, color);
		cub->drawStart++;
	}
}

void	raycast1(t_cub *cub)
{
	int	x;
	int	color;

	x = 0;
	while (x < cub->x)
	{
		cub->side = 0;
		init2(cub, x);
		step_sidedist(cub);
		check_wall(cub);
		color = create_trgb(24, 90, 130, 120);
		raycast2(cub, color, x);
		x++;
	}
}

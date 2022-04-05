/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:32:54 by ejahan            #+#    #+#             */
/*   Updated: 2022/04/05 17:22:28 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->addr + (y * cub->line_length + x * (cub->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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
	else if (cub->player == 'W')
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
		if (cub->side == 0)
			cub->perpWallDist = ((double)cub->mapX - cub->posX + (1 - (double)cub->stepX) / 2) / cub->raydirX;
		else
			cub->perpWallDist = ((double)cub->mapY - cub->posY + (1 - (double)cub->stepY) / 2) / cub->raydirY;
		cub->lineHeight = (int)(cub->y / cub->perpWallDist);
		cub->drawStart = -(cub->lineHeight) / 2 + cub->y / 2;
		if (cub->drawStart < 0)
			cub->drawStart = 0;
		cub->drawEnd = cub->lineHeight / 2 + cub->y / 2;
		if (cub->drawEnd >= cub->y)
			cub->drawEnd = cub->y - 1;
		color = create_trgb(24, 90, 130, 120);
		if (cub->side == 1)
			color /= 2;
		while (cub->drawStart < cub->drawEnd)
		{
			my_mlx_pixel_put(cub, x, cub->drawStart, color);
			cub->drawStart++;
		}
		x++;
	}
}

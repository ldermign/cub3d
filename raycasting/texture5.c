/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:14:03 by ejahan            #+#    #+#             */
/*   Updated: 2021/06/11 15:15:45 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->addr + (y * cub->line_length + x * (cub->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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
	cub->mini = 0;
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

void	raycast1(t_cub *cub)
{
	int	x;
	int	y;
	int	color;
	// char	buffer[cub->x][cub->y];

	x = 0;
	y = 0;
	cub->texture_no = mlx_xpm_file_to_image(cub->mlx, cub->north,
				&(cub->width), &(cub->height));
	cub->texture_ea = mlx_xpm_file_to_image(cub->mlx, cub->east,
				&(cub->width), &(cub->height));
	cub->texture_we = mlx_xpm_file_to_image(cub->mlx, cub->west,
				&(cub->width), &(cub->height));
	cub->texture_so = mlx_xpm_file_to_image(cub->mlx, cub->south,
				&(cub->width), &(cub->height));
	if (!(cub->texture_no) || !(cub->texture_ea) ||
				!(cub->texture_so) || !(cub->texture_we))
		ft_quit(cub);
	// cub->addr2 = mlx_get_data_addr(cub->texture_no,
	// 		&cub->bits_per_pixel, &cub->line_length, &cub->endian);
	while (x < cub->x)
	{
		cub->side = 0;
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
		while (cub->hit == 0)
		{
			if ((cub->sideDistY <= 0 && cub->sideDistX >= 0) ||
					cub->sideDistX < cub->sideDistY)
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
		if (cub->side == 0)
			cub->perpWallDist = ((double)cub->mapX - cub->posX +
					(1 - (double)cub->stepX) / 2) / cub->raydirX;
		else
			cub->perpWallDist = ((double)cub->mapY - cub->posY +
					(1 - (double)cub->stepY) / 2) / cub->raydirY;
		cub->lineHeight = (int)(cub->y / cub->perpWallDist);
		cub->drawStart = -(cub->lineHeight) / 2 + cub->y / 2;
		if (cub->drawStart < 0)
			cub->drawStart = 0;
		cub->drawEnd = cub->lineHeight / 2 + cub->y / 2;
		if (cub->drawEnd >= cub->y)
			cub->drawEnd = cub->y - 1;
		// cub->texNum = cub->map[cub->mapX][cub->mapY] - 1;
		if (cub->side == 0)
	  		cub->wallX = cub->posY + cub->perpWallDist * cub->raydirY;
		else
		  	cub->wallX = cub->posX + cub->perpWallDist * cub->raydirX;
		cub->wallX -= floor((cub->wallX));
		cub->texX = (int)(cub->wallX * (double)(cub->texWidth));
		if (cub->side == 0 && cub->raydirX > 0)
			cub->texX = cub->texWidth - cub->texX - 1;
		if (cub->side == 1 && cub->raydirY < 0)
			cub->texX = cub->texWidth - cub->texX - 1;
		cub->step = 1.0 * cub->texHeight / cub->lineHeight;
		cub->texPos = (cub->drawStart - cub->y / 2 + cub->lineHeight / 2) * cub->step;
		y = cub->drawStart;
		while (y < cub->drawEnd)
		{
			cub->texY = (int)cub->texPos & (cub->texHeight - 1);
			cub->texPos += cub->step;
			color = (int)&(cub->texture_no[cub->texHeight * cub->texY + cub->texX]);
			if (cub->side == 1)
				color /= 2;
			// buffer[y][x] = color;
			my_mlx_pixel_put(cub, x, y, color);
			y++;
		}
		x++;
		// while (cub->drawStart < cub->drawEnd)
		// {
		// 	my_mlx_pixel_put(cub, x, cub->drawStart, color);
		// 	cub->drawStart++;
		// }
	}
}

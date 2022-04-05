/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:21:21 by ejahan            #+#    #+#             */
/*   Updated: 2021/06/03 17:45:59 by ejahan           ###   ########.fr       */
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
	int	i;
	unsigned int	color;
	// unsigned long	width;
	// unsigned long	height;
	int	*texture[8];
	// char	buffer[cub->y][cub->x];

	x = 0;
	y = 0;
	i = 0;
	cub->texHeight = 64;
	cub->texWidth = 64;
	while (i < 8)
	{
		texture[i] = malloc((sizeof(char) * (cub->texWidth * cub->texHeight)));
		if (cub->texture[i] == NULL)
		{
			printf("error malloc\n");
			return ;
		}
		i++;
	}
	// mlx_xpm_file_to_image(cub->mlx_ptr, cub->north, &width, &height);
	while (x < cub->texWidth && y < cub->texHeight)
	{
		int xorcolor = (x * 256 / cub->texWidth) ^ (y * 256 / cub->texHeight);
		//int xcolor = x * 256 / texWidth;
		int ycolor = y * 256 / cub->texHeight;
		int xycolor = y * 128 / cub->texHeight + x * 128 / cub->texWidth;
		texture[0][cub->texWidth * y + x] = 65536 * 254 * (x != y && x != cub->texWidth - y);
		texture[1][cub->texWidth * y + x] = xycolor + 256 * xycolor + 65536 * xycolor;
		texture[2][cub->texWidth * y + x] = 256 * xycolor + 65536 * xycolor;
		texture[3][cub->texWidth * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor;
		texture[4][cub->texWidth * y + x] = 256 * xorcolor;
		texture[5][cub->texWidth * y + x] = 65536 * 192 * (x % 16 && y % 16);
		texture[6][cub->texWidth * y + x] = 65536 * ycolor;
		texture[7][cub->texWidth * y + x] = (char)(128 + (256 * 128) + (65536 * 128));
		x++;
		y++;
	}

	// while (x < cub->texWidth)
	// {
	// 	while (y < cub->texHeight)
	// 	{
	// 	int xorcolor = (x * 256 / cub->texWidth) ^ (y * 256 / cub->texHeight);
	// 	//int xcolor = x * 256 / texWidth;
	// 	int ycolor = y * 256 / cub->texHeight;
	// 	int xycolor = y * 128 / cub->texHeight + x * 128 / cub->texWidth;
	// 	texture[0][cub->texWidth * y + x] = 65536 * 254 * (x != y && x != cub->texWidth - y); //flat red texture with black cross
	// 	texture[1][cub->texWidth * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
	// 	texture[2][cub->texWidth * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
	// 	texture[3][cub->texWidth * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
	// 	texture[4][cub->texWidth * y + x] = 256 * xorcolor; //xor green
	// 	texture[5][cub->texWidth * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
	// 	texture[6][cub->texWidth * y + x] = 65536 * ycolor; //red gradient
	// 	texture[7][cub->texWidth * y + x] = (char)(128 + (256 * 128) + (65536 * 128)); //flat grey texture
	// 	y++;
	// 	}
	// x++;
	// }
	x = 0;
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
			if ((cub->sideDistY <= 0 && cub->sideDistX >= 0) || cub->sideDistX < cub->sideDistY)
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
		cub->texNum = cub->map[cub->mapX][cub->mapY] - 1;
		if (cub->side == 0)
			cub->wallX = cub->posY + cub->perpWallDist * cub->raydirY;
		else
			cub->wallX = cub->posX + cub->perpWallDist * cub->raydirX;
		cub->wallX -= floor((cub->wallX));
		cub->texX = (int)(cub->wallX * (double)cub->texWidth);
		if(cub->side == 0 && cub->raydirX > 0)
			cub->texX = cub->texWidth - cub->texX - 1;
		if(cub->side == 1 && cub->raydirY < 0)
			cub->texX = cub->texWidth - cub->texX - 1;
		cub->step = 1.0 * cub->texHeight / cub->lineHeight;
		cub->texPos = (cub->drawStart - cub->x / 2 + cub->lineHeight / 2) * cub->step;
		// int test = cub->drawStart;
		// while (test < cub->drawEnd)
		// {
		// 	my_mlx_pixel_put(cub, x, test, 456);
		// 	test++;
		// }
		y = cub->drawStart;
		while (y < cub->drawEnd)
		{
			cub->texY = (int)cub->texPos & (cub->texHeight - 1);
			cub->texPos += cub->step;
			color = (int)texture[0][cub->texHeight * cub->texY + cub->texX];
			// if (cub->side == 1)
			// 	color = 321654;
			// buffer[y][x] = color;
			my_mlx_pixel_put(cub, x, y, color);
			y++;
		}
		// color = create_trgb(24, 90, 130, 120);
		// if (cub->side == 1)
		// 	color /= 2;
		// while (cub->drawStart < cub->drawEnd)
		// {
		// 	my_mlx_pixel_put(cub, x, cub->drawStart, color);
		// 	cub->drawStart++;
		// }
		x++;
	}
}


	// x = 0;

	// 	unsigned long tw, th;
	// 	loadImage(texture[0], tw, th, cub->north);
	// 	loadImage(texture[1], tw, th, cub->south);
	// 	loadImage(texture[2], tw, th, cub->east);
	// 	loadImage(texture[3], tw, th, cub->west);



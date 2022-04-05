/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:58:13 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/05 17:21:46 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void 	draw_line_wall(int x, int start, int end, int side)
// {
// 	int	color;

// 	color = create_trgb(1, 255, 255, 255);
// 	if (side == 1)
// 		color = create_trgb(1, 200, 50, 100);
// 	while (start < end)
// 	{
// 		my_mlx_pixel_put(s()->img, x, start, color);
// 		start++;
// 		// if (x == 249 || x == 250 || x == 251)
// 		// 	printf("x = [%d].", x);
// 	}
// }

// void	which_square_with_wall_DDA(t_calc *clcls, t_arg *data)
// {
// 	while (clcls->hit == 0)
// 	{
// 		if (clcls->sideDistX < clcls->sideDistY)
// 		{
// 			clcls->sideDistX += clcls->deltaDistX;
// 			clcls->mapX += clcls->stepX;
// 			clcls->side = 0;
// 		}
// 		else
// 		{
// 			clcls->sideDistY += clcls->deltaDistY;
// 			clcls->mapY += clcls->stepY;
// 			clcls->side = 1;
// 		}
// 		if (data->map[clcls->mapX][clcls->mapY] == '1')
// 			clcls->hit = 1;
// 	}
// }

// void	distance_camera_calculs(t_mlx *img, t_calc *clcls)
// {
// 	int	lineHeight;

// 	if (clcls->side == 0)
// 		clcls->perpWallDist = (clcls->mapX - clcls->plrX
// 				+ (1 - clcls->stepX) / 2) / clcls->rayDirX;
// 	else
// 		clcls->perpWallDist = (clcls->mapY - clcls->plrY
// 				+ (1 - clcls->stepY) / 2) / clcls->rayDirY;
// 	lineHeight = (int)(img->height / clcls->perpWallDist);
// 	clcls->drawStart = -lineHeight / 2 + img->height / 2;
// 	clcls->drawEnd = lineHeight / 2 + img->height / 2;
// 	if (clcls->drawStart < 0)
// 		clcls->drawStart = 0;
// 	if (clcls->drawEnd >= img->height)
// 		clcls->drawEnd = img->height - 1;
// }

// void	init_calculs(t_mlx *img, t_calc *clcls, int i)
// {
// 	clcls->hit = 0;
// 	clcls->mapX = (int)(clcls->plrX);
// 	clcls->mapY = (int)(clcls->plrY);
// 	clcls->cameraX = 2 * i / (double)(img->width) - 1;
// 	clcls->rayDirX = clcls->dirX + clcls->planeX * clcls->cameraX;
// 	clcls->rayDirY = clcls->dirY + clcls->planeY * clcls->cameraX;
// 	if (clcls->rayDirX == 0)
// 		clcls->deltaDistY = 0;
// 	else
// 		clcls->deltaDistX = fabs(1 / clcls->rayDirX);
// 	if (clcls->rayDirY == 0)
// 		clcls->deltaDistY = 0;
// 	else
// 		clcls->deltaDistY = fabs(1 / clcls->rayDirY);
// 	// texture(img, clcls, s()->data);
// }


// void	fill_sky_and_floor(t_mlx *img)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	while (x < img->width)
// 	{
// 		y = 0;
// 		while (y < img->height / 2)
// 		{
// 			my_mlx_pixel_put(img, x, y, img->sky);
// 			++y;
// 		}
// 		while (y < img->height)
// 		{
// 			my_mlx_pixel_put(img, x, y, img->floor);
// 			++y;
// 		}
// 		++x;
// 	}
// }


// void	step_calculs(t_calc *clc)
// {
// 	if (clc->rayDirX < 0)
// 	{
// 		clc->stepX = -1;
// 		clc->sideDistX = (clc->plrX - clc->mapX) * clc->deltaDistX;
// 	}
// 	else
// 	{
// 		clc->stepX = 1;
// 		clc->sideDistX = (clc->mapX + 1.0 - clc->plrX) * clc->deltaDistX;
// 	}
// 	if (clc->rayDirY < 0)
// 	{
// 		clc->stepY = -1;
// 		clc->sideDistY = (clc->plrY - clc->mapY) * clc->deltaDistY;
// 	}
// 	else
// 	{
// 		clc->stepY = 1;
// 		clc->sideDistY = (clc->mapY + 1.0 - clc->plrY) * clc->deltaDistY;
// 	}
// }

// int	all_calculs_cub(t_mlx *img, t_calc *cls, t_arg *data)
// {
// 	int	i;

// 	i = 0;
// 	fill_sky_and_floor(img);
// 	while (i < img->width)
// 	{
// 		init_calculs(img, cls, i);
// 		step_calculs(cls);
// 		which_square_with_wall_DDA(cls, data);
// 		distance_camera_calculs(img, cls);
// 		draw_line_wall(i, cls->drawStart, cls->drawEnd, cls->side);
// 		i++;
// 	}
// 	mlx_put_image_to_window(s()->img->mlx, s()->img->win, s()->img->img, 0, 0);
// 	return (0);
// }
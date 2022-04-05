/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:52:13 by ejahan            #+#    #+#             */
/*   Updated: 2021/04/15 16:34:17 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_cub(t_cub *cub)
{
	cub->posX = 0;
	cub->posY = 0;
	cub->dirX = -1;
	cub->dirY = 0;
	cub->planeX = 0;
	cub->planeY = 0.66;
	cub->time = 0;
	cub->oldtime = 0;
	cub->drawEnd = 0;
	cub->drawStart = 0;
}

void	recup_pos(t_map *map, t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == map->player)
			{
				cub->posX = (double)j;
				cub->posY = (double)i;
				printf("\033[1;30mposX :\033[0m %f\n\033[1;30mposY :\033[0m %f\n\n", cub->posX, cub->posY);
				return ;
			}
			j++;
		}
		i++;
	}
}

// void	recup_angle(t_map *map, t_cub *cub)
// {
// 	if (map->player == 'N')
// 		cub->angle = M_PI_2;
// 	if (map->player == 'W')
// 		cub->angle = M_PI;
// 	if (map->player == 'S')
// 		cub->angle = 3 * M_PI_2;
// 	if (map->player == 'E')
// 		cub->angle = 2 * M_PI;
// }

// void	init_raycasting(t_cub *cub)
// {
// 	cub->mapX = floor(cub->posX);
// 	cub->mapY = floor(cub->posY);
// 	cub->deltaDistX = sqrt(1 + pow(cub->dirY, 2) / pow(cub->dirX, 2));
// 	cub->deltaDistY = sqrt(1 + pow(cub->dirX, 2) / pow(cub->dirY, 2));
// 	if (cub->dirX < 0)
// 	{
// 		cub->stepX = -1;
// 		cub->sideDistX = (cub->posX - cub->mapX) * cub->deltaDistX;
// 	}
// 	else
// 	{
// 		cub->stepX = 1;
// 		cub->sideDistX = (cub->mapX + 1 - cub->posX) * cub->deltaDistX;
// 	}
// 	if (cub->dirY < 0)
// 	{
// 		cub->stepY = -1;
// 		cub->sideDistY = (cub->posY - cub->mapY) * cub->deltaDistY;
// 	}
// 	else
// 	{
// 		cub->stepY = 1;
// 		cub->sideDistY = (cub->mapY + 1 - cub->posY) * cub->deltaDistY;
// 	}
// }

// void            my_mlx_pixel_put(t_img *img, t_cub *cub, t_map *map, int x, int color)
// {
//     char    *dst;
// 	int		y;

// 	y = map->x / 2 - (map->x / 4) / cub->perpWallDist;
// 	printf("%f\n", cub->perpWallDist);
// 	printf("dirX : %f\n", cub->dirX);
// 	// printf("%d\n", y);
// 	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }
	
// line(i, map->x / 2 - (map->x / 4) / cub->perpWallDist, i, map->x / 2 +
//  (map->x / 4) / cub->perpWallDist, color);



// void	raycast(t_cub *cub, t_map *map, t_img *img)
// {
// 	int	i;
// 	int	j;
// 	int	hit;
// 	int	side;
// 	int	color;

// 	hit = 0;
// 	side = 0;
// 	i = map->x;
// 	recup_angle(map, cub);
// 	while (i > 0)
// 	{
// 		j = (i - (map->x / 2)) / (map->x / 2);
// 		cub->dirX = cos(cub->angle) / 2 + cos(cub->angle - 0.25) * j;
// 		cub->dirY = sin(cub->angle) / 2 + sin(cub->angle - 0.25) * j;
// 		init_raycasting(cub);
// 		while (hit == 0)
// 		{
// 			if ((cub->sideDistX >= 0 || cub->sideDistY <= 0) && cub->sideDistX < cub->sideDistY)
// 			{
// 				cub->sideDistX += cub->deltaDistX;
// 				cub->mapX = cub->mapX + cub->stepX;
// 				side = 0;
// 			}
// 			else
// 			{
// 				cub->sideDistY += cub->deltaDistY;
// 				cub->mapY = cub->mapY + cub->stepY;
// 				side = 1;
// 			}
// 			if (map->map[cub->mapY][cub->mapX] != 0)
// 				hit = 1;
// 		}
// 		if (side == 0)
// 			cub->perpWallDist = (cub->mapX - cub->posX + (1 - cub->stepX) / 2) / cub->dirX;
// 		else
// 			cub->perpWallDist = (cub->mapY - cub->posY + (1 - cub->stepY) / 2) / cub->dirY;
// 		if (side == 0)
// 			color = create_trgb(24, 250, 0, 0);
// 		else
// 			color = create_trgb(24, 250, 0, 0);
// 		// printf("%d\n", i);
// 		my_mlx_pixel_put(img, cub, map, i, color);
// 		i--;
// 		// line(i, map->x / 2 - (map->x / 4) / cub->perpWallDist, i, map->x / 2 + (map->x / 4) / cub->perpWallDist, color);	
// 	}
// 	mlx_put_image_to_window(img->mlx, img->mlx_ptr, img->img, 0, 0);
// }

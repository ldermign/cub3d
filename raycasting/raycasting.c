/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:20:26 by ejahan            #+#    #+#             */
/*   Updated: 2021/04/27 17:10:00 by ejahan           ###   ########.fr       */
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
	// cub->time = 0;
	// cub->oldtime = 0;
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
				printf("\033[1;30mposX :\033[0m %f\n", cub->posX);
				printf("\033[1;30mposY :\033[0m %f\n\n", cub->posY);				return ;
			}
			j++;
		}
		i++;
	}
}

int		first_calcul(t_cub *cub, t_map *map, t_img *img)
{
	int	x;
	int hit;
	int side;
	int lineHeight;

	hit = 0;
	side = 0;
	x = 0;
	while (x < map->x)
	{
		cub->cameraX = 2 * x / (double)map->x - 1;
		cub->raydirX = cub->dirX + cub->planeX * cub->cameraX;
		cub->raydirY = cub->dirY + cub->planeY * cub->cameraX;
		cub->mapX = cub->posX;
		cub->mapY = cub->posY;
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
		while (hit == 0)
		{
			if (cub->sideDistX < cub->sideDistY)
			{
				cub->sideDistX += cub->deltaDistX;
				cub->mapX += cub->stepX;
				side = 0;
		}
		else
		{
			cub->sideDistY += cub->deltaDistY;
			cub->mapY += cub->stepY;
			side = 1;
		}
		if (map->map[cub->mapX][cub->mapY] > 0)
			hit = 1;
		}
		if (side == 0)
			cub->perpWallDist = (cub->mapX - cub->posX + (1 - cub->stepX) / 2) / cub->raydirX;
		else
			cub->perpWallDist = (cub->mapY - cub->posY + (1 - cub->stepY) / 2) / cub->raydirY;
		lineHeight = (int)(map->y / cub->perpWallDist);
		cub->drawStart = -lineHeight / 2 + map->y / 2;
		if (cub->drawStart < 0)
			cub->drawStart = 0; 
		cub->drawEnd = lineHeight / 2 + map->y / 2;
		if (cub->drawEnd >= map->y)
			cub->drawEnd = map->y - 1;
	// time(cub, map, img, x);
		mlx_put_image_to_window(img->mlx, img->mlx_ptr, img->img, 0, 0);
		x++;
	}
	my_mlx_pixel_put(img, x, cub->drawEnd, create_trgb(24, 250, 0, 0));
	return (0);
}


    //   //choose wall color
    //   ColorRGB color;
    //   switch(worldMap[mapX][mapY])
    //   {
    //     case 1:  color = RGB_Red;  break; //red
    //     case 2:  color = RGB_Green;  break; //green
    //     case 3:  color = RGB_Blue;   break; //blue
    //     case 4:  color = RGB_White;  break; //white
    //     default: color = RGB_Yellow; break; //yellow
    //   }

    //   //give x and y sides different brightness
    //   if (side == 1) {color = color / 2;}

    //   //draw the pixels of the stripe as a vertical line
    //   verLine(x, drawStart, drawEnd, color);
    // }
	
void            my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char    *dst;

    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}
	
void	time(t_cub *cub, t_map *map, t_img *img, int x)
{
	(void)map;
	(void)img;
	int		i;

	i = cub->drawEnd;
	printf("end : %d\n", cub->drawEnd);
	printf("start : %d\n\n", cub->drawStart);
	// cub->oldtime = cub->time;
	// cub->time = getTicks();
	// cub->frameTime = (cub->time - cub->oldtime) / 1000.0;
	printf("%f\n", 1.0 / cub->frameTime);
	// redraw();
	// my_mlx_pixel_put(img, cub->posX, cub->posY, 123465);
	while (i > cub->drawStart)
	{
		printf("fuck\n");
		my_mlx_pixel_put(img, x, i, create_trgb(24, 250, 0, 0));
		i--;
	}
	// if(!(map->map[(int)(cub->posX + cub->dirX * cub->moveSpeed)][(int)(cub->posY)]))
	// 	cub->posX += cub->dirX * cub->moveSpeed;
    // if(!(map->map[(int)(cub->posX)][(int)(cub->posY + cub->dirY * cub->moveSpeed)]))
	// 	cub->posY += cub->dirY * cub->moveSpeed;
	// cls();
	cub->moveSpeed = cub->frameTime * 5.0;
	cub->rotSpeed = cub->frameTime * 3.0;
}

//     readKeys();
//     //move forward if no wall in front of you
//     if (keyDown(SDLK_UP))
//     {
//       if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
//       if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
//     }
//     //move backwards if no wall behind you
//     if (keyDown(SDLK_DOWN))
//     {
//       if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
//       if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
//     }
//     //rotate to the right
//     if (keyDown(SDLK_RIGHT))
//     {
//       //both camera direction and camera plane must be rotated
//       double oldDirX = dirX;
//       dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
//       dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
//       double oldPlaneX = planeX;
//       planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
//       planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
//     }
//     //rotate to the left
//     if (keyDown(SDLK_LEFT))
//     {
//       //both camera direction and camera plane must be rotated
//       double oldDirX = dirX;
//       dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
//       dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
//       double oldPlaneX = planeX;
//       planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
//       planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
//     }
//   }
// }

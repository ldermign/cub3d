/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:32:54 by ejahan            #+#    #+#             */
/*   Updated: 2022/04/13 16:14:22 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	recup_pos(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cub->args->map[i])
	{
		j = 0;
		while (cub->args->map[i][j])
		{
			if (cub->args->map[i][j] == cub->args->player)
			{
				cub->args->map[i][j] = '0';
				cub->pos_x = (double)i + 0.5;
				cub->pos_y = (double)j + 0.5;
				printf("\033[1;30mposX :\033[0m %f\n", cub->pos_x);
				printf("\033[1;30mposY :\033[0m %f\n\n", cub->pos_y);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	step_sidedist(t_cub *cub)
{
	if (cub->raydir_x < 0)
	{
		cub->step_x = -1;
		cub->side_dist_x = (cub->pos_x - cub->map_x) * cub->delta_dist_x;
	}
	else
	{
		cub->step_x = 1;
		cub->side_dist_x = (cub->map_x + 1.0 - cub->pos_x) * cub->delta_dist_x;
	}
	if (cub->raydir_y < 0)
	{
		cub->step_y = -1;
		cub->side_dist_y = (cub->pos_y - cub->map_y) * cub->delta_dist_y;
	}
	else
	{
		cub->step_y = 1;
		cub->side_dist_y = (cub->map_y + 1.0 - cub->pos_y) * cub->delta_dist_y;
	}
}

void	check_wall(t_cub *cub)
{
	while (cub->hit == 0)
	{
		if ((cub->side_dist_y <= 0 && cub->side_dist_x >= 0)
			|| cub->side_dist_x < cub->side_dist_y)
		{
			cub->side_dist_x += cub->delta_dist_x;
			cub->map_x += cub->step_x;
			cub->side = 0;
		}
		else
		{
			cub->side_dist_y += cub->delta_dist_y;
			cub->map_y += cub->step_y;
			cub->side = 1;
		}
		if (cub->args->map[cub->map_x][cub->map_y] == '1')
			cub->hit = 1;
	}
}

// void	raycast2(t_cub *cub, int color, int x)
// {
// 	if (cub->side == 0)
// 	{
// 		cub->perp_wall_dist = ((double)cub->map_x - cub->pos_x
// 				+ (1 - (double)cub->step_x) / 2) / cub->raydir_x;
// 	}
// 	else
// 	{
// 		cub->perp_wall_dist = ((double)cub->map_y - cub->pos_y
// 				+ (1 - (double)cub->step_y) / 2) / cub->raydir_y;
// 	}
// 	cub->lineheight = (int)(cub->y / cub->perp_wall_dist);
// 	cub->drawstart = -(cub->lineheight) / 2 + cub->y / 2;
// 	if (cub->drawstart < 0)
// 		cub->drawstart = 0;
// 	cub->drawend = cub->lineheight / 2 + cub->y / 2;
// 	if (cub->drawend >= cub->y)
// 		cub->drawend = cub->y - 1;
	
// // /////////////////////////////////////////////////////////////////////////////////////////

// 	int buffer[WIDTH][HEIGHT];
// 	//calculate value of wallX
// 	//where exactly the wall was hit
// 	double wallX;
// 	if (cub->side == 0)
// 		wallX = cub->pos_y + cub->perp_wall_dist * cub->raydir_y;
// 	else
// 		wallX = cub->pos_x + cub->perp_wall_dist * cub->raydir_x;
// 	wallX -= floor((wallX));

// 	//x coordinate on the texture
// 	int texX = (int)(wallX * (double)64);
// 	if (cub->side == 0 && cub->raydir_x > 0)
// 		texX = 64 - texX - 1;
// 	if (cub->side == 1 && cub->raydir_y < 0)
// 		texX = 64 - texX - 1;

// 	double step = 1.0 * 64 / cub->lineheight;

// 	// Starting texture coordinate
// 	double texPos = (cub->drawstart - cub->y / 2 + cub->lineheight / 2) * step;
// 	for (int y = cub->drawstart ; y < cub->drawend ; y++)
// 	{
// 		// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
// 		int texY = (int)texPos & (64 - 1);
// 		texPos += step;

// 		color = cub->text.txt_test[64 * texY + texX];
// 		//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"

// 		if (cub->side == 1)
// 			color = (color >> 1) & 8355711;
// 		buffer[y][x] = color;
// 	}

// // /////////////////////////////////////////////////////////////////////////////////////////

// 	if (cub->side == 1)
// 		color /= 2;
// 	while (cub->drawstart <= cub->drawend)
// 	{
// 		my_mlx_pixel_put(cub, x, cub->drawstart, color);
// 		cub->drawstart++;
// 	}
// }

int		get_which_texture(t_cub *cub)
{
	int	text;

	text = 0;
	if (cub->side == 0 && cub->raydir_x < 0)
		text = 0;	//	north
	if (cub->side == 0 && cub->raydir_x >= 0)
		text = 1;	//	south
	if (cub->side == 1 && cub->raydir_x < 0)
		text = 2;	//	east
	if (cub->side == 1 && cub->raydir_x >= 0)
		text = 3;	//	west
	return (text);
}

void	raycast2(t_cub *cub, int color, int x)
{
	// int	test = 0;
	int y;

	if (cub->side == 0)
	{
		cub->perp_wall_dist = ((double)cub->map_x - cub->pos_x
				+ (1 - (double)cub->step_x) / 2) / cub->raydir_x;
	}
	else
	{
		cub->perp_wall_dist = ((double)cub->map_y - cub->pos_y
				+ (1 - (double)cub->step_y) / 2) / cub->raydir_y;
	}
	cub->lineheight = (int)(cub->y / cub->perp_wall_dist);
	cub->drawstart = -(cub->lineheight) / 2 + cub->y / 2;
	if (cub->drawstart < 0)
		cub->drawstart = 0;
	cub->drawend = cub->lineheight / 2 + cub->y / 2;
	if (cub->drawend >= cub->y)
		cub->drawend = cub->y - 1;
////////////////////////////////////////////////////////////////////////////////////////////
	cub->text.texnum = get_which_texture(cub);
	// cub->text.texnum = cub->args->map[cub->map_x][cub->map_y] - 1;
	// cub->text.texnum = 1;
	if (cub->side == 0)
		cub->wall_x = cub->pos_y + cub->perp_wall_dist * cub->raydir_y;
	else
		cub->wall_x = cub->pos_x + cub->perp_wall_dist * cub->raydir_x;
	cub->wall_x -= floor((cub->wall_x));
	cub->text.tex_x = (int)(cub->wall_x * (double)cub->all_txt[cub->text.texnum].tex_width);
	if (cub->side == 0 && cub->raydir_x > 0)
		cub->text.tex_x = cub->all_txt[cub->text.texnum].tex_width - cub->text.tex_x - 1;
	if (cub->side == 1 && cub->raydir_y < 0)
		cub->text.tex_x = cub->all_txt[cub->text.texnum].tex_width - cub->text.tex_x - 1;
	cub->step = 1.0 * cub->all_txt[cub->text.texnum].tex_height / cub->lineheight;
	cub->text.texpos = (cub->drawstart - cub->y / 2 + cub->lineheight / 2) * cub->step;
	y = cub->drawstart;
	while (y <= cub->drawend)
	{
		cub->text.tex_y = (int)cub->text.texpos & (cub->all_txt[cub->text.texnum].tex_height - 1);
		cub->text.texpos += cub->step;
		color = cub->all_txt[cub->text.texnum].text[cub->all_txt[cub->text.texnum].tex_height * cub->text.tex_y + cub->text.tex_x];
		if (cub->side == 1)
			color = (color >> 1) & 8355711;
		my_mlx_pixel_put(cub, x, y, color);
		y++;
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

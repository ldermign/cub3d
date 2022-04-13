/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:32:54 by ejahan            #+#    #+#             */
/*   Updated: 2022/04/13 20:15:25 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	raycast3(t_cub *cub, int color, int x)
{
	if (cub->side == 0)
		cub->wall_x = cub->pos_y + cub->perp_wall_dist * cub->raydir_y;
	else
		cub->wall_x = cub->pos_x + cub->perp_wall_dist * cub->raydir_x;
	cub->wall_x -= floor((cub->wall_x));
	cub->text.tex_x = (int)(cub->wall_x
			* (double)cub->all_txt[cub->text.texnum].tex_width);
	if (cub->side == 0 && cub->raydir_x > 0)
		cub->text.tex_x = cub->all_txt[cub->text.texnum].tex_width
			- cub->text.tex_x - 1;
	if (cub->side == 1 && cub->raydir_y < 0)
		cub->text.tex_x = cub->all_txt[cub->text.texnum].tex_width
			- cub->text.tex_x - 1;
	cub->step = 1.0 * cub->all_txt[cub->text.texnum].tex_height
		/ cub->lineheight;
	cub->text.texpos = (cub->drawstart - cub->y / 2 + cub->lineheight / 2)
		* cub->step;
	put_line(cub, color, x);
}

void	raycast2(t_cub *cub, int color, int x)
{
	if (cub->side == 0)
		cub->perp_wall_dist = ((double)cub->map_x - cub->pos_x
				+ (1 - (double)cub->step_x) / 2) / cub->raydir_x;
	else
		cub->perp_wall_dist = ((double)cub->map_y - cub->pos_y
				+ (1 - (double)cub->step_y) / 2) / cub->raydir_y;
	cub->lineheight = (int)(cub->y / cub->perp_wall_dist);
	cub->drawstart = -(cub->lineheight) / 2 + cub->y / 2;
	if (cub->drawstart < 0)
		cub->drawstart = 0;
	cub->drawend = cub->lineheight / 2 + cub->y / 2;
	if (cub->drawend >= cub->y)
		cub->drawend = cub->y - 1;
	cub->text.texnum = get_which_texture(cub);
	raycast3(cub, color, x);
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

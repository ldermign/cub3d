/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:08:34 by ejahan            #+#    #+#             */
/*   Updated: 2022/04/10 16:14:09 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_raycast2(t_cub *cub)
{
	if (cub->args->player == 'W')
	{
		cub->dir_x = 0;
		cub->dir_y = -1;
		cub->plane_x = -0.66;
		cub->plane_y = 0;
	}
	else if (cub->args->player == 'E')
	{
		cub->dir_x = 0;
		cub->dir_y = 1;
		cub->plane_x = 0.66;
		cub->plane_y = 0;
	}
}

void	init_raycast(t_cub *cub)
{
	if (cub->args->player == 'N')
	{
		cub->dir_x = -1;
		cub->dir_y = 0;
		cub->plane_x = 0;
		cub->plane_y = 0.66;
	}
	else if (cub->args->player == 'S')
	{
		cub->dir_x = 1;
		cub->dir_y = 0;
		cub->plane_x = 0;
		cub->plane_y = -0.66;
	}
	else
		init_raycast2(cub);
}

void	init2(t_cub *cub, int x)
{
	cub->camera_x = 2 * x / (double)cub->x - 1;
	cub->raydir_x = cub->dir_x + cub->plane_x * cub->camera_x;
	cub->raydir_y = cub->dir_y + cub->plane_y * cub->camera_x;
	cub->map_x = (int)cub->pos_x;
	cub->map_y = (int)cub->pos_y;
	cub->hit = 0;
	if (cub->raydir_x == 0)
		cub->delta_dist_y = 0;
	else
		cub->delta_dist_x = fabs(1 / cub->raydir_x);
	if (cub->raydir_y == 0)
		cub->delta_dist_y = 0;
	else
		cub->delta_dist_y = fabs(1 / cub->raydir_y);
}

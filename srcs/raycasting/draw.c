/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 19:55:13 by ejahan            #+#    #+#             */
/*   Updated: 2022/04/10 20:08:57 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_background(t_cub *cub, int x, int y)
{
	char	*dst;
	int		a;
	int		b;

	a = 0;
	while (a < x)
	{
		b = 0;
		while (b < y / 2)
		{
			dst = cub->img_mlx->addr + (b * cub->img_mlx->size_line
					+ a * (cub->img_mlx->bpp / 8));
			*(unsigned int *)dst = cub->args->c;
			b++;
		}
		while (b < y)
		{
			dst = cub->img_mlx->addr + (b * cub->img_mlx->size_line
					+ a * (cub->img_mlx->bpp / 8));
			*(unsigned int *)dst = cub->args->f;
			b++;
		}
		a++;
	}
}

void	draw_img(t_cub *cub)
{
	draw_background(cub, cub->x, cub->y);
	raycast1(cub);
	if (cub->mini == 1)
		minimap1(cub);
	mlx_put_image_to_window(cub->img_mlx->mlx, cub->img_mlx->win,
		cub->img_mlx->img, 0, 0);
}

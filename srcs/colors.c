/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:24:09 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/10 16:20:29 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_t(int color)
{
	return ((color & 0xFF000000) >> 24);
}

int	get_r(int color)
{
	return ((color & 0x00FF0000) >> 16);
}

int	get_g(int color)
{
	return ((color & 0x0000FF00) >> 8);
}

int	get_b(int color)
{
	return (color & 0x000000FF);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	t_color	clr;

	clr.t = get_t(color);
	clr.r = get_r(color);
	clr.g = get_g(color);
	clr.b = get_b(color);
	cub->img_mlx->addr[(y * cub->img_mlx->size_line
			+ x * (cub->img_mlx->bpp / 8))] = clr.b;
	cub->img_mlx->addr[(y * cub->img_mlx->size_line
			+ x * (cub->img_mlx->bpp / 8)) + 1] = clr.g;
	cub->img_mlx->addr[(y * cub->img_mlx->size_line
			+ x * (cub->img_mlx->bpp / 8)) + 2] = clr.r;
	cub->img_mlx->addr[(y * cub->img_mlx->size_line
			+ x * (cub->img_mlx->bpp / 8)) + 3] = clr.t;
}

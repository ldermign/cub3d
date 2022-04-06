/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:24:09 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/06 20:07:41 by ejahan           ###   ########.fr       */
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
	// printf("test\n");
	t_color	clr;

	clr.t = get_t(color);
	clr.r = get_r(color);
	clr.g = get_g(color);
	clr.b = get_b(color);
	cub->addr[(y * cub->line_length + x * (cub->bits_per_pixel / 8))] = clr.b;
	cub->addr[(y * cub->line_length + x * (cub->bits_per_pixel / 8)) + 1] = clr.g;
	cub->addr[(y * cub->line_length + x * (cub->bits_per_pixel / 8)) + 2] = clr.r;
	cub->addr[(y * cub->line_length + x * (cub->bits_per_pixel / 8)) + 3] = clr.t;
}

// void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->size_line + x * (data->bpp / 8));
// 	*(unsigned int *)dst = color;
// }

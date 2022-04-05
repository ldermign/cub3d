/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:24:09 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/05 21:33:19 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->size_line + x * (data->bpp / 8));
// 	*(unsigned int *)dst = color;
// }

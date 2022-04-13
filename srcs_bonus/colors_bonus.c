/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:24:09 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/13 22:41:06 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

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

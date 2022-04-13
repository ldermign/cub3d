/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:24:36 by ejahan            #+#    #+#             */
/*   Updated: 2022/04/13 22:40:34 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

void	my_mlx_pixel_put_square(t_cub *cub, int x, int y, int color)
{
	char	*dst;
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (y < 0 || x < 0)
		return ;
	while (a < cub->a2)
	{
		while (b < cub->a2)
		{
			dst = cub->img_mlx->addr + ((a + y) * cub->img_mlx->size_line
					+ (b + x) * (cub->img_mlx->bpp / 8));
			*(unsigned int *)dst = color;
			b++;
		}
		a++;
		b = 0;
	}
}

int	minimap1(t_cub *cub)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	j = 0;
	if (cub->y < 400 && cub->x < 400)
		return (-1);
	while (cub->args->map[i])
	{
		while (cub->args->map[i][j])
			j++;
		if (j > k)
			k = j;
		j = 0;
		i++;
	}
	if (i > k)
		k = i;
	minimap2(cub, k);
	return (1);
}

void	norm_minimap(t_cub *cub, int l, int k)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cub->args->map[i])
	{
		while (cub->args->map[i][j])
		{
			if (cub->args->map[i][j] == '1')
				my_mlx_pixel_put_square(cub, (l - cub->a2 * k) / 2 + cub->a2
					* j, (l - cub->a2 * k) / 2 + i * cub->a2,
					create_trgb(2, 0, 110, 90));
			else if (cub->args->map[i][j] == '0')
				my_mlx_pixel_put_square(cub, (l - cub->a2 * k) / 2 + cub->a2
					* j, (l - cub->a2 * k) / 2 + i * cub->a2,
					create_trgb(2, 160, 160, 160));
			j++;
		}
		j = 0;
		i++;
	}
}

int	minimap2(t_cub *cub, int k)
{
	int	l;

	l = 0;
	if (cub->x <= cub->y)
		l = cub->x / 2;
	else
		l = cub->y / 2;
	cub->a2 = l / k;
	norm_minimap(cub, l, k);
	my_mlx_pixel_put_square(cub, cub->a2 * cub->pos_y + (l - cub->a2 * k) / 2
		+ (cub->a2 * cub->dir_y) - cub->a2 / 2,
		cub->a2 * cub->pos_x + (l - cub->a2 * k) / 2 + cub->dir_x * cub->a2
		- cub->a2 / 2, create_trgb(2, 160, 200, 200));
	my_mlx_pixel_put_square(cub, (l - cub->a2 * k) / 2 + (cub->a2 * cub->pos_y)
		- cub->a2 / 2, (l - cub->a2 * k) / 2 + cub->pos_x * cub->a2
		- cub->a2 / 2, create_trgb(2, 65, 65, 65));
	return (1);
}

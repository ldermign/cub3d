/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 19:55:13 by ejahan            #+#    #+#             */
/*   Updated: 2022/04/13 20:14:40 by ejahan           ###   ########.fr       */
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

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	t_color	clr;

	if (x < 0 || y < 0)
		return ;
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

void	put_line(t_cub *cub, int color, int x)
{
	int	y;

	y = cub->drawstart;
	while (y <= cub->drawend)
	{
		cub->text.tex_y = (int)cub->text.texpos
			& (cub->all_txt[cub->text.texnum].tex_height - 1);
		cub->text.texpos += cub->step;
		color = cub->all_txt[cub->text.texnum].text[cub->all_txt[
			cub->text.texnum].tex_height * cub->text.tex_y + cub->text.tex_x];
		if (cub->side == 1)
			color = (color >> 1) & 8355711;
		my_mlx_pixel_put(cub, x, y, color);
		y++;
	}
}

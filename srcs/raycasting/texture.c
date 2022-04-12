/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:26:01 by ejahan            #+#    #+#             */
/*   Updated: 2022/04/12 14:07:04 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*get_color(t_mlx *txt)
{
	int	x;
	int	y;
	int	*tab;

	y = 0;
	txt->size_line /= 4;
	tab = malloc(sizeof(int) * (32 * 32));
	if (tab == NULL)
		return (NULL);
	while (y < 32)
	{
		x = 0;
		while (x < 32)
		{
			tab[y * 32 + x] = txt->text[y * txt->size_line + x];
			x++;
		}
		y++;
	}
	txt->size_line *= 4;
	return (tab);
}

int	*create_txt(char *path_to_text, t_cub *cub)
{
	int		width;
	int		height;
	int		*color;
	t_mlx	txt;

	ft_bzero(&txt, sizeof(txt));
	color = NULL;
	width = WIDTH;
	height = HEIGHT;
	txt.img = mlx_xpm_file_to_image(cub->img_mlx->mlx, path_to_text, &width,
			&height);
	txt.text = (int *)mlx_get_data_addr(txt.img, &txt.bpp, &txt.size_line,
			&txt.endian);
	txt.addr = mlx_get_data_addr(txt.img, &txt.bpp, &txt.size_line,
			&txt.endian);
	color = get_color(&txt);
	mlx_destroy_image(cub->img_mlx->mlx, txt.img);
	return (color);
}

void	get_texture(t_cub *cub, t_arg *arg)
{
	// (void)arg;
	cub->text.tex_height = HEIGHT;
	cub->text.tex_width = WIDTH;
	cub->text.texture_jsp = create_txt(arg->north, cub);
	cub->text.txt_north = create_txt(arg->north, cub);
	cub->text.txt_south = create_txt(arg->south, cub);
	cub->text.txt_east = create_txt(arg->east, cub);
	cub->text.txt_west = create_txt(arg->west, cub);
	if (cub->text.txt_north == NULL || cub->text.txt_south == NULL
		|| cub->text.txt_east == NULL || cub->text.txt_west == NULL)
	{
		quit_parsing(arg, "Something's wrong with malloc.\n", 0, 0);
		quit_image(cub);
		exit (1);
	}
	// for (int x = 0 ; x < 64 ; x++)
	// for (int y = 0 ; y < 64 ; y++)
	// 	cub->text.txt_test[64 * y + x] = 65536 * 192 * (x % 16 && y % 16);
}

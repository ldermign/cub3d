/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:26:01 by ejahan            #+#    #+#             */
/*   Updated: 2022/04/13 14:56:47 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_txt(char *path_to_text, t_cub *cub, t_text *text)
{
	int		width;
	int		height;
	t_mlx	txt;

	ft_bzero(&txt, sizeof(txt));
	width = 0;
	height = 0;
	text->img_text = mlx_xpm_file_to_image(cub->img_mlx->mlx, path_to_text, &width,
			&height);
	text->text = (int *)mlx_get_data_addr(text->img_text, &txt.bpp, &txt.size_line,
			&txt.endian);
	text->tex_width = width;
	text->tex_height = height;
}

void	get_texture(t_cub *cub, t_arg *arg)
{
	create_txt(arg->north, cub, &(cub->all_txt[0]));
	create_txt(arg->south, cub, &(cub->all_txt[1]));
	create_txt(arg->east, cub, &(cub->all_txt[2]));
	create_txt(arg->west, cub, &(cub->all_txt[3]));
	if (cub->all_txt[0].img_text == NULL || cub->all_txt[1].img_text == NULL
		|| cub->all_txt[2].img_text == NULL || cub->all_txt[3].img_text == NULL)
	{
		quit_parsing(arg, "Something's wrong with malloc.\n", 0, 0);
		quit_image(cub);
		exit (1);
	}
}

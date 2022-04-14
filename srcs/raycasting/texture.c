/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:26:01 by ejahan            #+#    #+#             */
/*   Updated: 2022/04/14 13:21:42 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_txt(char *path_to_text, t_cub *cub, t_text *t)
{
	int		width;
	int		height;
	t_mlx	txt;

	ft_bzero(&txt, sizeof(txt));
	width = 0;
	height = 0;
	t->img_text = mlx_xpm_file_to_image(cub->img_mlx->mlx, path_to_text, &width,
			&height);
	if (t->img_text == NULL)
		return ;
	t->text = (int *)mlx_get_data_addr(t->img_text, &txt.bpp, &txt.size_line,
			&txt.endian);
	t->tex_width = width;
	t->tex_height = height;
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

int	get_which_texture(t_cub *cub)
{
	int	text;

	text = 0;
	if (cub->side == 0 && cub->raydir_x < 0)
		text = 0;
	if (cub->side == 0 && cub->raydir_x >= 0)
		text = 1;
	if (cub->side == 1 && cub->raydir_y < 0)
		text = 2;
	if (cub->side == 1 && cub->raydir_y >= 0)
		text = 3;
	return (text);
}

/*
**	0 == NORTH
**	1 == SOUTH
**	2 == EAST
**	3 == WEST
*/

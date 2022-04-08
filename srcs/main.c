/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:37:45 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/08 15:15:11 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parsing(int ac, char **ag, t_arg *data)
{
	init_struct_arg(data);
	if (ft_check_arg(ac, ag) == -1 || gnl_mapcub(data, ag[1]) == -1
		|| check_wrong_data_and_recup(data) == -1 || recup_map(data) == -1
		|| check_map(data) == -1)
		return (-1);
	if (check_textures(data) == -1)
	{
		quit_parsing(data, "One of the textures cannot be opened.\n", 0, 0);
		return (-1);
	}
	return (1);
}

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
	width = 600;
	height = 600;
	txt.img = mlx_xpm_file_to_image(cub->mlx, path_to_text, &width,
			&height);
	txt.text = (int *)mlx_get_data_addr(txt.img, &txt.bpp, &txt.size_line,
			&txt.endian);
	txt.addr = mlx_get_data_addr(txt.img, &txt.bpp, &txt.size_line,
			&txt.endian);
	color = get_color(&txt);
	mlx_destroy_image(cub->mlx, txt.img);
	return (color);
}

void	get_texture(t_cub *cub, t_arg *arg)
{
	cub->texHeight = 600;
	cub->texWidth = 600;
	cub->txt_north = create_txt(arg->north, cub);
	cub->txt_south = create_txt(arg->south, cub);
	cub->txt_east = create_txt(arg->east, cub);
	cub->txt_west = create_txt(arg->west, cub);
	cub->txt_sprite = create_txt(arg->sprite, cub);
	if (cub->txt_north == NULL || cub->txt_south == NULL
		|| cub->txt_east == NULL || cub->txt_west == NULL
		|| cub->txt_sprite == NULL)
	{
		quit_parsing(arg, "Something's wrong with malloc.\n", 0, 0);
		quit_image(cub);
		exit (1);
	}
}

void	recup_cub(t_cub *cub, t_mlx *img, t_arg *arg)
{
	cub->mini = -1;
	cub->bits_per_pixel = img->bpp;
	cub->line_length = img->size_line;
	cub->endian = img->endian;
	cub->c = create_trgb(21, arg->ciel_r, arg->ciel_g, arg->ciel_b);
	cub->f = create_trgb(21, arg->flr_r, arg->flr_g, arg->flr_b);
	cub->x = 600;
	cub->y = 600;
	cub->east = arg->east;
	cub->west = arg->west;
	cub->south = arg->south;
	cub->north = arg->north;
	cub->sprite = arg->sprite;
	cub->player = (char)arg->player;
	cub->map = arg->map;
	recup_pos(cub);
	init_raycast(cub);
}

int		main(int ac, char **ag)
{
	t_struct	all;

	if (parsing(ac, ag, &all.data) == -1)
		exit (1);
	recup_cub(&all.cub, &(all.img), &all.data);
	print(all.cub);
	printf("dirX : %f\ndirY : %f\nplaneX : %f\nplaneY : %f\n", all.cub.dirX, all.cub.dirY, all.cub.planeX, all.cub.planeY);
	window(&all);

	return (0);
}


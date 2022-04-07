/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:37:45 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/07 15:18:56 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_pars(t_arg *data, t_mlx *img, t_calc *clcls)
{
	img->width = 600;
	img->height = 600;
	img->sky = create_trgb(1, data->ciel_r, data->ciel_g, data->ciel_b);
	img->floor = create_trgb(1, data->flr_r, data->flr_g, data->flr_b);
	clcls->plrX = (int)data->plrX;
	clcls->plrY = (int)data->plrY;
}

void	get_orientation_player(t_calc *clcls, t_arg *data)
{
	if (data->player == 'E') // cast (char) a data
	{
		clcls->dirY = 1;
		clcls->planeX = 0.66;
	}
	else if (data->player == 'N')
	{
		clcls->dirX = -1;
		clcls->planeY = 0.66;
	}
	else if (data->player == 'W')
	{
		clcls->dirY = -1;
		clcls->planeX = -0.66;
	}
	else if (data->player == 'S')
	{
		clcls->dirX = 1;
		clcls->planeY = -0.66;
	}
}

int	parsing(int ac, char **ag, t_arg *data)
{
	init_struct_arg(data);
	if (ft_check_arg(ac, ag) == -1 || gnl_mapcub(data, ag[1]) == -1
		|| check_wrong_data_and_recup(data) == -1 || recup_map(data) == -1
		|| check_map(data) == -1)
		return (-1);
	return (1);
}

void	recup_cub(t_cub *cub, t_mlx *img, t_arg *arg)
{
	cub->mini = -1;
	cub->bits_per_pixel = img->bpp;
	cub->line_length = img->size_line;
	cub->endian = img->endian;
	cub->c = create_trgb(21, arg->ciel_r, arg->ciel_g, arg->ciel_b);
	cub->f = create_trgb(21, arg->flr_r, arg->flr_g, arg->flr_b);
	cub->x = img->width;
	cub->y = img->height;
	cub->east = arg->east;
	cub->west = arg->west;
	cub->south = arg->south;
	cub->north = arg->north;
	cub->sprite = arg->sprite;
	cub->player = (char)arg->player;
	cub->map = arg->map;	
}

int		main(int ac, char **ag)
{
	t_struct	all;

	if (parsing(ac, ag, &all.data) == -1)
		exit (1);
	get_pars(&all.data, &(all.img), &(all.cls));
	get_orientation_player(&(all.cls), &all.data);
	recup_cub(&all.cub, &(all.img), &all.data);
	print(all.cub);
	recup_pos(&all.cub);
	init_raycast(&all.cub);
	printf("dirX : %f\ndirY : %f\nplaneX : %f\nplaneY : %f\n", all.cub.dirX, all.cub.dirY, all.cub.planeX, all.cub.planeY);
	window(&all);

	return (0);
}


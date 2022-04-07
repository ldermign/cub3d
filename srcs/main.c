/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:37:45 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/07 14:30:30 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_pars(t_arg *data, t_mlx *img, t_calc *clcls)
{
	ft_memset(img, 0, sizeof(t_mlx));
	ft_memset(clcls, 0, sizeof(t_calc));
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

int		close_cross()
{
	printf("You clicked on the cross.\n");
	quit_parsing(s()->data, "Goodbye !\n", 3, 0);
	quit_image(s()->img);
	quit_structure();
	exit(0);
	return (0);
}

// int		key_press(int keycode)
// {
// 	printf("[%d]\n", keycode);
// 	if (keycode == 65307)
// 	{
// 		quit(s()->data, "You pressed the escape button. Goodbye !\n", 3, 0);
// 		quit_properly_image(s()->img);
// 		exit (0);
// 	}
// 	// if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13
// 	// || keycode == 123 || keycode == 124)
// 	// 	move_player(keycode, s()->cls, s()->data);
// 	// all_calculs_cub(s()->img, s()->cls, s()->data);
// 	return (0);
// }

int	parsing(int ac, char **ag)
{
	if (ft_check_arg(ac, ag) == -1 || gnl_mapcub(s()->data, ag[1]) == -1
		|| check_wrong_data_and_recup(s()->data) == -1 || recup_map(s()->data) == -1
		|| check_map(s()->data) == -1)
		return (-1);
	return (1);
}

t_s	*s(void)
{
	static t_s *stc = NULL;

	if (!stc)
	{
		stc = calloc(1, sizeof(t_s));
		if (!stc)
			return (NULL);
		stc->data = calloc(1, sizeof(t_arg));
		if (!stc->data)
			return (NULL);
		stc->img = calloc(1, sizeof(t_mlx));
		if (!stc->img)
			return (NULL);
		stc->cls = calloc(1, sizeof(t_calc));
		if (!stc->cls)
			return (NULL);
	}
	return (stc);
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
	t_cub	cub;

	if (parsing(ac, ag) == -1)
	{
		free(s()->img);
		free(s()->cls);
		free(s());
		exit (1);
	}
	get_pars(s()->data, s()->img, s()->cls);
	get_orientation_player(s()->cls, s()->data);
	recup_cub(&cub, s()->img, s()->data);
	print(cub);
	recup_pos(&cub);
	init_raycast(&cub);
	printf("dirX : %f\ndirY : %f\nplaneX : %f\nplaneY : %f\n", cub.dirX, cub.dirY, cub.planeX, cub.planeY);
	window(&cub);
	// all_calculs_cub(s()->img, s()->cls, s()->data);

	return (0);
}

// ==528264== 9 bytes in 1 blocks are still reachable in loss record 1 of 2
// ==528264==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
// ==528264==    by 0x4085EB: ft_last_call (in /mnt/nfs/homes/ldermign/Desktop/cub3d/cub3d)
// ==528264==    by 0x4087BC: get_next_line (in /mnt/nfs/homes/ldermign/Desktop/cub3d/cub3d)
// ==528264==    by 0x4048A1: gnl_mapcub (first_step_parsing.c:100)
// ==528264==    by 0x402868: parsing (main.c:79)
// ==528264==    by 0x402A54: main (main.c:131)
// ==528264== 


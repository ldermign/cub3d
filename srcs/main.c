/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:37:45 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/06 20:08:52 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_pars(t_arg *data, t_mlx *img, t_calc *clcls)
{
	ft_memset(img, 0, sizeof(t_mlx));
	ft_memset(clcls, 0, sizeof(t_calc));
	img->width = 500;
	img->height = 500;
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
	// printf("ciel = %d, %d, %d\n", arg->ciel_r, arg->ciel_g, arg->ciel_b);
	cub->c = create_trgb(21, arg->ciel_r, arg->ciel_g, arg->ciel_b);
	cub->f = create_trgb(21, arg->flr_r, arg->flr_g, arg->flr_b);
	// printf("ciel = %d\n", cub->c);
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
		exit (1);
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


// ==567246== Conditional jump or move depends on uninitialised value(s)
// ==567246==    at 0x406422: test (merde.c:19)
// ==567246==    by 0x406FAD: window (merde.c:176)
// ==567246==    by 0x402B4D: main (main.c:141)
// ==567246==  Uninitialised value was created by a stack allocation
// ==567246==    at 0x402A20: main (main.c:129)

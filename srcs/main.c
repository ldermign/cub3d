/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:37:45 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/05 19:19:15 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_pars(t_arg *data, t_mlx *img, t_calc *clcls)
{
	ft_memset(img, 0, sizeof(t_mlx));
	ft_memset(clcls, 0, sizeof(t_calc));
	img->width = data->res_x;
	img->height = data->res_y;
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
	quit(s()->data, "Goodbye !\n", 3, 0);
	quit_properly_image(s()->img);
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

void	parsing(int ac, char **ag)
{
	ft_check_arg(ac, ag);
	gnl_mapcub(s()->data, ag[1]);
	check_wrong_data_and_recup(s()->data);
	recup_map(s()->data);
	check_map(s()->data);
	// printf_struct_arg(*data);
	// quit(&data, "All good.\n", 3, 0);
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

	// printf("\n\033[1;32m-> OK  🐸\033[0m\n\n");
	// printf("\n\033[1;33mINFOS : \033[0m\n\n");
	// printf("\033[1;34mx	\033[0m -> %d\n", cub.x);
	// printf("\033[1;34my	\033[0m -> %d\n", cub.y);
	// printf("\033[1;34mf	\033[0m -> %d\n", cub.f);
	// printf("\033[1;34mc	\033[0m -> %d\n", cub.c);
	// printf("\033[1;34mEAST	\033[0m -> %s\n", cub.east);
	// printf("\033[1;34mWEST	\033[0m -> %s\n", cub.west);
	// printf("\033[1;34mSOUTH	\033[0m -> %s\n", cub.south);
	// printf("\033[1;34mNORTH	\033[0m -> %s\n", cub.north);
	// printf("\033[1;34mSPRITE	\033[0m -> %s\n", cub.sprite);
	// printf("\033[1;34mPLAYER	\033[0m -> %c\n", cub.player);
	// printf("\n\033[1;33mMAP : \033[0m\n\n");

void	recup_cub(t_cub *cub, t_mlx *img, t_arg *arg)
{
	cub->bits_per_pixel = img->bpp;
	cub->line_length = img->size_line;
	cub->endian = img->endian;
	printf("ciel = %d, %d, %d\n", arg->ciel_r, arg->ciel_g, arg->ciel_b);
	cub->c = create_trgb(arg->ciel_r, arg->ciel_g, arg->ciel_b, 12);
	cub->f = create_trgb(arg->flr_r, arg->flr_g, arg->flr_b, 12);
	printf("ciel = %d\n", cub->c);
	cub->x = arg->res_x;
	cub->y = arg->res_y;
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
	// t_arg data;
	// t_mlx img;
	// t_calc clcls;

	// free(data()->east);
	// free(data());

	parsing(ac, ag);
	get_pars(s()->data, s()->img, s()->cls);
	// s()->img->mlx = mlx_init();
	// s()->img->win = mlx_new_window(s()->img->mlx, s()->img->width, s()->img->height, "Cub3D");
	// s()->img->img = mlx_new_image(s()->img->mlx, s()->img->width, s()->img->height);
	// s()->img->addr = mlx_get_data_addr(s()->img->img, &s()->img->bpp, &s()->img->size_line, &s()->img->endian);
	// get_orientation_player(s()->cls, s()->data);
	recup_cub(&cub, s()->img, s()->data);
	print(cub);
	recup_pos(&cub);
	init_raycast(&cub);
	printf("dirX : %f\ndirY : %f\nplaneX : %f\nplaneY : %f\n", cub.dirX, cub.dirY, cub.planeX, cub.planeY);
	window(&cub);
	// all_calculs_cub(s()->img, s()->cls, s()->data);

	// mlx_hook(s()->img->win, 2, 1L<<0, &key_press, (void *)0);

	// mlx_hook(s()->img->win, 17, 1L<<0, &close_cross, (void *)0);

	// mlx_loop(s()->img->mlx);
	return (0);
}

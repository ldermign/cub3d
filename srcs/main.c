/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:37:45 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/05 15:23:11 by ldermign         ###   ########.fr       */
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

int		key_press(int keycode)
{
	printf("[%d]\n", keycode);
	if (keycode == 65307)
	{
		quit(s()->data, "You pressed the escape button. Goodbye !\n", 3, 0);
		quit_properly_image(s()->img);
		exit (0);
	}
	// if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13
	// || keycode == 123 || keycode == 124)
	// 	move_player(keycode, s()->cls, s()->data);
	// all_calculs_cub(s()->img, s()->cls, s()->data);
	return (0);
}

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

int		main(int ac, char **ag)
{
	// t_arg data;
	// t_mlx img;
	// t_calc clcls;

	// free(data()->east);
	// free(data());

	parsing(ac, ag);
	get_pars(s()->data, s()->img, s()->cls);
	s()->img->mlx = mlx_init();
	s()->img->win = mlx_new_window(s()->img->mlx, s()->img->width, s()->img->height, "Cub3D");
	s()->img->img = mlx_new_image(s()->img->mlx, s()->img->width, s()->img->height);
	s()->img->addr = mlx_get_data_addr(s()->img->img, &s()->img->bpp, &s()->img->size_line, &s()->img->endian);
	get_orientation_player(s()->cls, s()->data);
	all_calculs_cub(s()->img, s()->cls, s()->data);

	mlx_hook(s()->img->win, 2, 1L<<0, &key_press, (void *)0);

	mlx_hook(s()->img->win, 17, 1L<<0, &close_cross, (void *)0);

	mlx_loop(s()->img->mlx);
	return (0);
}

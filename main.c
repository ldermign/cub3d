/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:37:45 by ldermign          #+#    #+#             */
/*   Updated: 2021/05/28 09:53:00 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int		close_cross()
{
	printf("You clicked on the cross.\n");
	quit(s()->data, "Goodbye !\n", 3, 0);
	exit(0);
	return (0);
}

int		key_press(int keycode)
{
	if (keycode == 53)
	{
		printf("You pressed the escape button.\n");
		quit(s()->data, "Goodbye !\n", 3, 0);
		exit (0);
	}
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13
	|| keycode == 123 || keycode == 124)
		move_player(keycode, s()->cls, s()->data);
	all_calculs_cub(s()->img, s()->cls, s()->data);
	return (0);
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
		if (!stc->img)
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
	
	// mlx_hook(s()->img->win, 2, 1L<<0, &key_press, (void *)0);
	// mlx_hook(img.win, 3, 1L<<0, &key_release, (void *)0);
	// mlx_hook(s()->img->win, 2, 1L<<0, &key_press, (void *)0);
	
	// PAS TOUCHER
	// mlx_key_hook(img.win, &print_keycode, &img); // ne fonctionne pas avec move pixel
	// mlx_hook(s()->img->win, 2, 1L<<0, &move_pixel, s()->img);
	// mlx_hook(s()->img->win, 2, 1L<<0, &key_press, (void *)0);

	mlx_hook(s()->img->win, 2, 1L<<0, &key_press, (void *)0);
	// mlx_hook(s()->img->win, 3, 1L<<0, &key_release, (void *)0);
	mlx_hook(s()->img->win, 17, 1L<<0, &close_cross, (void *)0);
	// mlx_key_hook(s()->img->win, &close_escape, (void *)0);
	// mlx_loop_hook(s()->img->mlx, &all_calculs_cub, s()); //creer fonction qui refresh

	mlx_loop(s()->img->mlx);
	return (0);
}


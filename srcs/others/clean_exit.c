/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 08:39:23 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/08 15:13:14 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab_int(int **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (i < 32)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("\x1b[0mLine [ %d ]\t==>\t\x1B[1;30m%s\n", i + 1, map[i]);
		i++;
	}
}

int	quit_parsing(t_arg *data, char *str_err, int i, int place)
{
	if (i != 3)
		printf("Error\n");
	if (str_err != NULL)
		printf("%s", str_err);
	if ((i == 1 || i == 2) && str_err != NULL)
		printf("[ %d ].\n", place);
	if (i == 2)
		ft_print_map(data->map);
	free(data->north);
	free(data->south);
	free(data->west);
	free(data->east);
	free(data->sprite);
	free_str(data->fd);
	free_str(data->map);
	return (-1);
}

void	quit_image(t_cub *cub)
{
	// free_tab_int(cub->txt_north);
	// free_tab_int(cub->txt_south);
	// free_tab_int(cub->txt_east);
	// free_tab_int(cub->txt_west);
	// free_tab_int(cub->txt_sprite);
	free(cub->txt_north);
	free(cub->txt_south);
	free(cub->txt_east);
	free(cub->txt_west);
	free(cub->txt_sprite);
	if (cub)
	{
		if (cub->img)
			mlx_destroy_image(cub->mlx, cub->img);
		if (cub->mlx_ptr)
			mlx_destroy_window(cub->mlx, cub->mlx_ptr);
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 08:39:23 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/14 13:27:57 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

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
	free_str(data->fd);
	free_str(data->map);
	return (-1);
}

void	quit_image(t_cub *cub)
{
	if (cub->all_txt[0].img_text != NULL)
		mlx_destroy_image(cub->img_mlx->mlx, cub->all_txt[0].img_text);
	if (cub->all_txt[1].img_text != NULL)
		mlx_destroy_image(cub->img_mlx->mlx, cub->all_txt[1].img_text);
	if (cub->all_txt[2].img_text != NULL)
		mlx_destroy_image(cub->img_mlx->mlx, cub->all_txt[2].img_text);
	if (cub->all_txt[3].img_text != NULL)
		mlx_destroy_image(cub->img_mlx->mlx, cub->all_txt[3].img_text);
	if (cub)
	{
		if (cub->img_mlx->img)
			mlx_destroy_image(cub->img_mlx->mlx, cub->img_mlx->img);
		if (cub->img_mlx->win)
			mlx_destroy_window(cub->img_mlx->mlx, cub->img_mlx->win);
		mlx_destroy_display(cub->img_mlx->mlx);
		free(cub->img_mlx->mlx);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 08:39:23 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/30 08:34:10 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	quit(t_arg *data, char *str_err, int i, int place)
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
	exit (0);
}

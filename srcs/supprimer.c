/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supprimer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 14:39:53 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/06 11:20:00 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	printf_struct_arg(t_arg data)
{
	printf(GREEN"\n\t///\\\\\\DATA MAP.CUB///\\\\\\\n\n"NORMAL);
	printf("flr_r = \t%d\n", data.flr_r);
	printf("flr_g = \t%d\n", data.flr_g);
	printf("flr_b = \t%d\n", data.flr_b);
	printf("ciel_r = \t%d\n", data.ciel_r);
	printf("ciel_g = \t%d\n", data.ciel_g);
	printf("ciel_b = \t%d\n", data.ciel_b);
	printf("north = \t[%s]\n", data.north);
	printf("south = \t[%s]\n", data.south);
	printf("west = \t\t[%s]\n", data.west);
	printf("east = \t\t[%s]\n", data.east);
	printf("sprite = \t[%s]\n", data.sprite);
	printf("\nPLAYER = \n");
	printf("player = \t%c\n", data.player);
	printf("plrX = \t%f\n", data.plrX);
	printf("plrY = \t%f\n", data.plrY);
	int i = 0;
	printf(GREEN"\n\t///\\\\\\FINAL MAP TO USE///\\\\\\\n\n");
	while (data.map[i])
	{
		printf("\x1b[0mFinal map ligne [ %d ]\t\t==>\t\t\x1B[1;30m%s\n", i + 1, data.map[i]);
		i++;
	}
	printf("\n");
}

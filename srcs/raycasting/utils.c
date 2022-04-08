/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:04:38 by ejahan            #+#    #+#             */
/*   Updated: 2022/04/08 15:00:51 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	test(t_cub *cub)
{
	init_background(cub, cub->c, cub->f, cub->x, cub->y);
	raycast1(cub);
	if (cub->mini == 1)
		minimap1(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_ptr, cub->img, 0, 0);
}

int	ft_loop(t_cub *cub)
{
	(void)cub;
	return (0);
}

int	ft_quit(t_struct *all)
{
	printf("\033[1;31mQUIT\033[0m\n");
	quit_parsing(&(all->data), "Goodbye !\n", 3, 0);
	quit_image(&(all->cub));
	exit(EXIT_SUCCESS);
	return (0);
}

void	init_background(t_cub *cub, int c, int f, int x, int y)
{
	char	*dst;
	int		a;
	int		b;


	a = 0;
	while (a < x)
	{
		b = 0;
		while (b < y / 2)
		{
			dst = cub->addr + (b * cub->line_length + a * (cub->bits_per_pixel / 8));
			*(unsigned int *)dst = c;
			b++;
		}
		while (b < y)
		{
			dst = cub->addr + (b * cub->line_length + a * (cub->bits_per_pixel / 8));
			*(unsigned int *)dst = f;
			b++;
		}
		a++;
	}
}

void	window(t_struct *all)
{
	printf("posX : %f\n", all->cub.posX);
	all->cub.background = 2;
	all->cub.mlx = mlx_init();
	all->cub.mlx_ptr = mlx_new_window(all->cub.mlx, all->cub.x, all->cub.y, "Cub3D");
	all->cub.img = mlx_new_image(all->cub.mlx, all->cub.x, all->cub.y);
	all->cub.addr = mlx_get_data_addr(all->cub.img, &all->cub.bits_per_pixel,
			&all->cub.line_length, &all->cub.endian);
	get_texture(&(all->cub), &(all->data));
	test(&all->cub);
	// init_background(cub, cub->c, cub->f, cub->x, cub->y);
	// raycast1(cub);
	// mlx_put_image_to_window(cub->mlx, cub->mlx_ptr, cub->img, 0, 0);
	mlx_hook(all->cub.mlx_ptr, 2, 1L << 0, key_press, all);
	mlx_hook(all->cub.mlx_ptr, 17, 1L << 2, ft_quit, all);
	mlx_loop_hook(all->cub.mlx, ft_loop, &(all->cub));
	mlx_loop(all->cub.mlx);
}

void	print(t_cub cub)
{
	int	i;

	i = 0;
	// printf("\n\033[1;32m-> OK  🐸\033[0m\n\n");
	printf("\n\033[1;32m-> OK  🐸\033[0m\n\n");
	printf("\n\033[1;33mINFOS : \033[0m\n\n");
	printf("\033[1;34mx	\033[0m -> %d\n", cub.x);
	printf("\033[1;34my	\033[0m -> %d\n", cub.y);
	printf("\033[1;34mf	\033[0m -> %d\n", cub.f);
	printf("\033[1;34mc	\033[0m -> %d\n", cub.c);
	printf("\033[1;34mEAST	\033[0m -> %s\n", cub.east);
	printf("\033[1;34mWEST	\033[0m -> %s\n", cub.west);
	printf("\033[1;34mSOUTH	\033[0m -> %s\n", cub.south);
	printf("\033[1;34mNORTH	\033[0m -> %s\n", cub.north);
	printf("\033[1;34mSPRITE	\033[0m -> %s\n", cub.sprite);
	printf("\033[1;34mPLAYER	\033[0m -> %c\n", cub.player);
	printf("\n\033[1;33mMAP : \033[0m\n\n");
	while (cub.map[i] != NULL)
	{
		printf("%d\033[1;30m	>>	\033[0m%s\n", i, cub.map[i]);
		i++;
	}
	printf("\n");
}

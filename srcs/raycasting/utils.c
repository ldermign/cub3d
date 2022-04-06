/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:04:38 by ejahan            #+#    #+#             */
/*   Updated: 2022/04/06 21:12:04 by ejahan           ###   ########.fr       */
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

int	ft_quit(t_cub *cub)
{
	printf("\033[1;31mQUIT\033[0m\n");
	quit_parsing(s()->data, "Goodbye !\n", 3, 0);
	quit_image_2(cub);
	quit_structure();
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

void	window(t_cub *cub)
{
	printf("posX : %f\n", cub->posX);
	cub->background = 2;
	cub->mlx = mlx_init();
	cub->mlx_ptr = mlx_new_window(cub->mlx, cub->x, cub->y, "Cub3D");
	cub->img = mlx_new_image(cub->mlx, cub->x, cub->y);
	cub->addr = mlx_get_data_addr(cub->img, &cub->bits_per_pixel,
			&cub->line_length, &cub->endian);
	test(cub);
	// init_background(cub, cub->c, cub->f, cub->x, cub->y);
	// raycast1(cub);
	// mlx_put_image_to_window(cub->mlx, cub->mlx_ptr, cub->img, 0, 0);
	mlx_hook(cub->mlx_ptr, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->mlx_ptr, 17, 1L << 2, ft_quit, cub);
	mlx_loop_hook(cub->mlx, ft_loop, cub);
	mlx_loop(cub->mlx);
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

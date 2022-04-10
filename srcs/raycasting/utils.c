/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:04:38 by ejahan            #+#    #+#             */
/*   Updated: 2022/04/10 16:22:20 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_img(t_cub *cub)
{
	init_background(cub, cub->x, cub->y);
	raycast1(cub);
	if (cub->mini == 1)
		minimap1(cub);
	mlx_put_image_to_window(cub->img_mlx->mlx, cub->img_mlx->win,
		cub->img_mlx->img, 0, 0);
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

void	init_background(t_cub *cub, int x, int y)
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
			dst = cub->img_mlx->addr + (b * cub->img_mlx->size_line
					+ a * (cub->img_mlx->bpp / 8));
			*(unsigned int *)dst = cub->args->c;
			b++;
		}
		while (b < y)
		{
			dst = cub->img_mlx->addr + (b * cub->img_mlx->size_line
					+ a * (cub->img_mlx->bpp / 8));
			*(unsigned int *)dst = cub->args->f;
			b++;
		}
		a++;
	}
}

void	window(t_struct *all)
{
	all->img.mlx = mlx_init();
	all->img.win
		= mlx_new_window(all->img.mlx, all->cub.x, all->cub.y, "Cub3D");
	all->img.img = mlx_new_image(all->img.mlx, all->cub.x, all->cub.y);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->cub.img_mlx->bpp,
			&all->cub.img_mlx->size_line, &all->cub.img_mlx->endian);
	get_texture(&(all->cub), &(all->data));
	draw_img(&all->cub);
	mlx_hook(all->img.win, 2, 1L << 0, key_press, all);
	mlx_hook(all->img.win, 17, 1L << 2, ft_quit, all);
	mlx_loop_hook(all->img.mlx, ft_loop, &(all->cub));
	mlx_loop(all->img.mlx);
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
	printf("\033[1;34mf	\033[0m -> %d\n", cub.args->f);
	printf("\033[1;34mc	\033[0m -> %d\n", cub.args->c);
	// printf("\033[1;34mEAST	\033[0m -> %s\n", cub.east);
	// printf("\033[1;34mWEST	\033[0m -> %s\n", cub.west);
	// printf("\033[1;34mSOUTH	\033[0m -> %s\n", cub.south);
	// printf("\033[1;34mNORTH	\033[0m -> %s\n", cub.north);
	// printf("\033[1;34mSPRITE	\033[0m -> %s\n", cub.sprite);
	printf("\033[1;34mPLAYER	\033[0m -> %c\n", cub.args->player);
	printf("\n\033[1;33mMAP : \033[0m\n\n");
	while (cub.args->map[i] != NULL)
	{
		printf("%d\033[1;30m	>>	\033[0m%s\n", i, cub.args->map[i]);
		i++;
	}
	printf("\n");
}

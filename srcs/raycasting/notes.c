===============================================================================================================================================
LIENS
===============================================================================================================================================

https://lodev.org/cgtutor/raycasting.html
https://lodev.org/cgtutor/raycasting2.html
https://lodev.org/cgtutor/raycasting3.html

https://permadi.com/1996/05/ray-casting-tutorial-4/

https://www.youtube.com/watch?v=gID_FKfncZI

https://harm-smits.github.io/42docs/libs/minilibx










===============================================================================================================================================
TESTS
===============================================================================================================================================

wrong texture
missing or wrong player
wrong caracter in map
map error
wrong caracter in file
error color










===============================================================================================================================================
A FAIRE
===============================================================================================================================================

		4 murs differents 
	✅	parsing
	✅	raycasting
	✅	mlx
		textures
	✅	touches a et d
		plusieurs touches en meme temps ?
		LEAKSSSSSSS ta mereeeeee
		norme

	// BONUS :

	✅	minimap
	✅	collision murs s et w
		sprites animes
		portes
		pov avec souris
		collision murs a et d










===============================================================================================================================================
UTILS
===============================================================================================================================================

mlx_ptr == win










===============================================================================================================================================
SEGFAULT
===============================================================================================================================================

AddressSanitizer:DEADLYSIGNAL
=================================================================
==489557==ERROR: AddressSanitizer: SEGV on unknown address 0x7fee1708be8c (pc 0x0000004d3671 bp 0x7fffa1deaa58 sp 0x7fffa1d3a800 T0)
==489557==The signal is caused by a WRITE memory access.
    #0 0x4d3671 in my_mlx_pixel_put_square /mnt/nfs/homes/ejahan/Desktop/last/srcs/raycasting/minimap.c:29:25
    #1 0x4d3671 in minimap2 /mnt/nfs/homes/ejahan/Desktop/last/srcs/raycasting/minimap.c:100:2
    #2 0x4d335b in minimap1 /mnt/nfs/homes/ejahan/Desktop/last/srcs/raycasting/minimap.c:59:2
    #3 0x4d193f in draw_img /mnt/nfs/homes/ejahan/Desktop/last/srcs/raycasting/utils.c:20:3
    #4 0x4d5134 in key_press /mnt/nfs/homes/ejahan/Desktop/last/srcs/raycasting/key_press.c
    #5 0x4d6b95 in mlx_loop (/mnt/nfs/homes/ejahan/Desktop/last/cub3d+0x4d6b95)
    #6 0x4ca93f in main /mnt/nfs/homes/ejahan/Desktop/last/srcs/main.c:125:2
    #7 0x7fee1a6dd0b2 in __libc_start_main /build/glibc-sMfBJT/glibc-2.31/csu/../csu/libc-start.c:308:16
    #8 0x41c5fd in _start (/mnt/nfs/homes/ejahan/Desktop/last/cub3d+0x41c5fd)










===============================================================================================================================================
AUTRE
===============================================================================================================================================








int	*get_color(t_mlx *txt)
{
	int	x;
	int	y;
	int	*tab;

	y = 0;
	txt->size_line /= 4;
	tab = malloc(sizeof(int) * (32 * 32));
	if (tab == NULL)
		return (NULL);
	while (y < 32)
	{
		x = 0;
		while (x < 32)
		{
			tab[y * 32 + x] = txt->text[y * txt->size_line + x];
			x++;
		}
		y++;
	}
	txt->size_line *= 4;
	return (tab);
}

int	*create_txt(char *path_to_text, t_cub *cub)
{
	int		width;
	int		height;
	int		*color;
	t_mlx	txt;

	ft_bzero(&txt, sizeof(txt));
	color = NULL;
	width = 600;
	height = 600;
	txt.img = mlx_xpm_file_to_image(cub->mlx, path_to_text, &width,
			&height);
	txt.text = (int *)mlx_get_data_addr(txt.img, &txt.bpp, &txt.size_line,
			&txt.endian);
	txt.addr = mlx_get_data_addr(txt.img, &txt.bpp, &txt.size_line,
			&txt.endian);
	color = get_color(&txt);
	mlx_destroy_image(cub->mlx, txt.img);
	return (color);
}

void	get_texture(t_cub *cub, t_arg *arg)
{
	cub->texHeight = 600;
	cub->texWidth = 600;
	cub->txt_north = create_txt(arg->north, cub);
	cub->txt_south = create_txt(arg->south, cub);
	cub->txt_east = create_txt(arg->east, cub);
	cub->txt_west = create_txt(arg->west, cub);
	cub->txt_sprite = create_txt(arg->sprite, cub);
	if (cub->txt_north == NULL || cub->txt_south == NULL
		|| cub->txt_east == NULL || cub->txt_west == NULL
		|| cub->txt_sprite == NULL)
	{
		quit_parsing(arg, "Something's wrong with malloc.\n", 0, 0);
		quit_image(cub);
		exit (1);
	}
}







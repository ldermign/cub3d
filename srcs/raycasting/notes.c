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
line_lenght == size_line










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

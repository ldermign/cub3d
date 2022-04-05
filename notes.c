https://lodev.org/cgtutor/raycasting.html
https://lodev.org/cgtutor/raycasting2.html
https://lodev.org/cgtutor/raycasting3.html

https://permadi.com/1996/05/ray-casting-tutorial-4/

https://www.youtube.com/watch?v=gID_FKfncZI

https://harm-smits.github.io/42docs/libs/minilibx











tableau de texture :	char	*texture[4]		->		texture[0][longueur * largeur] 






	if (!(rc->text->text_we = mlx_xpm_file_to_image(rc->mlx, rc->p->we,
		(int *)&w_we, (int *)&h_we)))
		return (ERROR);
	if (!(rc->text->text_we_data = mlx_get_data_addr(rc->text->text_we,
		&t, &t, &t)))
		return (ERROR);
	if (!(rc->text->text_ea = mlx_xpm_file_to_image(rc->mlx, rc->p->ea,
		(int *)&w_ea, (int *)&h_ea)))
		return (ERROR);
	if (!(rc->text->text_ea_data = mlx_get_data_addr(rc->text->text_ea,
		&t, &t, &t)))
		return (ERROR);
	rc->text->w_we = w_we;
	rc->text->h_we = h_we;
	rc->text->w_ea = w_ea;
	rc->text->h_ea = h_ea;
	return (GOOD);








wrong texture
missing or wrong player
wrong caracter in map
map error
wrong caracter in file
error color








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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 09:04:06 by ejahan            #+#    #+#             */
/*   Updated: 2021/06/15 17:55:03 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include "libft/libft.h"
# include <fcntl.h>

typedef struct	s_cub
{
	//raycasting
	double	posX;				//position x du joueur
	double	posY;				//position y du joueur
	double	dirX;				//vecteur de direction initiale
	double	dirY;				//vecteur de direction initiale
	double	planeX;				//j'sais plus
	double	planeY;				//j'sais plus
	double	cameraX;			//abscisse de camera
	double	raydirX;			//calcul de direction x du rayon
	double	raydirY;			//calcul de direction y du rayon
	double	sideDistX;			//longueur entre position actuelle et prochain x ou y
	double	sideDistY;			//longueur entre position actuelle et prochain x ou y
	double	deltaDistX;			//longueur entre cote x ou y jusqu'a autre cote x ou y
	double	deltaDistY;			//longueur entre cote x ou y jusqu'a autre cote x ou y
	double	perpWallDist;		//distance jusqu'au mur perpandiculaire au plan camera
	double	oldDirX;
	double	oldPlaneX;
	double	wallX;
	double	step;
	double	texPos;
	char	texture[8][64 * 64];
	int		texWidth;
	int		texHeight;
	int		texY;
	int		stepX;				//dans quelle direction avancer
	int		stepY;				//dans quelle direction avancer
	int		mapX;				//dans quel carre on est
	int		mapY;				//dans quel carre on est
	int		drawStart;			//plus haut pixel a afficher
	int		drawEnd;			//plus bas pixel a afficher
	int		lineHeight;
	int		hit;
	int		side;
	int		texNum;
	int		texX;
	int		width_no;
	int		height_no;
	int		width_we;
	int		height_we;
	int		width_so;
	int		height_so;
	int		width_ea;
	int		height_ea;


	
	//img
	
	
	
	void	*mlx;
	void	*mlx_ptr;
	void	*mlx_ptr2;
	void	*img;
	void	*texture_ea;
	void	*texture_we;
	void	*texture_no;
	void	*texture_so;
	char	*addr;
	char	*addr_no;
	char	*addr_ea;
	char	*addr_so;
	char	*addr_we;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		background;
	int		screen_x;
	int		screen_y;



	//map
	
	
	
	int		x;
	int		y;
	int		a;
	int		b;
	int		fc;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	int		f;
	int		c;
	char	player;
	char	*line;
	char	**map;
	int	reste_x;
	int	reste_y;
	int	a2;			//largeur carre
	int	mini;
	int	jsp;
}				t_cub;

	// double		posx; 	//position x du joueur
	// double		posy; 	//position y du joueur
	// double		dirx; 	//vecteur de direction (commence à -1 pour N, 1 pour S, 0 sinon)
	// double		diry; 	//vecteur de direction (commence à -1 pour W, 1 pour E, 0 sinon)
	// double		planx; 	//vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
	// double		plany; 	//vecteur du plan (commence à 0.66 pour N, -0.66 pour S, 0 sinon)
	// double		raydirx; //calcul de direction x du rayon
	// double		raydiry; //calcul de direction y du rayon
	// double		camerax; //point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
	// int		mapx; // coordonée x du carré dans lequel est pos
	// int		mapy; // coordonnée y du carré dans lequel est pos
	// double		sidedistx; //distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x)
	// double		sidedisty; //distance que le rayon parcours jusqu'au premier point d'intersection horizontal (= un coté y)
	// double		deltadistx; //distance que rayon parcours entre chaque point d'intersection vertical
	// double		deltadisty; //distance que le rayon parcours entre chaque point d'intersection horizontal
	// int		stepx; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	// int		stepy; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	// int		hit; // 1 si un mur a ete touche, 0 sinon
	// int		side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	// double		perpwalldist; // distance du joueur au mur
	// int		lineheight; //hauteur de la ligne a dessiner
	// int		drawstart; //position de debut ou il faut dessiner
	// int		drawend; //position de fin ou il faut dessiner
	// int		x; //permet de parcourir tous les rayons

typedef struct	s_img
{
	void	*mlx;
	void	*mlx_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		background;
	int		x;
	int		y;
	double	posX;
	double	posY;
}				t_img;

// void			my_mlx_pixel_put(t_img *data, int x, t_cub *cub, int color);
int				create_trgb(int t, int r, int g, int b);
int				key_press(int key_code, t_cub *cub);
// void			image(t_img *data, int x, int y);
int				ft_loop(t_cub *cub);
void			init_background(t_cub *cub, int c, int f, int x, int y);
void			square(t_img *data, int color);
int				get_next_line(int fd, char **line);
void			window(t_cub *cub);
// map
int				check_last(t_cub *cub, char *str);
int				check_not_null(t_cub *cub, char *str);
int				check_line(char *str, t_cub *cub);
int				check_line2(char *str);
int				check_infos(t_cub *cub);
int				check_map_null(t_cub *cub, char *str);
int				check_player(t_cub *cub, char *str, int i, int a);
int				check_element(char *str, t_cub *cub);
void			init_info(t_cub *cub);
int				recup_r(char *str, t_cub *cub, int i);
int				recup_s(char *str, t_cub *cub);
int				recup_no(char *str, t_cub *cub);
int				recup_we(char *str, t_cub *cub);
int				check_map(char *str, t_cub *cub);
int				check_cub(char *str);
int				check_texture(char *str);
int				check_re_texture(t_cub *cub);
int				check_file(char *str, t_cub *cub);
int				recup_map(t_cub *cub, char *str);
int				check_next(t_cub *cub, char *str);
int				recup_c(char *str, t_cub *cub);
int				recup_ea(char *str, t_cub *cub);
int				recup_so(char *str, t_cub *cub);
void			recup_pos(t_cub *cub);
void			init_cub(t_cub *cub);
// int				first_calcul(t_cub *cub, t_map *map, t_img *img);
int				ft_quit(t_cub *cub);
// void			time(t_cub *cub, t_map *map, t_img *img, int x);
// void			init_raycasting(t_cub *cub);
// void	raycast(t_cub *cub, t_map *map, t_img *img);
// void	recup_angle(t_map *map, t_cub *cub);
void	free_map(t_cub *cub);
int		check_integer(t_cub *cub);
void	init_raycast(t_cub *cub);
void	raycast1(t_cub *cub);
int	minimap1(t_cub *cub);
void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
int	minimap2(t_cub *cub, int k);
void	recup_textures(t_cub *cub);
// int		first_calcul(t_cub *cub, t_map *map, t_img *img);

#endif

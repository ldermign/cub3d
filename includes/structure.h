/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 08:19:05 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/06 14:03:49 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

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

typedef	struct	s_argmts {
	int			tmp;
    int         last;
    int         len_fd;
	int 		flr_r;
	int		 	flr_g;
	int 		flr_b;
	int 		ciel_r;
	int			ciel_g;
	int 		ciel_b;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*sprite;
	char		**fd;
    char        **map;
	int         player;
    double		plrX;
    double		plrY;
}				t_arg;

typedef struct  s_data {
    void        *mlx;
    void        *win;
    void        *img;
    char        *addr;
    int         bpp;
    int         size_line;
    int         endian;
	int			width;
	int			height;
	int			sky;
	int			floor;

    int x;
    int y;
}               t_mlx;

typedef struct  s_calculs {
	int hit;
	int side;
	double plrX; // vecteur positionnel du joueur // position
	double plrY;
	double dirX; // direction du joueur
	double dirY;
	double planeX; // plan camera du joueur
	double planeY;
	double speed;
	double rota;
	double cameraX;
	double rayDirX;
	double rayDirY;
	int mapX; // carre dans lequel le rayon est
	int mapY;
	int stepX; 	//what direction to step in x or y-direction (either +1 or -1)
	int stepY;
	double sideDistX; // distance que le rayon a a parcourir jusqu'au mur
	double sideDistY; //length of ray from current position to next x or y-side
	double deltaDistX;
	double deltaDistY;
	int	drawStart;
	int	drawEnd;
	double perpWallDist;
}				t_calc;

typedef struct  s_structure {
	t_arg *data;
	t_mlx *img;
	t_calc *cls;
}				t_s;

// typedef struct  s_input {
//     int sp;
//     int ret;
//     int w;
//     int a;
//     int s;
//     int d;
//     int f;
//     int l;
//     int m;
//     int arr_u;
//     int arr_d;
//     int arr_l;
//     int arr_r;
//     int mouse_l;
//     int mouse_r;
//     int touche;
// }               t_ipt;

t_s	*s(void);

/*
**  POINTEUR SUR FONCTION
*/

typedef struct s_recup_data
{
	char	conv[3 + 1];
	int		(*f)(t_arg *data, char *str);
}	t_recup;

typedef struct s_texture
{
	char	conv[3 + 1];
	char	*(*f)(t_arg *data, char *str, char a, char b);
	char	**ptr;
}	t_text;

typedef struct s_colors
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	t;
}	t_color;

#endif
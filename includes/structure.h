/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 08:19:05 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/10 16:24:16 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			*text;
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	int			endian;
}				t_mlx;

typedef struct s_texture
{
	char	texture[600][600];
	double	texpos;
	int		texnum;
	int		tex_x;
	int		width_no;
	int		height_no;
	int		width_we;
	int		height_we;
	int		width_so;
	int		height_so;
	int		width_ea;
	int		height_ea;
	int		tex_width;
	int		tex_height;
	int		tex_y;
	int		*txt_north;
	int		*txt_south;
	int		*txt_east;
	int		*txt_west;
	int		*txt_sprite;
}				t_text;

typedef struct s_argmts
{
	int			f;
	int			c;
	int			tmp;
	int			last;
	int			len_fd;
	int			flr_r;
	int			flr_g;
	int			flr_b;
	int			ciel_r;
	int			ciel_g;
	int			ciel_b;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*sprite;
	char		**fd;
	char		**map;
	int			player;
	double		plr_x;
	double		plr_y;
}				t_arg;

typedef struct s_cub
{
	double	pos_x;				//position x du joueur
	double	pos_y;				//position y du joueur
	double	dir_x;				//vecteur de direction initiale
	double	dir_y;				//vecteur de direction initiale
	double	plane_x;			//j'sais plus
	double	plane_y;			//j'sais plus
	double	camera_x;			//abscisse de camera
	double	raydir_x;			//calcul de direction x du rayon
	double	raydir_y;			//calcul de direction y du rayon
	double	side_dist_x;		//longueur entre position actuelle et prochain x ou y
	double	side_dist_y;		//longueur entre position actuelle et prochain x ou y
	double	delta_dist_x;		//longueur entre cote x ou y jusqu'a autre cote x ou y
	double	delta_dist_y;		//longueur entre cote x ou y jusqu'a autre cote x ou y
	double	perp_wall_dist;		//distance jusqu'au mur perpandiculaire au plan camera
	double	olddir_x;
	double	oldplane_x;
	int		step_x;				//dans quelle direction avancer
	int		step_y;				//dans quelle direction avancer
	int		map_x;				//dans quel carre on est
	int		map_y;				//dans quel carre on est
	int		drawstart;			//plus haut pixel a afficher
	int		drawend;			//plus bas pixel a afficher
	int		lineheight;
	int		hit;
	int		side;
	int		x;					//x ecran
	int		y;					//y ecran
	int		a2;					//largeur carre
	int		mini;
	t_text	text;
	t_mlx	*img_mlx;
	t_arg	*args;
}				t_cub;

typedef struct s_colors
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	t;
}	t_color;

typedef struct s_structure
{
	t_cub	cub;
	t_arg	data;
	t_mlx	img;
}	t_struct;

#endif

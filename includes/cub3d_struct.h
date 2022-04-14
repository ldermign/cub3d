/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 08:19:05 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/14 02:45:51 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

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
	double	texpos;
	int		texnum;
	int		tex_x;
	int		tex_y;
	int		tex_width;
	int		tex_height;
	char	*text_data;
	int		*texture_jsp;
	int		w;
	int		h;
	int		size_line;
	int		*text;
	void	*img_text;
}				t_text;

typedef struct s_argmts
{
	int			f;
	int			check_f;
	int			c;
	int			check_c;
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
	char		**fd;
	char		**map;
	int			player;
	double		plr_x;
	double		plr_y;
}				t_arg;

typedef struct s_cub
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	olddir_x;
	double	oldplane_x;
	double	wall_x;
	double	step;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		drawstart;
	int		drawend;
	int		lineheight;
	int		hit;
	int		side;
	int		x;
	int		y;
	t_text	all_txt[4];
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
	t_text	txt;
}	t_struct;

#endif

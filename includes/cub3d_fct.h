/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_fct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:37:27 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/09 19:27:51 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_FCT_H
# define CUB3D_FCT_H

/*
**	CHECK PARSING
*/

int		ft_save(char *arg);
int		ft_check_arg(int ac, char **ag);
int		check_map(t_arg *data);
int		check_wrong_data_and_recup(t_arg *data);
int		check_floor_sky(t_arg *data, char *str);
int		check_textures(t_arg *data);

/*
**	GET INFOS MAP.CUB
*/

int		gnl_mapcub(t_arg *data, char *arg);
int		recup_map(t_arg *data);
int		check_space_sprite_and_plr_map(t_arg *data, char **map, char c);
int		check_start_end_map(t_arg *data, char **map, int plr);
int		check_interior_map(t_arg *data, char **map, int plr);
void	ft_fill_map(t_arg *data, int len, int start, int larger);
void	save_mapcub_in_char(t_arg *data, char *arg);
char	*get_name_texture(t_arg *data, char *new_text, char *needle);
int		get_sky(t_arg *data, char *str);
int		get_floor(t_arg *data, char *str);

/*
**	TEST LIENA TEXTURES
*/

void	get_texture(t_cub *cub, t_arg *arg);

/*
**	INIT
*/

void	init_struct_arg(t_arg *data);

/*
**	UTILS
*/

int		ft_int_strstr(char *str, char *needle);
int		ft_int_strchr(const char *str, int c);
void	free_str(char **tab);

/*
**	UTILS PARSING
*/

int		is_map(char *str);

/*
**	COLORS
*/

int		create_trgb(int t, int r, int g, int b);
// void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);

/*
**  UTILS MAP
*/

int		space_or_element(int c);
int		ft_is_player(int c);
void	map_valid(char **tab);
int		cara_in_map(int c);
int		ft_is_noting(char *str);
int		ft_is_either(char *str);
int		get_position(char **tab, int c);
int		which_is_larger(char **tab);
char	*ft_strdup_map_line(char *s1, int length);
int		size_tab_char(char **tab);
int		ft_strchr_tab_wrong_cara(char **tab);
int		return_player(char **map);
int		how_many_player(t_arg *data, char **map);
void	get_position_player(t_arg *data);

/*
**  EXIT
*/

void	quit(t_arg *data, char *str_err, int i, int place);
int		quit_parsing(t_arg *data, char *str_err, int i, int place);
void	quit_image(t_cub *cub);

/*
**	SUPPRIMER
*/

void	printf_struct_arg(t_arg data);

/*
**  RAYCASTING
*/

int		ft_loop(t_cub *cub);
int		ft_quit(t_struct *all);
void	init2(t_cub *cub, int x);
void	init_background(t_cub *cub, int x, int y);
void	init_raycast(t_cub *cub);
void	init_raycast2(t_cub *cub);
int		key_press(int key_code, t_struct *all);
void	key_press_a(t_cub *cub);
void	key_press_d(t_cub *cub);
void	key_press_m(t_cub *cub);
int		minimap1(t_cub *cub);
int		minimap2(t_cub *cub, int k);
void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
void	print(t_cub cub);
void	raycast1(t_cub *cub);
void	recup_pos(t_cub *cub);
void	draw_img(t_cub *cub);
void	window(t_struct *all);
int		ft_loop(t_cub *cub);
void	window(t_struct *all);

#endif

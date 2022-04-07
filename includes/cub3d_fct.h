/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_fct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:37:27 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/07 14:27:35 by ldermign         ###   ########.fr       */
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

/*
**	GET INFOS MAP.CUB
*/

int		gnl_mapcub(t_arg *data, char *arg);
int		recup_data(t_arg *data, char *str);
int		recup_map(t_arg *data);
int		check_space_sprite_and_plr_map(t_arg *data, char **map, char c);
int		check_start_end_map(t_arg *data, char **map, int plr);
int		check_interior_map(t_arg *data, char **map, int plr);
void	ft_fill_map(t_arg *data, int len, int start, int larger);
void	save_mapcub_in_char(t_arg *data, char *arg);
char	*get_texture(t_arg *data, char *new_text, char *needle);
int		get_sky(t_arg *data, char *str);
int		get_floor(t_arg *data, char *str);

/*
**	RAYCASTING
*/

int	all_calculs_cub(t_mlx *img, t_calc *cls, t_arg *data);

/*
**	R CALCULS
*/



/*
**  R UTILS
*/



/*
**	UTILS
*/

int		ft_int_strstr(char *str, char *needle);
int		ft_int_strchr(const char *str, int c);
void	free_str(char **tab);

/*
**	UTILS PARSING
*/

int	is_map(char *str);

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
void	quit_image(t_mlx *img);
int	quit_parsing(t_arg *data, char *str_err, int i, int place);
void	quit_structure();
void	quit_image_2(t_cub *cub);

/*
**	SUPPRIMER
*/

void	printf_struct_arg(t_arg data);



/*
**  RAYCASTING
*/


void	init2(t_cub *cub, int x);
void	init_raycast(t_cub *cub);
void	init_raycast2(t_cub *cub);
void	print(t_cub cub);
void	window(t_cub *cub);
void    init_background(t_cub *cub, int c, int f, int x, int y);
int		ft_quit(t_cub *cub);
int		ft_loop(t_cub *cub);
void	test(t_cub *cub);
int		key_press(int key_code, t_cub *cub);
int		ft_loop(t_cub *cub);
void	init_background(t_cub *cub, int c, int f, int x, int y);
void	window(t_cub *cub);
int		ft_quit(t_cub *cub);
void	init_raycast(t_cub *cub);
void	raycast1(t_cub *cub);
int		minimap1(t_cub *cub);
void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
int		minimap2(t_cub *cub, int k);
void	recup_pos(t_cub *cub);
void	key_press_d(t_cub *cub);
void	key_press_a(t_cub *cub);
void	key_press_m(t_cub *cub);




#endif
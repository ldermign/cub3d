/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:40:28 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/05 14:21:08 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "structure.h"

# define KM_W 13
# define KM_A 0
# define KM_S 1
# define KM_D 2
# define KM_F 3
# define KM_M 46
# define KM_SPACE 49
# define KM_UP 126
# define KM_DOWN 125
# define KM_LEFT 123
# define KM_RIGht 124
# define KM_ENTER 36
# define KM_DELETE 51
# define KM_LM 1
# define KM_RM 2
# define KM_MUP 5
# define KM_MDOWN 4
# define KM_ESC 53

// # define KL_W
// # define KL_A
// # define KL_S
// # define KL_D
// # define KL_F
// # define KL_M
// # define KL_SPACE
// # define KL_UP
// # define KL_DOWN
// # define KL_LEFT
// # define KL_RIGht
// # define KL_ENTER
// # define KL_DELETE
// # define KL_LM
// # define KL_RM
// # define KL_MUP
// # define KL_MDOWN
// # define KL_ESC


/*
**	CHECK PARSING
*/

int		ft__save(char *arg);
int		ft_check_name_map(char *arg);
void	ft_check_arg(int ac, char **ag);
void	check_map(t_arg *data);
void	check_wrong_data_and_recup(t_arg *data);
void	check_resolution(t_arg *data, char *str);
void	check_floor_sky(t_arg *data, char *str);

/*
**	GET INFOS MAP.CUB
*/

void	gnl_mapcub(t_arg *data, char *arg);
void	recup_data(t_arg *data, char *str);
void	recup_map(t_arg *data);
void	check_space_sprite_and_plr_map(t_arg *data, char **map, char c);
void	check_start_end_map(t_arg *data, char **map, int plr);
void	check_interior_map(t_arg *data, char **map, int plr);
void	ft_fill_map(t_arg *data, int len, int start, int larger);
void	save_mapcub_in_char(t_arg *data, char *arg);
void	if_texture(t_arg *data, char *str);
char	*get_texture(t_arg *data, char *str, char a, char b);
void	get_sky(t_arg *data, char *str);
void	get_floor(t_arg *data, char *str);
void	get_resolution(t_arg *data, char *str);

/*
**	RAYCASTING
*/



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
int		create_trgb(int t, int r, int g, int b);

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






























/*
**  A TEJ
*/


#define KRED  "\x1B[0;31m" // ROUGE
#define KGRN  "\x1B[0;32m" // VERT
#define KYEL  "\x1B[0;33m" // JAUNE
#define KBLU  "\x1B[0;34m" // BLEU
#define KMAG  "\x1B[0;35m" // MAGENTA
#define KCYN  "\x1B[0;36m" // CYAN
#define KWHT  "\x1B[0;37m" // BLANC
#define KGRE  "\x1b[1;30m" // GRIS
#define CLR_COLOR "\x1b[0m" // CLEAR COLOR
void	printf_struct_arg(t_arg data);

#endif


/*
RGB colors can be initialized as above, a few examples would be:
Red: 0x00FF0000;
Green: 0x0000FF00;
Blue: 0x000000FF;
Keycode
w = 0x0D
space = 49
arrow up = 126
arrow down = 125
arrow left = 123
arrow right = 124
s = 1
a = 0
d = 2
f = 3
m = 46
l = 37
enter = 36
delete = 51
left mouse = 1
right mouse = 2
molette haut = 5
molette bas = 4
esc = 53
*/


//              1111111111111111111111111
//              1000000001100000000000001
//              1011000001110000000000001
//              1001000000000000000000001
//      111111111011000001110000000000001
//      100000000110000011101111111111111
//      1110111111111011100000010001
//      11110111111111011101010010001
//   111110000001101010111000000100001111111
//  100000020000000000011000000100000011011
//  1000000000000000000110101001N00000011
//  111000001110001011111011110000000111
//    111111011111110101 1011110100000001
//      1111111 1111111 11111111111111111
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/28 17:09:11 by ldermign          #+#    #+#              #
#    Updated: 2022/04/14 01:00:03 by ejahan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d

SRCS	=	./srcs/main.c \
			./srcs/parsing/get_mapcub_infos.c \
			./srcs/parsing/get_map.c \
			./srcs/colors.c \
			./srcs/parsing/check_reso_floor_sky.c \
			./srcs/parsing/first_step_parsing.c \
			./srcs/parsing/check_arg.c \
			./srcs/parsing/simple_utils.c \
			./srcs/init/init.c \
			./srcs/utils/utils.c \
			./srcs/utils/utils_check_get_player.c \
			./srcs/utils/utils_parsing_1.c \
			./srcs/utils/utils_parsing_2.c \
			./srcs/utils/utils_parsing_map.c \
			./srcs/others/clean_exit.c \
			./srcs/raycasting/raycasting.c \
			./srcs/raycasting/utils.c \
			./srcs/raycasting/init.c \
			./srcs/raycasting/key_press.c \
			./srcs/raycasting/key_press2.c \
			./srcs/raycasting/draw.c \
			./srcs/raycasting/texture.c 

SRCS_BONUS	=	./srcs_bonus/main_bonus.c \
				./srcs_bonus/parsing/get_mapcub_infos_bonus.c \
				./srcs_bonus/parsing/get_map_bonus.c \
				./srcs_bonus/colors_bonus.c \
				./srcs_bonus/parsing/check_reso_floor_sky_bonus.c \
				./srcs_bonus/parsing/first_step_parsing_bonus.c \
				./srcs_bonus/parsing/check_arg_bonus.c \
				./srcs_bonus/parsing/simple_utils_bonus.c \
				./srcs_bonus/init/init_bonus.c \
				./srcs_bonus/utils/utils_bonus.c \
				./srcs_bonus/utils/utils_check_get_player_bonus.c \
				./srcs_bonus/utils/utils_parsing_1_bonus.c \
				./srcs_bonus/utils/utils_parsing_2_bonus.c \
				./srcs_bonus/utils/utils_parsing_map_bonus.c \
				./srcs_bonus/others/clean_exit_bonus.c \
				./srcs_bonus/raycasting/raycasting_bonus.c \
				./srcs_bonus/raycasting/utils_bonus.c \
				./srcs_bonus/raycasting/minimap_bonus.c \
				./srcs_bonus/raycasting/init_bonus.c \
				./srcs_bonus/raycasting/key_press_bonus.c \
				./srcs_bonus/raycasting/key_press2_bonus.c \
				./srcs_bonus/raycasting/draw_bonus.c \
				./srcs_bonus/raycasting/texture_bonus.c 

INCS	=	./includes/

INCS_BONUS	=	./includes_bonus/

OBJS	=	${SRCS:.c=.o}

OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

DEPS	=	${SRCS:.c=.d}

CC		=	clang

MLX		=	libmlx_Linux.a

CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address -I ${INCS} -I ./mlx/ #-Ofast #-fsanitize=address

CFLAGS_BONUS	=	-Wall -Wextra -Werror -g3 -fsanitize=address -I ${INCS_BONUS} -I ./mlx/ -Ofast #-fsanitize=address

MLXFLG	=	-Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 

RM		=	rm -rf

all:		${NAME}

${NAME}:	${OBJS} ${INCS}
			${MAKE} -C libft
			${MAKE} -C mlx
			${CC} -o ${NAME} ${OBJS} ${CFLAGS} ${MLXFLG} libft/libft.a mlx/libmlx_Linux.a

-include	${DEPS}

.c.o:		${CC} ${CFLAGS} -MMD -MP -MF ${@:.o=.d} -c $< -o ${<:c=o}

clean:
			${MAKE} -C libft clean
			${MAKE} -C mlx clean
			${RM} ${OBJS} ${DEPS}
			${RM} ${OBJS_BONUS}

fclean:		clean
			${MAKE} -C libft fclean
			${RM} ${MLX}
			${RM} ${NAME}

re:			fclean all

bonus:		${OBJS_BONUS} ${INCS_BONUS}
			${MAKE} -C libft
			${MAKE} -C mlx
			${CC} -o ${NAME} ${OBJS_BONUS} ${CFLAGS_BONUS} ${MLXFLG} libft/libft.a mlx/libmlx_Linux.a
			

.PHONY: 	all clean fclean re bonus

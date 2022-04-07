# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/28 17:09:11 by ldermign          #+#    #+#              #
#    Updated: 2022/04/07 15:06:52 by ldermign         ###   ########.fr        #
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
			./srcs/supprimer.c \
			./srcs/raycasting/raycasting.c \
			./srcs/raycasting/utils.c \
			./srcs/raycasting/minimap.c \
			./srcs/raycasting/init.c \
			./srcs/raycasting/key_press.c \
			./srcs/raycasting/key_press2.c 

INCS	=	./includes/

OBJS	=	${SRCS:.c=.o}

DEPS	=	${SRCS:.c=.d}

CC		=	clang

MLX		=	libmlx_Linux.a

CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address -I ${INCS} -I ./mlx/ #-fsanitize=address

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

fclean:		clean
			${MAKE} -C libft fclean
			${RM} ${MLX}
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re

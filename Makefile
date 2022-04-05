# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/28 17:09:11 by ldermign          #+#    #+#              #
#    Updated: 2022/04/05 14:24:32 by ldermign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d

SRCS	=	./main.c \
			./parsing/get_mapcub_infos.c \
			./parsing/get_map.c \
			./colors.c \
			./parsing/check_reso_floor_sky.c \
			./parsing/first_step_parsing.c \
			./parsing/check_arg.c \
			./utils/utils.c \
			./utils/utils_check_get_player.c \
			./utils/utils_parsing_1.c \
			./utils/utils_parsing_2.c \
			./utils/utils_parsing_map.c \
			./others/clean_exit.c \
			./others/print_utils.c

INCS	=	./includes/

OBJS	=	${SRCS:.c=.o}

CC		=	clang

MLX		=	libmlx_Linux.a

CFLAGS	=	-Wall -Wextra -Werror -g3 -I ${INCS} -I ./mlx/

MLXFLG	=	-Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

RM		=	rm -rf

all:		${NAME}

${NAME}:	${OBJS} ${INCS}
			${MAKE} -C libft
			${MAKE} -C mlx
			${CC} -o ${NAME} ${OBJS} ${CFALGS} ${MLXFLG} libft/libft.a mlx/libmlx_Linux.a

.c.o:		${CC} ${CFLAGS} -c $< -o ${<:c=o}

clean:
			${MAKE} -C libft clean
			${MAKE} -C mlx clean
			${RM} ${OBJS}

fclean:		clean
			${MAKE} -C libft fclean
			${RM} ${MLX}
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re

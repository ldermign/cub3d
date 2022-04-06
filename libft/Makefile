# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 19:45:34 by ldermign          #+#    #+#              #
#    Updated: 2022/04/06 10:14:10 by ldermign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	./srcs/libft/ft_atoi.c \
			./srcs/libft/ft_atol.c \
			./srcs/libft/ft_binary.c \
			./srcs/libft/ft_bzero.c \
			./srcs/libft/ft_calloc.c \
			./srcs/libft/ft_free_tab.c \
			./srcs/libft/ft_int_strstr.c \
			./srcs/libft/ft_int_strchr.c \
			./srcs/libft/ft_isalnum.c \
			./srcs/libft/ft_isalpha.c \
			./srcs/libft/ft_isascii.c \
			./srcs/libft/ft_isdigit.c \
			./srcs/libft/ft_isprint.c \
			./srcs/libft/ft_itoa.c \
			./srcs/libft/ft_len_int.c \
			./srcs/libft/ft_lstadd_front.c \
			./srcs/libft/ft_lstdelone.c \
			./srcs/libft/ft_lstnew.c \
			./srcs/libft/ft_lstsize.c \
			./srcs/libft/ft_memccpy.c \
			./srcs/libft/ft_memchr.c \
			./srcs/libft/ft_memcmp.c \
			./srcs/libft/ft_memcpy.c \
			./srcs/libft/ft_memmove.c \
			./srcs/libft/ft_memset.c \
			./srcs/libft/ft_pos_strchr.c \
			./srcs/libft/ft_putchar.c \
			./srcs/libft/ft_putchar_fd.c \
			./srcs/libft/ft_putendl_fd.c \
			./srcs/libft/ft_putnbr_fd.c \
			./srcs/libft/ft_putstr.c \
			./srcs/libft/ft_putstr_fd.c \
			./srcs/libft/ft_random.c \
			./srcs/libft/ft_split.c \
			./srcs/libft/ft_strcat.c \
			./srcs/libft/ft_strchr.c \
			./srcs/libft/ft_strcmp.c \
			./srcs/libft/ft_strcpy.c \
			./srcs/libft/ft_strdup.c \
			./srcs/libft/ft_strjoin.c \
			./srcs/libft/ft_strlcat.c \
			./srcs/libft/ft_strlcpy.c \
			./srcs/libft/ft_strlen.c \
			./srcs/libft/ft_strmapi.c \
			./srcs/libft/ft_strncat.c \
			./srcs/libft/ft_strncmp.c \
			./srcs/libft/ft_strncpy.c \
			./srcs/libft/ft_strnstr.c \
			./srcs/libft/ft_strrchr.c \
			./srcs/libft/ft_strtrim.c \
			./srcs/libft/ft_substr.c \
			./srcs/libft/ft_swap.c \
			./srcs/libft/ft_tolower.c \
			./srcs/libft/ft_toupper.c

# Gnl srcs
SRCS	+=	./srcs/get_next_line/get_next_line.c \
			./srcs/get_next_line/get_next_line_utils.c

IDIR	=	./includes/

OBJS	=	${SRCS:.c=.o}

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror -I ${IDIR}

LIBC	=	ar rc

LIBR	=	ranlib

RM		=	rm -f

all:		${NAME}

${NAME}:	${OBJS} ${IDIR}
			${LIBC} ${NAME} ${OBJS}
			${LIBR}	${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o $@

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: david <david@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 14:23:43 by unix              #+#    #+#              #
#    Updated: 2022/02/22 17:06:27 by david            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = so_long.c read_map.c render_utils.c key_press.c animate.c move_gost.c

HEADER = so_long.h

OBJS		=	$(SRCS:%.c=%.o)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

LIBFT		=	libft/libft.a
LIBFT_DIR	=	libft

MLXFLAGS	=	-L ./mlx/ -lmlx -framework OpenGL -framework AppKit -lz
MLXDIR		=	./mlx/

ifeq ($(shell uname), Linux)
MLXFLAGS	=	-L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11
MLXDIR		=	./mlx_linux/
endif

all:		$(NAME)

$(NAME):	$(OBJS) $(HEADERS)
			@make -s -C $(MLXDIR)
			@make bonus -s -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLXFLAGS) -lm

%.o : %.c $(HEADERS)
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			make clean -s -C $(LIBFT_DIR)
			make clean -s -C $(MLXDIR)

re:			fclean all

run:		all
			./so_long ./maps/map.ber

val:		all
			valgrind ./so_long ./maps/map1.cub

.PHONY:		all clean fclean re run val
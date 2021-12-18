# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 14:23:43 by unix              #+#    #+#              #
#    Updated: 2021/12/18 11:18:52 by tyamcha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc 
FLAGS = -g
#FLAGS = -Wall -Werror -Wextra

LIB = libft.a

MINILIBX = -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit

HEADER = so_long.h

MAIN_FILES = so_long.c read_map.c

MAIN_OBJ_FILES = $(MAIN_FILES:.c=.o)

RM = rm -f

all: $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(MAIN_OBJ_FILES) $(HEADER)
	make bonus -C ./libft
	cp libft/libft.a ./
	$(CC) $(FLAGS) $(MINILIBX) -o $(NAME) $(MAIN_OBJ_FILES) $(LIB)

clean:
#	make clean -C ./libft
	$(RM) $(MAIN_OBJ_FILES) $(BONUS_OBJ_FILES)

fclean: clean
#	make fclean -C ./libft
	$(RM) $(NAME) $(BONUS_NAME) libft.a

re: fclean all

.PHONY: all clean fclean re bonus
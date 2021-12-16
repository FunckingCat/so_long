# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 14:23:43 by unix              #+#    #+#              #
#    Updated: 2021/12/16 11:03:14 by tyamcha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
FLAGS = 
#FLAGS = -Wall -Werror -Wextra

LIB = -L '.' -lft

MINILIBX = -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit

HEADER = so_long.h

MAIN_FILES = so_long.c

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
	make clean -C ./libft
	$(RM) $(MAIN_OBJ_FILES) $(BONUS_OBJ_FILES)

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME) $(BONUS_NAME) libft.a

re: fclean all

.PHONY: all clean fclean re bonus
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 14:23:43 by unix              #+#    #+#              #
#    Updated: 2021/12/16 10:37:56 by tyamcha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
FLAGS = 
#FLAGS = -Wall -Werror -Wextra
LIB = -L '.' -lft 

HEADER = so_long.h

MAIN_FILES = so_long.c

MAIN_OBJ_FILES = $(MAIN_FILES:.c=.o)

RM = rm -f

all: $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(MAIN_OBJ_FILES) $(HEADER)
	make bonus -C ./libft
	@make -C ./mlx
	cp libft/libft.a ./
	cp mlx/libmlx.a ./
	$(CC) $(FLAGS) -o $(NAME) $(MAIN_OBJ_FILES) $(LIB)

clean:
	make clean -C ./libft
	make clean -C ./mlx
	$(RM) $(MAIN_OBJ_FILES) $(BONUS_OBJ_FILES)

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME) $(BONUS_NAME) libft.a libmlx.a

re: fclean all

.PHONY: all clean fclean re bonus
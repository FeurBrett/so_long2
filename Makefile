# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 11:40:26 by apirovan          #+#    #+#              #
#    Updated: 2023/03/09 17:37:33 by apirovan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Compile 

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRCS = ft_error.c ft_init_map.c ft_split.c map_utils.c ft_init_img.c main.c basic_fcts.c ft_check_win.c ft_fill_data.c ft_moves.c ft_moves_utils.c
INCSDIR = Includes
OBJSDIR = Objs
MLXDIR = mlx
OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: ${NAME}

clean:
	rm -f *.o

fclean:
	make clean
	rm -f $(NAME)
	
re:
	make fclean
	make

.PHONY: all clean fclean re
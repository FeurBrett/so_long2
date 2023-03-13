# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 11:40:26 by apirovan          #+#    #+#              #
#    Updated: 2023/03/13 19:08:44 by apirovan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Compile 

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRCS = ft_error.c ft_init_map.c path_finding.c ft_split.c map_utils.c ft_init_img.c main.c basic_fcts.c ft_check_win.c ft_fill_data.c ft_moves.c ft_moves_utils.c ft_printf/ft_itoa.c ft_printf/ft_pr_point.c ft_printf/ft_printf_utils.c ft_printf/ft_printf.c
MLXDIR = mlx
OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: ${NAME}

clean:
	rm -f *.o ft_printf/*.o

fclean:
	make clean
	rm -f $(NAME)
	
re:
	make fclean
	make

.PHONY: all clean fclean re
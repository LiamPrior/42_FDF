# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprior <lprior@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/06 12:19:27 by lprior            #+#    #+#              #
#    Updated: 2018/03/27 09:56:15 by lprior           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libx_flags = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

cflags = -Wall -Wextra -Werror

make_libft = @make -C ./libft/

header = fdf.h

includes = ./libft/libft.a ./minilibx_macos/libmlx.a

SRC = main.c ft_initialize.c ft_lists.c ft_utilities.c ft_rotation.c ft_draw.c ft_mlx.c

OBJ = *.o

cc = @gcc -g

name = fdf

all : $(name)

$(name) :
	@make -C libft/
	$(cc) $(cflags) $(libx_flags) $(SRC) $(includes) -o $(name)
	@echo "Created FDF executable"
clean:
	@make -C libft/ clean
	@/bin/rm -f $(name)
fclean: clean
	@make -C libft/ fclean
re: fclean all
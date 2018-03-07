# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprior <lprior@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/06 12:19:27 by lprior            #+#    #+#              #
#    Updated: 2018/03/06 13:36:12 by lprior           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libx_flags = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

cflags = -Wall -Wextra -Werror

make_libft = @make -C ./GNL/libft/

header = fdf.h

includes = ./GNL/libft/libft.a ./GNL/get_next_line.c

SRC = main.c

OBJ = *.o

cc = @gcc

name = fdf

all : $(name)

$(name) :
	@make -C GNL/libft/
	$(cc) $(libx_flags) $(SRC) $(includes) -o $(name)
	@echo "Created FDF executable"
clean:
	@make -C GNL/libft/ clean
	@/bin/rm -f $(name)
fclean: clean
	@make -C GNL/libft/ fclean
re: fclean all
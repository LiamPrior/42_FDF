# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprior <lprior@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 10:44:33 by lprior            #+#    #+#              #
#    Updated: 2018/02/17 23:17:17 by lprior           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror 

SRC = ft_fwap.c ft_parsec.c ft_parsef.c ft_printf.c ft_basic_print.c \
	ft_print_pup.c ft_wchar_bonus.c ft_parse_tools.c ft_check.c ft_prints.c \
	ft_conversion_tools.c

OBJECTS = *.o

LIBFT_SRC = libft/*.c

all: $(NAME) 

$(NAME): 
		gcc $(FLAGS) -c $(SRC) $(LIBFT_SRC)
		ar rcs $(NAME) $(OBJECTS)
		ranlib $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
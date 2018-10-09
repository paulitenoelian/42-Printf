# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npaulite <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 09:58:04 by npaulite          #+#    #+#              #
#    Updated: 2018/10/06 10:56:47 by npaulite         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =   ft_printf.c ft_format.c ft_type.c write_nbr.c ft_is.c ft_wp.c\
	fill_zero.c add_width.c change_color.c ft_sc.c no_print.c ft_type.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all:
	@gcc -c $(FLAGS) $(SRC)

clean:
	@rm -rf $(OBJ)

fclean: clean

re: fclean all

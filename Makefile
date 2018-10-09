# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npaulite <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/04 09:48:51 by npaulite          #+#    #+#              #
#    Updated: 2018/10/06 12:20:38 by npaulite         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I includes/

SRC = ft_printf.c ft_format.c ft_type.c write_nbr.c ft_is.c ft_wp.c      \
	  ft_sc.c fill_zero.c add_width.c no_print.c change_color.c

SRCS = $(addprefix srcs/, $(SRC))

OBJ = $(SRC:.c=.o)

OBJS = $(addprefix objs/, $(OBJ))

LIB = libft/srcs/*.c

LIBS = libft/objs/*.o

all: $(NAME)

$(NAME): lib $(OBJS)
	@ar -rc $(NAME) $(OBJS) $(LIBS)

objs/%.o: srcs/%.c | objs
	@gcc $(CFLAGS) -I libft/ -o $@ -c $^
lib:
	@make -C ./libft
clean:
	@make clean -C ./libft
	@make clean -C ./srcs
	@rm -rf objs/

fclean: clean
	@make fclean -C ./libft
	@make fclean -C ./srcs
	@rm -rf $(NAME)

re: fclean all

objs:
	@mkdir objs/

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npaulite <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/04 09:48:51 by npaulite          #+#    #+#              #
#    Updated: 2018/10/21 07:54:10 by npaulite         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I includes/

SRC = ft_printf.c ft_params.c ft_null.c ft_printf_percent.c \
      ft_tools.c ft_printf_int.c ft_printf_long.c ft_printf_char.c \
      ft_printf_str.c ft_printf_hex.c ft_printf_octal.c ft_printf_unsign.c \
      ft_printf_void.c \

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
	@rm -rf objs/

fclean: clean
	@make fclean -C ./libft
	@rm -rf $(NAME)

re: fclean all

objs:
	@mkdir objs/

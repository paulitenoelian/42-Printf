# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npaulite <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/04 09:48:51 by npaulite          #+#    #+#              #
#    Updated: 2018/10/11 12:52:18 by npaulite         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I includes/

SRC = char.c char_unicode.c check_funcs.c decimal.c\
      format_write_funcs.c ft_itoa_base.c /ft_printf.c\
      get_var_param.c hexadecimal.c \
      octodecimal.c output_format_funcs.c percent.c\
      pointer.c print_type.c service_funcs.c string.c\
      type_processing.c unicode_to_string.c unsigned.c wrong_var.c\
      cnt_bytes.c bonus_star.c

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

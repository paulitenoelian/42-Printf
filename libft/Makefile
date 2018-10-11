#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npaulite <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/09 16:13:09 by npaulite          #+#    #+#              #
#    Updated: 2018/10/11 13:06:21 by npaulite         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

HEADER += -I includes/

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c\
	ft_strcat.c ft_strncpy.c ft_strncat.c ft_strlcat.c ft_strchr.c\
	ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c\
	ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
	ft_isprint.c ft_toupper.c ft_tolower.c ft_putchar.c ft_putstr.c\
	ft_putnbr.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strclr.c\
	ft_striter.c ft_striteri.c ft_strmap.c ft_putendl.c ft_putchar_fd.c\
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strdel.c\
	ft_strequ.c ft_strnequ.c ft_itoa.c ft_strsub.c ft_strjoin.c\
       	ft_strtrim.c ft_strmapi.c ft_strsplit.c ft_lstnew.c\
	ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c\
	ft_lstmap.c ft_lstaddback.c ft_lstrev.c ft_absnum.c ft_capitalize.c\
	ft_realloc.c ft_replace.c ft_strreplace.c ft_sizebyte.c ft_sizewchar.c\
	ft_wstrlen.c ft_wnstrlen.c ft_recursive_factorial.c ft_recursive_power.c \
	ft_base.c ft_power.c ft_init_str.c ft_itoah.c ft_itoab.c \
	ft_lltoa.c ft_lltoah.c ft_lltoab.c ft_lltoao.c ft_ulltoa.c \
	ft_putwchar.c ft_putwstr.c ft_putnstr.c ft_putnwstr.c ft_put_error.c \
	ft_free_str_arr.c ft_putchars.c	ft_putendls.c ft_putnbrs.c ft_putstrs.c \
	ft_putchars_fd.c ft_putendls_fd.c ft_putnbrs_fd.c ft_putstrs_fd.c \

OBJ = $(SRC:.c=.o)

SRCDIR = srcs/

OBJDIR = objs/

SRCS = $(addprefix $(SRCDIR), $(SRC))

OBJS = $(addprefix $(OBJDIR), $(OBJ))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

objs/%.o: srcs/%.c | objs
	@gcc $(CFLAGS) $(HEADER) -o $@ -c $^

clean: 
	@/bin/rm -rf $(OBJDIR)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

objs:
	@mkdir objs/

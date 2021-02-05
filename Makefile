# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/03 09:31:57 by xli               #+#    #+#              #
#    Updated: 2021/02/03 15:42:29 by xli              ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = 	ft_printf.c ./utiles/ft_atoi.c ./utiles/ft_strlen.c ./utiles/ft_comp.c\
		./utiles/ft_itoa.c ./utiles/ft_itoa_base.c ./utiles/ft_putchar.c\
		./utiles/ft_putstr.c\
		./parse/ft_parse.c ./parse/ft_preparse.c ./handle/ft_handle_char.c\
		./handle/ft_handle_hex_upper.c ./handle/ft_handle_hex.c\
		./handle/ft_handle_int.c ./handle/ft_handle_percent.c\
		./handle/ft_handle_pointer.c ./handle/ft_handle_specifier.c\
		./handle/ft_handle_string.c ./handle/ft_handle_unint.c

HEADER = ./includes/

INCLUDES = ./includes/ft_printf.h

OBJS = $(SRCS:.c=.o)

$(NAME): $(INCLUDES) $(OBJS)
		@ar -rcs $(NAME) $(OBJS)

all:	$(NAME)

clean:
		@rm -rf $(OBJS)

fclean: clean
		@rm -rf $(NAME)

re:		clean all

.PHONY:	all clean fcl re

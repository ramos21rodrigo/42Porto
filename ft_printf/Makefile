# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roramos <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 19:49:39 by roramos           #+#    #+#              #
#    Updated: 2022/11/18 17:44:42 by roramos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft
CC = cc
SRCS = ft_print_hexs.c ft_print_nums.c ft_print_ptrs.c ft_print_strs.c ft_printf.c
OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
	make -C ${LIBFT}
	cp libft/libft.a .
	mv libft.a ${NAME}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	make clean -C ${LIBFT}
	rm -rf *.o

fclean: clean
	make fclean -C ${LIBFT}
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re

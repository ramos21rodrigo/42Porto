# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roramos <roramos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 16:38:13 by roramos           #+#    #+#              #
#    Updated: 2022/11/27 17:29:50 by roramos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
SRC_PATH = src/
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L ./mlx -lmlx -Ilmlx -lXext -lX11
RM = rm -rf

SRCS = src/hooks.c src/map_check.c src/map_get.c\
		src/tilemap.c src/utils.c src/main.c
OBJS=${SRCS:.c=.o}

${NAME}: ${OBJS}
	${MAKE} --no-print-directory -C ./libft
	cp libft/libft.a .
	${MAKE} --no-print-directory -C ./mlx
	${CC} ${OBJS} libft.a ${MLXFLAGS} -o ${NAME}

clean:
	${MAKE} clean --no-print-directory -C ./libft
	${RM} ${OBJS}

fclean: clean
	${MAKE} fclean --no-print-directory -C ./libft
	${RM} libft.a
	${RM} ${NAME}

all: ${NAME}

re: fclean all

.PHONY: all clear fclean re

.SILENT: all clean fclean re ${NAME}
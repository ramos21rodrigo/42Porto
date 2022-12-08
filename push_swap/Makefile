# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roramos <roramos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 18:11:09 by roramos           #+#    #+#              #
#    Updated: 2022/12/06 18:21:03 by roramos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

SRCS = src/main.c src/finds.c src/operations_utils.c\
	src/operations.c src/order.c src/parse_input.c
BONUS_SRCS = bonus/src/main_bonus.c bonus/src/parse_input_bonus.c\
	bonus/src/operations_bonus.c bonus/src/operations_utils_bonus.c

BONUS_OBJS = ${BONUS_SRCS:.c=.o}
OBJS = ${SRCS:.c=.o}

LIBFT = libft
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -rf

${NAME}: ${OBJS} ${LIBFT}
	${CC} ${OBJS} ${LIBFT}.a -o ${NAME}

bonus: ${BONUS_OBJS} ${LIBFT}
	${CC} ${BONUS_OBJS} ${LIBFT}.a -o ${BONUS_NAME}

${LIBFT}:
		${MAKE} --no-print-directory -C ./libft
		cp ${LIBFT}/${LIBFT}.a .

clean:
		${MAKE} clean --no-print-directory -C ./${LIBFT}
		${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
		${MAKE} fclean --no-print-directory -C ./${LIBFT}
		${RM} ${LIBFT}.a
		${RM} ${NAME} ${BONUS_NAME}

all: ${NAME} bonus

re: fclean all

.PHONY: ${NAME} ${LIBFT} clean fclean re

.SILENT:

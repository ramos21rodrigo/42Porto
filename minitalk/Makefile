# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roramos <roramos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 12:33:09 by roramos           #+#    #+#              #
#    Updated: 2022/11/29 14:51:11 by roramos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client
SERVER_SRCS = server.c
CLIENT_SRCS = client.c
SERVER_BONUS_SRCS = server_bonus.c
CLIENT_BONUS_SRCS = client_bonus.c

LIBFT = libft
SERVER_OBJS = ${SERVER_SRCS:.c=.o}
SERVER_BONUS_OBJS = ${SERVER_BONUS_SRCS:.c=.o}
CLIENT_OBJS = ${CLIENT_SRCS:.c=.o}
CLIENT_BONUS_OBJS = ${CLIENT_BONUS_SRCS:.c=.o}
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -rf

${NAME}: ${SERVER} ${CLIENT}

${SERVER}: ${LIBFT} ${SERVER_OBJS}
	${CC} ${SERVER_OBJS} ${LIBFT}.a -o ${SERVER}

${CLIENT}: ${LIBFT} ${CLIENT_OBJS}
	${CC} ${CLIENT_OBJS} ${LIBFT}.a -o ${CLIENT}

bonus: ${LIBFT} ${SERVER_BONUS_OBJS} ${CLIENT_BONUS_OBJS}
	${CC} ${SERVER_BONUS_OBJS} ${LIBFT}.a -o ${SERVER}
	${CC} ${CLIENT_BONUS_OBJS} ${LIBFT}.a -o ${CLIENT}

${LIBFT}: 
	${MAKE} --no-print-directory -C ./libft
	cp ${LIBFT}/${LIBFT}.a .

clean:
	${MAKE} clean --no-print-directory -C ./${LIBFT}
	${RM} ${SERVER_OBJS} ${CLIENT_OBJS} ${SERVER_BONUS_OBJS} ${CLIENT_BONUS_OBJS}

fclean: clean
	${MAKE} fclean --no-print-directory -C ./${LIBFT}
	${RM} libft.a
	${RM} ${SERVER} ${CLIENT}

all: ${NAME}

re: fclean all

.PHONY: all clean fclean re ${LIBFT}

.SILENT:


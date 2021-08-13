# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teppei <teppei@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 12:46:40 by teppei            #+#    #+#              #
#    Updated: 2021/08/13 15:57:50 by teppei           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME	=	client
SERVER_NAME	=	server
NAME		=	$(CLIENT_NAME) $(SERVER_NAME)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
CLIENT_SRCS	=	mt_client.c \
				mt_ft_atoi.c \
				
CLIENT_OBJS	=	$(CLIENT_SRCS:.c=.o)
SERVER_SRCS	=	mt_server.c \
				mt_ft_itoa.c \
				mt_ft_strlen.c \
				mt_ft_bzero.c \
				mt_init_bits.c \
				
SERVER_OBJS	=	$(SERVER_SRCS:.c=.o)
OBJS		=	$(CLIENT_OBJS) $(SERVER_OBJS)
HEAD		=	minitalk.h

BONUS_NAME	= # your bonus target file

all: $(NAME)

$(SERVER_NAME): $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SERVER_OBJS)

$(CLIENT_NAME): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJS)

.c.o: $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) *.gch
	rm -rf *.dSYM
fclean: clean
	rm -f $(NAME)
	rm -f libs/*.a

re: fclean all

.PHONY: all clean fclean re

# if you challenge bonus
bonus:
	make -C bonus
	cp bonus/$(BONUS_NAME) .

bclean:
	make clean -C bonus

bfclean:
	make fclean -C bonus
	rm $(BONUS_NAME)

.PHONY: bonus bclean bfclean

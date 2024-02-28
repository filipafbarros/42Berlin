# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: filipa <filipa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 15:30:56 by fibarros          #+#    #+#              #
#    Updated: 2024/02/28 17:24:46 by filipa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# MINITALK

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libftprintf.a
RM = rm -rf

SERVER = server
CLIENT = client

SV_SRCS = server.c
SV_OBJS = $(SV_SRCS:.c=.o)

CLIENT_SRCS = client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)


all: $(SERVER) $(CLIENT)

$(LIBFT):
	$(MAKE) -C ./libft
$(SERVER): $(SV_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SV_OBJS) $(LIBFT) -o server
$(CLIENT): $(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) -o client


clean:
	$(MAKE) clean -C ./libft
	$(RM) $(SV_OBJS) $(CLIENT_OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re

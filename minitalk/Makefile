# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 15:30:56 by fibarros          #+#    #+#              #
#    Updated: 2024/04/03 16:42:56 by fibarros         ###   ########.fr        #
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
CLIENT_SRCS = client.c

all: $(SERVER) $(CLIENT)

$(LIBFT):
	$(MAKE) -C ./libft
$(SERVER): $(SV_SRCS) $(LIBFT)
	$(CC) $(CFLAGS) $(SV_SRCS) $(LIBFT) -o server
$(CLIENT): $(CLIENT_SRCS) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_SRCS) $(LIBFT) -o client

clean:
	$(MAKE) clean -C ./libft

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(SERVER) $(CLIENT)
	# $(RM) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all

.PHONY: all clean fclean re

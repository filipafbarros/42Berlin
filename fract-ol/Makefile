# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 12:11:48 by fibarros          #+#    #+#              #
#    Updated: 2024/04/09 15:22:06 by fibarros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LINK = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
LIBFT = ./libft/libftprintf.a
RM = rm -rf
SRC = 	fractol.c
				
OBJ	= $(SRC:.c=.o)

all:$(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LINK) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
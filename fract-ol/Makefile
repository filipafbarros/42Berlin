# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 12:11:48 by fibarros          #+#    #+#              #
#    Updated: 2024/04/19 12:40:00 by fibarros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LINK = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
# LIBFT = ./libft/libftprintf.a
RM = rm -rf
SRC = 	main.c \
		init.c \
		draw.c \
		colors.c \
		mandelbrot.c \
		utils.c
					
OBJ	= $(SRC:.c=.o)

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LINK) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
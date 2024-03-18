# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: filipa <filipa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 11:35:20 by fibarros          #+#    #+#              #
#    Updated: 2024/03/14 15:23:04 by filipa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#PROGRAM
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -fsanitize=leak
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
INCLUDE = -I./includes
RM = rm -rf
# LIBFT = libftprintf.a
# LIBFTDIR = ./libft


#####################################################################################
# Contains the X11 and MLX header files
INCLUDES = -I/usr/include -Imlx
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

# Link X11 and MLX


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

######################################################################################
#SRCS
SRCS =	main.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

# LIBFT

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFT) .
	@mv $(LIBFT) $(NAME)

$(NAME) : makelibft $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) ./libft/libftprintf.a


clean:
	@rm -rf $(OBJS)
	@make -C $(LIBFTDIR) clean


fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all

run: all
	./a.out | cat -e

.PHONY: all clean fclean re







# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 11:35:20 by fibarros          #+#    #+#              #
#    Updated: 2024/02/16 17:51:22 by fibarros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#PROGRAM
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -fsanitize=leak
# LIBFT = libftprintf.a
# LIBFTDIR = ./libft


#####################################################################################
# Contains the X11 and MLX header files
INCLUDES = -I/usr/include -Imlx
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

# Link X11 and MLX
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
 
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



 



# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 16:01:36 by fibarros          #+#    #+#              #
#    Updated: 2024/02/09 10:46:30 by fibarros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#PROGRAM
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libftprintf.a
LIBFTDIR = ./libft

#SRCS
SRCS =	main.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		stack_utils.c \
		swap.c \
		error_handling.c \
		initialize_stack.c \
			
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
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 16:01:36 by fibarros          #+#    #+#              #
#    Updated: 2024/01/31 14:50:25 by fibarros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#PROGRAM
NAME			= push_swap
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
PRINTF 			= libftprintf.a
PRINTFDIR 		= ./printf
FSANITIZE 		= -fsanitize=address -g3
RM		  		= rm -rf 

#SRCS
SRCS =		main.c \
			push.c \
			reverse.c \
			rotate.c \
			stack_utils.c \
			swap.c \
			error_handling.c \ 
			initialize_stack.c \
			
OBJS = $(SRCS:.c=.o)

all: $(NAME)

# PRINTF

$(NAME) : $(OBJS)
		  @make -C printf
		  @cp printf/libftprintf.a .
		  $(CC) $(CFLAGS) $(OBJ) $(PRINTF) -O $(NAME)
	
run: all
	cc -g main.c push_swap
	./a.out | cat -e

clean: 
		make clean -C printf
		${RM} ${OBJS}

fclean: 
		clean
				@make fclean -C printf
				${RM} $(NAME)
				${RM} $(PRINTF)
				${RM} printf/$(PRINTF)

re: fclean all

.PHONY: all clean fclean re
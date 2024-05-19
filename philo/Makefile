# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: filipa <filipa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/19 18:16:25 by filipa            #+#    #+#              #
#    Updated: 2024/05/19 18:23:21 by filipa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = CC
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRC =	main.c \
		init.c \
		routine.c \
		utils.c \
		arg_check.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 11:10:46 by fibarros          #+#    #+#              #
#    Updated: 2023/12/12 16:30:38 by fibarros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprint.a
LIBFTNAME = libft.a
LIBFTDIR = ./libft
CC = cc
SRCS = ft_printf.c \
		ft_print_hex.c \
		ft_print_nbr.c \
		ft_print_str.c \
		ft_print_u.c \
		ft_print_ptr.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJS)
	@ar -r $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
	@cd $(LIBFTDIR) && make clean
	
fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean
	
re: fclean all

run: all
	cc -g main.c libftprint.a
	./a.out | cat -e
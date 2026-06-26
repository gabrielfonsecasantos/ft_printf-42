# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/25 15:06:21 by gviniciu          #+#    #+#              #
#    Updated: 2026/06/26 10:49:49 by gabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

CC := cc

CFLAGS := -Wall -Wextra -Werror

SRCS := ft_printf.c ft_helper_functions.c ft_utils.c

# Object files
OBJS = $(SRCS:.c=.o)
 
# Main Rule
all: $(NAME)

# Creating Library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compiling .c files to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean .o files
.PHONY: all clean fclean re

clean:
	rm -f $(OBJS) *.gch

fclean: clean
	rm -f $(NAME)

re: fclean all
 

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 10:24:04 by ahamdy            #+#    #+#              #
#    Updated: 2021/12/21 13:48:39 by ahamdy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRCS =	functions.c libft.c libft2.c push_functions.c split.c sort_functions.c libft3.c array_stack.c
BONUS_SRCS =  checker_utils.c checker_functions.c get_next_line.c get_next_line_utils.c libft.c libft2.c libft3.c split.c check_utils2.c
NAME = push_swap.a
NAME_CHECKER = checker.a
AR = ar rs

OBJS = $(SRCS:.c=.o)
OBJS_CHECKER = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(CC) $(CFLAGS) main.c $(NAME) -o push_swap

bonus: $(NAME_CHECKER)

$(NAME_CHECKER): $(OBJS_CHECKER)
	$(AR) $(NAME_CHECKER) $(OBJS_CHECKER)
	$(CC) $(CFLAGS) checker.c $(NAME_CHECKER) -o checker

clean:
	rm -f $(OBJS) $(OBJS_CHECKER)

fclean: clean
	rm -f $(NAME) $(NAME_CHECKER)

re: fclean all

.PHONY: all bonus clean fclean re
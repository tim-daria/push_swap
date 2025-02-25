# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtimofee <dtimofee@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 12:41:15 by dtimofee          #+#    #+#              #
#    Updated: 2025/02/17 15:51:37 by dtimofee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc

CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap
SRCS = operations.c push_swap.c calculations.c directions.c rotations.c utils1.c utils2.c
OBJS = $(SRCS:.c=.o)

LIBFT_FOLDER = ./Libft
LIBFT_ARCHIVE = libft.a
LIBFT_LIB = ft
LIBFT = $(LIBFT_FOLDER)/$(LIBFT_ARCHIVE)

all: $(NAME)

$(LIBFT):
	make bonus -C $(LIBFT_FOLDER)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -g $(OBJS) -o $(NAME) -L$(LIBFT_FOLDER) -l$(LIBFT_LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make fclean -C $(LIBFT_FOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

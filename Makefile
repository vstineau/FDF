# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 10:33:24 by vstineau          #+#    #+#              #
#    Updated: 2024/03/05 13:24:18 by vstineau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fdf
CC				= cc
CFLAGS		= -Wall -Wextra -Werror  -g3 -O2 -fno-builtin
SRCS			= main.c \
						parsing.c

OBJS			= $(SRCS:.c=.o)
INCLUDES	= -I. -ILIBFT -IMINILIBX
LIBFT 		= LIBFT/libft.a
MINILIBX	= minilibx-linux/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) -o $(NAME) -lm -lX11 -lXext $(OBJS) $(LIBFT) $(MINILIBX)

$(LIBFT):
	$(MAKE) -C LIBFT

$(MINILIBX):
	$(MAKE) -C minilibx-linux

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	$(MAKE) -C LIBFT clean
	$(MAKE) -C minilibx-linux clean
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) -C LIBFT fclean
	$(MAKE) -C minilibx-linux clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

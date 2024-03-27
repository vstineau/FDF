# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 10:33:24 by vstineau          #+#    #+#              #
#    Updated: 2024/03/27 16:36:07 by vstineau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fdf
CC				= cc
CFLAGS		= -Wall -Wextra -MMD -g3 -O2 -fno-builtin -Werror
SRCS			= main.c \
						parsing.c \
						parsing2.c \
						\
						free.c \
						free_exit.c \
						\
						window.c \
						windows_action.c \
						windows_action2.c \
						windows_action3.c \
						image.c \
						color.c \
						segment.c \
						\
						matrice_projection.c \
						matrices_rotations.c

OBJECTS			= $(SRCS:.c=.o)
INCLUDES	= -I. -ILIBFT -IMINILIBX
LIBFT 		= LIBFT/libft.a
MINILIBX	= minilibx-linux/libmlx.a

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT) $(MINILIBX) -lm -lX11 -lXext

propre: all clean

$(LIBFT):
	$(MAKE) -C LIBFT

$(MINILIBX):
	$(MAKE) -C minilibx-linux

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

-include $(OBJECTS:.o=.d)

clean:
	$(MAKE) -C LIBFT clean
	$(MAKE) -C minilibx-linux clean
	rm -rf $(OBJECTS) $(OBJECTS:.o=.d)

fclean: clean
	$(MAKE) -C LIBFT fclean
	$(MAKE) -C minilibx-linux clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

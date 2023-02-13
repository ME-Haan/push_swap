# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mhaan <mhaan@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/30 16:06:53 by mhaan         #+#    #+#                  #
#    Updated: 2023/02/13 17:14:14 by mhaan         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -crs
RM = /bin/rm -rf
INCLUDES = -I ./includes -I ./libft

SRC_DIR = ./src
SRC = ps_atoi.c ps_errors.c ps_parsing.c ps_stack.c push_swap.c

OBJ_DIR = ./obj
OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# LIBS:
LIBFT_DIR = ./libft
LIBFTAR = $(LIBFT_DIR)/libft.a

# RULES:
all: $(NAME)

$(NAME): $(LIBFTAR) $(OBJ_DIR) $(OBJS)
		$(CC) $(CFLAGS) $(INCLUDES) $(LIBFTAR) $(OBJS) -o $(NAME)

$(LIBFTAR):
		$(MAKE) -C libft

$(OBJ_DIR):
		mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $^

clean:
		$(RM) $(OBJ_DIR)
		$(MAKE) clean -C libft

fclean: clean
		$(RM) $(NAME)
		$(RM) $(LIBFTAR)

re:
		$(MAKE) fclean
		$(MAKE) all

# OTHER:
.PHONY:
		all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mhaan <mhaan@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/30 16:06:53 by mhaan         #+#    #+#                  #
#    Updated: 2023/02/24 15:31:16 by mhaan         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#GENERAL VARIABLES
NAME=push_swap
RM=/bin/rm -rf

#COMPILATION VARIABLES
CC=gcc
CFLAGS=-Wall -Wextra -Werror
AR=ar -crs

#DIRS AND FILES
INC_DIR=./includes ./libft
INCLUDES=$(foreach D,$(INC_DIR),-I$(D))

SRC_DIR=./src
SRC=ps_errors.c ps_operations.c ps_parsing.c ps_sorting.c ps_stack.c push_swap.c test_utils.c

OBJ_DIR=./obj
OBJS=$(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))

#DEPENDENCY LIBS:
LIBFT_DIR=./libft
LIBFT_AR=$(LIBFT_DIR)/libft.a

#RECIPES:
all: $(NAME)

clean:
		$(RM) $(OBJ_DIR)
		$(MAKE) clean -C libft

fclean: clean
		$(RM) $(NAME)
		$(RM) $(LIBFT_AR)

re:
		$(MAKE) fclean
		$(MAKE) all

#RULES:
$(NAME): $(LIBFT_AR) $(OBJ_DIR) $(OBJS)
		$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT_AR) $(OBJS) -o $(NAME)

$(LIBFT_AR):
		$(MAKE) -C libft

$(OBJ_DIR):
		mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@


#OTHER:
.PHONY:
		all clean fclean re
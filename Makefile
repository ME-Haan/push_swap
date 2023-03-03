# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mhaan <mhaan@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/30 16:06:53 by mhaan         #+#    #+#                  #
#    Updated: 2023/03/03 17:42:14 by mhaan         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#GENERAL VARIABLES
NAME := push_swap
RM := /bin/rm -rf

#COMPILATION VARIABLES
CFLAGS ?= -Wall -Wextra -Werror
AR := ar -crs

#DIRS AND FILES
INC_DIRS := ./includes ./libft
INCLUDES := $(foreach D,$(INC_DIRS),-I$(D))
INC_FILES := ./includes/push_swap.h ./libft/libft.h

SRC_DIR := ./src
SRC := ps_errors.c ps_operations.c ps_parsing.c ps_sorting.c ps_stack.c push_swap.c

OBJ_DIR := ./obj
OBJS := $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))

#DEPENDENCIES:
LIBFT_DIR := ./libft
LIBFT_AR := $(LIBFT_DIR)/libft.a

#RECIPES:
all:	$(NAME)

fclean: clean
		$(RM) $(NAME)
		$(RM) $(LIBFT_AR)

clean:
		$(RM) $(OBJ_DIR)
		@$(MAKE) clean -C libft

re:
		@$(MAKE) fclean
		@$(MAKE) all

#RULES:
$(NAME): $(OBJS) $(LIBFT_AR)
		$(CC) $(CFLAGS) -o $@ $^

$(LIBFT_AR):
		@$(MAKE) -C libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
		@mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<


#OTHER:
.PHONY:
		all clean fclean re
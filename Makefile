# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mhaan <mhaan@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/30 16:06:53 by mhaan         #+#    #+#                  #
#    Updated: 2023/03/15 18:49:43 by mhaan         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#GENERAL VARIABLES
NAME := push_swap
BONUS := checker_bonus
RM := /bin/rm -rf

#COMPILATION VARIABLES
CFLAGS ?= -Wall -Wextra -Werror
AR := ar -crs

#DIRS AND FILES
INC_DIRS := includes libft_ext/includes
INCLUDES := $(foreach D,$(INC_DIRS),-I $(D))
INC_FILES := ./includes/push_swap.h ./includes/checker_bonus.h

SRC_DIR :=		./src
SRC :=			ps_errors.c \
				ps_operations.c \
				ps_parsing.c \
				ps_radix.c \
				ps_stack.c \
				push_swap.c \
				ps_shortsort.c

OBJ_DIR		:=	./obj
OBJS		:=	$(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))

BONUS_DIR	:=	$(SRC_DIR)/checker_bonus
SRC_BONUS	:=	checker_bonus.c
BONUS_OBJS	:=	$(addprefix $(OBJ_DIR)/,$(notdir $(SRC_BONUS:.c=.o)))

#DEPENDENCIES:
LIBFT_DIR := ./libft_ext
LIBFT_AR := $(LIBFT_DIR)/libft_ext.a

#RECIPES:
all:	$(NAME)

clean:
		@$(RM) $(OBJ_DIR)
		@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
		@$(RM) $(NAME)
		@$(RM) $(BONUS)
		@$(RM) $(LIBFT_AR)

re:
		@$(MAKE) fclean
		@$(MAKE) all

bonus:	$(BONUS)

#RULES:
$(NAME): $(OBJS) $(LIBFT_AR)
		$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT_AR)

$(BONUS): $(LIBFT_AR) $(BONUS_OBJS)
		$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

$(LIBFT_AR):
		@$(MAKE) -C $(LIBFT_DIR) -j

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
		@mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c $(INC_FILES)
		@mkdir -p $(OBJ_DIR)
		gcc $(CFLAGS) $(INCLUDES) -c -o $@ $<

#OTHER:
.PHONY:
		all clean fclean re bonus
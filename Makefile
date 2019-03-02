# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pclement <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/02 17:17:15 by pclement          #+#    #+#              #
#    Updated: 2019/03/02 18:20:31 by tdelabro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = alum1

#compiler
CC = gcc
CFLAGS = -Werror -Wall -Wextra

#flags for preprocessor
CPPFLAGS = -Iincludes/ -Ilibft/inc
LFLAGS = -Llibft -lft

#deps
DEPENDENCIES = includes/alum1.h Makefile

#libs
LIB_PATH = libft/
LIB_NAME = libft.a
LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))

#srcs
SRC_PATH =srcs/
SRC_NAME = alum1.c algo.c ft_get_board.c ft_print_board.c \
		   utils.c ft_parsing.c
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

#obj
OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

# Colours
CYAN = \x1b[36m
GREEN = \x1b[32m
YELLOW = \x1b[33m
END_COLOUR = \x1b[0m

#disable implicit rules
.SUFFIXES:
.PHONY: clean fclean all re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LFLAGS) $(OBJ) -o $@
	@echo "$(GREEN) Binary compilation succesfull$(END_COLOUR)"

$(OBJ_PATH)%.o: $(SRC_PATH)/%.c $(DEPENDENCIES) $(LIB)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(LIB):
	@echo "$(CYAN) Compiling library $(END_COLOUR)"
	@$(MAKE) -C libft/

clean:
	@echo "$(YELLOW) Removing objects $(END_COLOUR)"
	@$(MAKE) -C libft/ clean
	@$(RM) $(OBJ)
	@$(RM) $(DBG_OBJ)
	@$(RM) -R $(OBJ_PATH) 2> /dev/null || true
	@$(RM) -R $(DBG_PATH) 2> /dev/null || true

fclean: clean
	@echo "$(YELLOW) Removing binary $(END_COLOUR)"
	@$(MAKE) -C libft/ fclean
	@$(RM) $(NAME)
	@$(RM) $(DBG_NAME)

re:
	@echo "Recompiling"
	@$(MAKE) fclean
	@$(MAKE) all

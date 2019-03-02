# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/02 14:39:37 by tdelabro          #+#    #+#              #
#    Updated: 2019/03/02 21:23:08 by tdelabro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
MODULES := libft/ gnl/
SRC_DIR := $(addprefix src/,$(MODULES))
OBJ_DIR := obj/
INC_DIR := inc/

SRC := ft_atoi.c			ft_memmove.c				ft_strequ.c\
	ft_atoll.c			ft_memset.c					ft_striter.c\
	ft_bzero.c			ft_print_words_tables.c		ft_striteri.c\
	ft_convert_base.c	ft_strjoin.c\
	get_next_line.c			ft_putchar.c				ft_strlcat.c\
	ft_isalnum.c		ft_putchar_fd.c				ft_strlen.c\
	ft_isalpha.c		ft_putendl.c				ft_strmap.c\
	ft_isascii.c		ft_putendl_fd.c				ft_strmapi.c\
	ft_isdigit.c		ft_putlst.c					ft_strncat.c\
	ft_isprint.c		ft_putnbr.c					ft_strncmp.c\
	ft_itoa.c			ft_putnbr_fd.c				ft_strncpy.c\
	ft_lstadd.c			ft_putnbrendl.c				ft_strndup.c\
	ft_lstclear.c		ft_putnstr.c				ft_strnequ.c\
	ft_lstclearifdata.c	ft_putstr.c					ft_strnew.c\
	ft_lstdel.c			ft_putstr_fd.c				ft_strnstr.c\
	ft_lstdelcontent.c	ft_pwd.c					ft_strrchr.c\
	ft_lstdelone.c		ft_pwd_uint64.c				ft_strremend.c\
	ft_lstiter.c		ft_sqrt.c					ft_strrev.c\
	ft_lstlen.c			ft_strcat.c					ft_strsplit.c\
	ft_lstmap.c			ft_strcdup.c				ft_strsplit_lst.c\
	ft_lstnew.c			ft_strchr.c					ft_strstr.c\
	ft_memalloc.c		ft_strclen.c				ft_strsub.c\
	ft_memccpy.c		ft_strclr.c					ft_strtrim.c\
	ft_memchr.c			ft_strcmp.c					ft_strwordcount.c\
	ft_memcmp.c			ft_strcpy.c					ft_tolower.c\
	ft_memcpy.c			ft_strdel.c					ft_toupper.c\
	ft_memdel.c			ft_strdup.c					ft_lenint_base.c\
	
INC := libft.h get_next_line.h

OBJECTS := $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))
INCLUDES := $(addprefix $(INC_DIR), $(INC))

vpath %.c $(SRC_DIR)

all : $(NAME)

clean :
	@rm -rf $(OBJ_DIR)
	@echo "object deleted ✔"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(NAME) deleted ✔"

re : fclean all

obj/%.o : %.c 
	@$(CC) $(CFLAGS) -I$(INC_DIR) $< -o $@

$(NAME) : $(OBJ_DIR) $(OBJECTS) 
	@ar rc $@ $(OBJECTS)
	@ranlib $@

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

.PHONY : all clean fclean re

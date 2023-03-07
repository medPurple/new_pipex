# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 09:59:07 by purple            #+#    #+#              #
#    Updated: 2023/03/06 17:57:06 by wmessmer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus

cc = cc

CFLAGS = -Wall -Werror -Wextra -g3

PATH_SRC = srcs/mandatory
PATH_SRC_BONUS = srcs/bonus
PATH_SRC_GEN = srcs/general

PATH_LIB = libft

SRC =	$(PATH_SRC)/utils.c \
		srcs/pipex.c 

SRC_GEN =	$(PATH_SRC_GEN)/commands.c 


SRC_BONUS = $(PATH_SRC_BONUS)/here_doc.c \
	  $(PATH_SRC_BONUS)/pipes_bonus.c \
	  $(PATH_SRC_BONUS)/bonus_norme.c \
	  srcs/pipex_bonus.c

LIB = $(PATH_LIB)/libft.a

OBJ = $(SRC:.c=.o)

OBJ_GEN = $(SRC_GEN:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(LIB) $(NAME)

bonus : $(LIB) $(NAME_BONUS)

$(NAME) : $(OBJ) $(OBJ_GEN)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(OBJ_GEN) $(LIB)
	@echo "\n Compilation OK\n"

$(NAME_BONUS) : $(OBJ_BONUS) $(OBJ_GEN)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(OBJ_GEN) $(LIB)
	@echo "\n Compilation Bonus OK\n"

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB) :
	@make -s -C $(PATH_LIB)

clean :
	make -C $(PATH_LIB) clean
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	rm -f $(OBJ_GEN)

fclean : clean
	make -C $(PATH_LIB) fclean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re

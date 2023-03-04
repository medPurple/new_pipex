# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 13:16:04 by wmessmer          #+#    #+#              #
#    Updated: 2023/01/24 16:59:20 by wmessmer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
HEADER = libft.h \
CC 	= cc
FLAGS	= -Wall -Werror -Wextra -g3
OBJ_DIR = objs/

GREEN	= \033[1;32
DEFAULT = \033[0m

SRCS_LIBFT =	srcs/src_libftbase/src_part1/ft_isalpha.c	\
				srcs/src_libftbase/src_part1/ft_isdigit.c	\
				srcs/src_libftbase/src_part1/ft_isalnum.c	\
				srcs/src_libftbase/src_part1/ft_isascii.c	\
				srcs/src_libftbase/src_part1/ft_isprint.c	\
				srcs/src_libftbase/src_part1/ft_strlen.c	\
				srcs/src_libftbase/src_part1/ft_memset.c	\
				srcs/src_libftbase/src_part1/ft_bzero.c		\
				srcs/src_libftbase/src_part1/ft_memcpy.c	\
				srcs/src_libftbase/src_part1/ft_memmove.c	\
				srcs/src_libftbase/src_part1/ft_strlcpy.c	\
				srcs/src_libftbase/src_part1/ft_strlcat.c	\
				srcs/src_libftbase/src_part1/ft_toupper.c	\
				srcs/src_libftbase/src_part1/ft_tolower.c	\
				srcs/src_libftbase/src_part1/ft_strchr.c	\
				srcs/src_libftbase/src_part1/ft_strrchr.c	\
				srcs/src_libftbase/src_part1/ft_strncmp.c	\
				srcs/src_libftbase/src_part1/ft_memchr.c	\
				srcs/src_libftbase/src_part1/ft_memcmp.c	\
				srcs/src_libftbase/src_part1/ft_strnstr.c	\
				srcs/src_libftbase/src_part1/ft_calloc.c	\
				srcs/src_libftbase/src_part1/ft_strdup.c	\
				srcs/src_libftbase/src_part1/ft_atoi.c 		\
				srcs/src_libftbase/src_part2/ft_substr.c 	\
				srcs/src_libftbase/src_part2/ft_strjoin.c 	\
				srcs/src_libftbase/src_part2/ft_strtrim.c 	\
				srcs/src_libftbase/src_part2/ft_split.c 	\
				srcs/src_libftbase/src_part2/ft_itoa.c 		\
				srcs/src_libftbase/src_part2/ft_striteri.c 	\
				srcs/src_libftbase/src_part2/ft_putchar_fd.c 	\
				srcs/src_libftbase/src_part2/ft_putstr_fd.c  	\
				srcs/src_libftbase/src_part2/ft_putendl_fd.c  	\
				srcs/src_libftbase/src_part2/ft_putnbr_fd.c 	\
				srcs/src_libftbase/src_part2/ft_strmapi.c 	\
				srcs/src_libftbase/src_bonus/ft_lstnew.c 	\
				srcs/src_libftbase/src_bonus/ft_lstadd_front.c \
				srcs/src_libftbase/src_bonus/ft_lstsize.c 	\
				srcs/src_libftbase/src_bonus/ft_lstlast.c 	\
				srcs/src_libftbase/src_bonus/ft_lstadd_back.c 	\
				srcs/src_libftbase/src_bonus/ft_lstdelone.c    \
				srcs/src_libftbase/src_bonus/ft_lstclear.c 	\
				srcs/src_libftbase/src_bonus/ft_lstiter.c 	\
				srcs/src_libftbase/src_bonus/ft_lstmap.c 	\
		
SRCS_PRINTF  =	srcs/src_printf/ft_hexa.c 			\
				srcs/src_printf/ft_hexavoid.c 			\
				srcs/src_printf/ft_nbr.c 			\
				srcs/src_printf/ft_printf.c 			\
		
SRCS_GNL  =		srcs/src_gnl/get_next_line_bonus.c 		\

SRCS_PERSO	= 	srcs/src_add/print_error.c \
				srcs/src_add/ft_strcmp.c \

OBJ	=   ${SRCS_LIBFT:.c=.o} ${SRCS_PRINTF:.c=.o} ${SRCS_GNL:.c=.o} ${SRCS_PERSO:.c=.o} 

all:	${NAME}

$(NAME) : ${OBJ}
		@ ar rc ${NAME} ${OBJ} 
		@echo "\nCompilation libft [OK]"
	
clean :
	@ rm -rf $(OBJ)

fclean : clean
	@ rm -rf $(NAME)
re : fclean all

.c.o	:
		@ $(CC) $(CFLAGS) -o $@ -c $<
			
.PHONY:	
	all re clean fclean
	

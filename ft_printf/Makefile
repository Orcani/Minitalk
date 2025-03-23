# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: desambou <desambou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 14:57:50 by desambou          #+#    #+#              #
#    Updated: 2025/02/10 13:59:28 by desambou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	ft_printf.c print_part1.c print_hex.c print_nbr.c print_p.c print_str.c print_u.c

OBJ = ${SRC:.c=.o}
NAME = libftprintf.a
AR = ar -rcs
RM = rm -f

all: ${NAME}

${NAME}: ${OBJ}
	${AR} ${NAME} ${OBJ}
	
%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@
clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
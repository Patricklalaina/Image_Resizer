# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fidrandr <fidrandr@student.42antananarivo  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 21:51:36 by fidrandr          #+#    #+#              #
#    Updated: 2024/11/15 11:42:52 by fidrandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

SRC	=	get_next_line.c get_next_line_utils.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Werror -Wextra

all :	$(NAME)
	
.c.o:
	cc $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean	:
	rm -f $(OBJ)
	
fclean	:		clean
	rm -f $(NAME)

re	:	fclean all

.PHONY	: all re fclean clean
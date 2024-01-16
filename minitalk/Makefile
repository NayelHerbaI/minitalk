# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naherbal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 20:28:19 by naherbal          #+#    #+#              #
#    Updated: 2023/10/10 14:29:02 by naherbal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	server.c		\
		client.c		\
		functions.c		\
		sec_functions.c	\

OBJ		=	$(SRC:.c=.o)

SERVER	=	server

CLIENT	=	client

UTILS	=	functions.c		\
			sec_functions.c	\

CFLAGS	=	-Wall -Wextra -Werror

HEADERS	=	-I include

RM		=	rm -rf

all:
	cc $(FLAGS) server.c -o $(SERVER)
	cc $(FLAGS) client.c $(UTILS) -o $(CLIENT)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(CLIENT) $(SERVER)

re:		fclean all

.PHONY:	all clean fclean re

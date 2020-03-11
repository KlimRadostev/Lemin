#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kradoste <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 16:36:25 by kradoste          #+#    #+#              #
#    Updated: 2019/10/07 16:36:33 by kradoste         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = *.c
OBJ = $(SRC:.c=.o)
LIB_LNK = -L ./libft -lft

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(LIB_LNK) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f *~

fclean: clean
	@/bin/rm -f $(NAME)

re:	fclean all
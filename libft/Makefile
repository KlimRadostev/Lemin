#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kradoste <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/16 14:54:41 by kradoste          #+#    #+#              #
#    Updated: 2019/10/08 16:09:46 by kradoste         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
CFLAG = -Wall -Werror -Wextra

FILES = *.c
OBJ = *.o
BUP = *~

OBJDIR = objects

all : $(NAME)

$(NAME) :
		@mkdir $(OBJDIR)
		@gcc $(CFLAG) -c $(wildcard $(FILES))
		@ar rc $(NAME) $(OBJ)

$(OBJDIR)/%.o: %/c
		$(CC) $(CFLAG) -c -o $@ $<

.PHONY : clean fclean re

clean :
		@/bin/rm -rf $(OBJDIR)
		@/bin/rm -f $(OBJ)
		@/bin/rm -f $(BUP)

fclean : clean
		@/bin/rm -f $(NAME)

re : fclean all

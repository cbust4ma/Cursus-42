# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbustama <cbustama@student.42urduliz.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 16:44:11 by cbustama          #+#    #+#              #
#    Updated: 2022/09/14 16:47:15 by cbustama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)
#wpedantic -pedantic.errors
#Emita todas las advertencias exigidas por las estrictas normas ISO C e ISO C++; rechace todos los programas que utilicen extensiones prohibidas y algunos otros programas que no sigan las normas ISO C e ISO C++.

CC = clang++ -MD -O2 -Wpedantic -pedantic-errors -std=c++98 -g3 

FLAGS = -Wunused-value -Wall -Wextra -Werror -fsanitize=address

.cpp.o:$(SRC)
	@$(CC) $(FLAGS) -c -o $@ $<

$(NAME):$(OBJ)

	@$(CC) $(FLAGS) -c $(SRC)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ)

all:$(NAME)

clean:

	@/bin/rm -f $(OBJ)
	@/bin/rm -f *.d

fclean:clean
	@/bin/rm -rf $(NAME)
	
re:fclean all

.PHONY: all clean fclean re

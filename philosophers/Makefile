# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 19:30:17 by cbustama          #+#    #+#              #
#    Updated: 2022/05/27 19:03:51 by cbustama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philo.c\
	  utils.c\
	  operations.c\
	  routine.c\

OBJ = *.o

CC = gcc -MD -pthread -std=c11 -ggdb3 

FLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

all: $(NAME)
$(NAME):

	@$(CC) $(FLAGS) -c $(SRC)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

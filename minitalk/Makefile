# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 15:28:41 by cbustama          #+#    #+#              #
#    Updated: 2022/03/08 11:52:58 by cbustama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = client
NAME2 = server
NAME_BONUS1 = client_bonus
NAME_BONUS2 = server_bonus

SRC1 = client.c\
	   utils.c
SRC2 = server.c\
	   utils.c
SRC1_BONUS = client_bonus.c
SRC2_BONUS = server_bonus.c

OBJ = client.o\
	  utils.o
OBJ_SERV = server.o\
		   utils.o

OBJ_BONUS = client_bonus.o\
			utils.o
OBJ_SERVER = server_bonus.o\
			 utils.o

WHT = \033[1;37m
EOC = \033[1;0m

CC = gcc

FLAGS = -Wall -Wextra -Werror
INCL = minitalk.h
all: $(NAME1)

$(NAME1):
			@echo "$(WHT)Compiling the best minitalk...$(EOC)"
			@$(CC) $(FLAGS) -c $(SRC1) -I$(INCL)
			@$(CC) $(FLAGS) -o $(NAME1) $(OBJ) $(LIB)
			@$(CC) $(FLAGS) -c $(SRC2) -I$(INCL)
			@$(CC) $(FLAGS) -o $(NAME2) $(OBJ_SERV) $(LIB)
			@echo "$(WHT)BUILD COMPLETED...$(EOC)"

bonus: $(NAME_BONUS1)

$(NAME_BONUS1):

			@echo "$(WHT)Compiling the best minitalk bonus...$(EOC)"
			@$(CC) $(FLAGS) -c $(SRC1_BONUS) -I$(INCL)
			@$(CC) $(FLAGS) -o $(NAME_BONUS1) $(OBJ_BONUS) $(LIB)
			@$(CC) $(FLAGS) -c $(SRC2_BONUS) -I$(INCL)
			@$(CC) $(FLAGS) -o $(NAME_BONUS2) $(OBJ_SERVER) $(LIB)
			@echo "$(WHT)BUILD COMPLETED...$(EOC)"


clean:
		@echo "$(WHT)Removing o files...$(EOC)"
		@/bin/rm -Rf $(OBJ)
		@/bin/rm -Rf $(OBJ_BONUS)
		@/bin/rm -Rf $(OBJ_SERVER)
		@/bin/rm -Rf $(OBJ_SERV)
		@echo "$(WHT)Clean...$(EOC)"

fclean: clean
		@echo "$(WHT)Removing ALL...$(EOC)"
		@/bin/rm -Rf $(NAME1) $(NAME2)
		@/bin/rm -Rf $(NAME_BONUS1) $(NAME_BONUS2)
		@echo "$(WHT)Clean...$(EOC)"

re: fclean all

.PHONY: all clean fclean re	

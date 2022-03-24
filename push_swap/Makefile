# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 13:28:27 by cbustama          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2022/02/15 14:18:50 by cbustama         ###   ########.fr        #
=======
#    Updated: 2022/02/15 14:52:52 by cbustama         ###   ########.fr        #
>>>>>>> 797f34884869f89b8a2ff500097b978050e105aa
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap

SRC1 = index.c\
	   isnumber.c\
	   magic.c\
	   movements.c\
	   mysort.c\
	   push_swap.c\
	   push_swap.h\
	   put.c\
	   qsort.c\
	   rever.c\
	   stack.c\
	   utils.c\
	   check.c\
	   atoi.c
OBJ = *.o

GREEN = \033[1;32m
RED = \033[1;31m
YEL = \033[1;33m
WHT = \033[1;37m
EOC = \033[1;0m

HEADERS1 = includes/push_swap.h

<<<<<<< HEAD
LIBFT = ../libft/libft.a
CC = gcc

FLAGS = -Wall -Wextra -Werror
=======
LIBFT = libft/libft.a
CC = gcc

FLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
>>>>>>> 797f34884869f89b8a2ff500097b978050e105aa

all: $(NAME1)

$(NAME1):
	@echo "$(WHT)Compiling libraries...$(EOC)"
<<<<<<< HEAD
	@${MAKE} -C ../libft
=======
	@${MAKE} -C libft
>>>>>>> 797f34884869f89b8a2ff500097b978050e105aa
	@echo "$(GREEN)Libraries done.$(EOC)"

	@echo "$(WHT)Compiling push_swap...$(EOC)"
	@$(CC) $(FLAGS) -c $(SRC1) -I$(HEADERS1)
	@$(CC) $(FLAGS) -o $(NAME1) $(OBJ) $(LIBFT) $(LIB)
	@mkdir obj
	@mv $(OBJ) ./obj
	@echo "$(GREEN)push_swap build completed.$(EOC)"
	
clean:
	@echo "$(WHT)Removing o-files...$(EOC)"
	@/bin/rm -f $(OBJ)
	@/bin/rm -Rf obj
<<<<<<< HEAD
	@${MAKE} -C ../libft clean
=======
	@${MAKE} -C libft clean
>>>>>>> 797f34884869f89b8a2ff500097b978050e105aa
	@echo "$(GREEN)Clean done.$(EOC)"

fclean: clean
	@echo "$(WHT)Removing object- and binary -files...$(EOC)"
	@/bin/rm -f $(NAME1) $(NAME2)
<<<<<<< HEAD
	@${MAKE} -C ../libft fclean
=======
	@${MAKE} -C libft fclean
>>>>>>> 797f34884869f89b8a2ff500097b978050e105aa
	@echo "$(GREEN)fclean done.$(EOC)"

re: fclean all

.PHONY: all clean fclean re

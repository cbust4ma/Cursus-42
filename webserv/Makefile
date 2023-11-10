NAME = webserv

SRC = HttpResponse.cpp\
	Queue.cpp\
	main.cpp\
	Sock.cpp\
	Location.cpp\
	Config.cpp\
	Server.cpp\
	UtilityFunctions.cpp\
	UserDataManager.cpp\
	User.cpp\
	configHeader.cpp\
	configUtils.cpp\
	configResponse.cpp\
	configMethods.cpp\
	configCgi.cpp\



OBJ = $(addprefix obj/, $(SRC:.cpp=.o))#$(SRC:.cpp=.o)
#wpedantic -pedantic.errors
#Emita todas las advertencias exigidas por las estrictas normas ISO C e ISO C++; rechace todos los programas que utilicen extensiones prohibidas y algunos otros programas que no sigan las normas ISO C e ISO C++.
OBJDIRS := $(sort $(dir $(OBJ)))

override HEADERS := HttpResponse.hpp\
					Queue.hpp\
					Server.hpp\
					Sock.hpp\
					Location.hpp\
					Config.hpp\
					UtilityFunctions.hpp\
					UserDataManager.hpp\
					User.hpp\
									



override HEADERS := $(addprefix includes/,$(HEADERS))

CPPC = c++ -MD -O2 -Wpedantic -pedantic-errors -g3

CXXFLAGS = -std=c++98

CPPFLAGS = -Wall -Wextra -Werror -fsanitize=address -static-libsan -fno-omit-frame-pointer

GREEN = \033[1;32m
WHT = \033[1;37m
EOC = \033[1;0m
CYAN = \033[0;36m


#all: $(NAME)
all: $(NAME)
	@echo " [🔥 DONE 🔥] $< ";

#	#@echo "$(GREEN)[ALL Done]$(EOC)"
#$(NAME): $(OBJ)
#	#@$(CPPC) $(CPPFLAGS) -o $@ $(OBJ)

obj/%.o: src/%.cpp $(HEADERS) | 
	@echo "[⚙️   Compiling...⚙️ ] $<";
	@$(CPPC) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@ -Iincludes 

$(OBJ):  | $(OBJDIRS)

$(OBJDIRS):
	@mkdir -p $@
#.cpp.o:$(SRC)
#	@$(CPPC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CPPC) $(CXXFLAGS) $(CPPFLAGS) -o $@ $(OBJ)
	@echo "$@";
	@echo "$(WHT)[⚙️  ⚙️  COMPILING $@...⚙️  ⚙️ ]$(EOC)"

#	@$(ECHO) Compiling $@

#	@$(CPCC) $(FLAGS) -c $(SRC)
#	@$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	@/bin/rm -rf obj
	@/bin/rm -f cookie.txt
	@/bin/rm -f *.d
	@echo "[Delete...]";
	@echo "$(WHT)[CLean Done]$(EOC)"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo " [Delete...] ";
	@echo "$(WHT)[FcLean Done]$(EOC)"
	
re: fclean all

.PHONY: all clean fclean re
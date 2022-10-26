NAME = Replace

SRC = main.cpp\



OBJ = $(addprefix obj/, $(SRC:.cpp=.o))#$(SRC:.cpp=.o)
#wpedantic -pedantic.errors
#Emita todas las advertencias exigidas por las estrictas normas ISO C e ISO C++; rechace todos los programas que utilicen extensiones prohibidas y algunos otros programas que no sigan las normas ISO C e ISO C++.
OBJDIRS := $(sort $(dir $(OBJ)))

override HEADERS := #HumanA.hpp\
					HumanB.hpp\
					Weapon.hpp\

override HEADERS := #$(addprefix includes/,$(HEADERS))

CPPC = clang++ -MD -O2 -Wpedantic -pedantic-errors -g3

CXXFLAGS = -std=c++98

CPPFLAGS = -Wall -Wextra -Werror -fsanitize=address -static-libsan -fno-omit-frame-pointer

GREEN = \033[1;32m
WHT = \033[1;37m
EOC = \033[1;0m
CYAN = \033[0;36m

ifndef cbustama
H := $(shell ${MAKE} ${MAKECMDGOALS} \
	-nrRf $(firstword $(MAKEFILE_LIST)) \
      cbustama="COUNTTHIS" | grep -c "COUNTTHIS")
N := x
T = $(words $N)$(eval N := x $N)
cbustama = echo -ne "\r [`expr $T '*' 100 / $H`%]" 

endif

#all: $(NAME)
all: $(NAME)
	@$(cbustama) [🔥 DONE 🔥] $<;

#	#@echo "$(GREEN)[ALL Done]$(EOC)"
#$(NAME): $(OBJ)
#	#@$(CPPC) $(CPPFLAGS) -o $@ $(OBJ)

obj/%.o: src/%.cpp $(HEADERS) | 
	@$(cbustama) [⚙️   Compiling...⚙️ ] $<;
	@$(CPPC) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@ -Iincludes 

$(OBJ):  | $(OBJDIRS)

$(OBJDIRS):
	@mkdir -p $@
#.cpp.o:$(SRC)
#	@$(CPPC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CPPC) $(CXXFLAGS) $(CPPFLAGS) -o $@ $(OBJ)
	@$(cbustama) $@;
	@echo "$(WHT)[⚙️  ⚙️  COMPILING $@...⚙️  ⚙️ ]$(EOC)"
	@echo "$(CYAN)$$coffe$(EOC)"
	@sleep 1
	@clear
	@echo "$(CYAN)$$cbus$(EOC)"

#	@$(ECHO) Compiling $@

#	@$(CPCC) $(FLAGS) -c $(SRC)
#	@$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	@/bin/rm -rf obj
	@/bin/rm -f *.d *.replace
	@$(cbustama) [Delete...];
	@echo "$(WHT)[CLean Done]$(EOC)"

fclean: clean
	@/bin/rm -rf $(NAME)
	@$(cbustama) [Delete...];
	@echo "$(WHT)[FcLean Done]$(EOC)"
	
re: fclean all

define cbus

                                                                                               
                                                                                                
  ,----..                                        ___                          ____              
 /   /   \   ,---,                             ,--.'|_                      ,'  , `.            
|   :     :,---.'|            ,--,             |  | :,'                  ,-+-,.' _ |            
.   |  ;. /|   | :          ,'_ /|   .--.--.   :  : ' :               ,-+-. ;   , ||            
.   ; /--` :   : :     .--. |  | :  /  /    '.;__,'  /    ,--.--.    ,--.'|'   |  || ,--.--.    
;   | ;    :     |,-.,'_ /| :  . | |  :  /`./|  |   |    /       \  |   |  ,', |  |,/       \   
|   : |    |   : '  ||  ' | |  . . |  :  ;_  :__,'| :   .--.  .-. | |   | /  | |--'.--.  .-. |  
.   | '___ |   |  / :|  | ' |  | |  \  \    `. '  : |__  \__\/: . . |   : |  | ,    \__\/: . .  
'   ; : .'|'   : |: |:  | : ;  ; |   `----.   \|  | '.'| ," .--.; | |   : |  |/     ," .--.; |  
'   | '/  :|   | '/ :'  :  `--'   \ /  /`--'  /;  :    ;/  /  ,.  | |   | |`-'     /  /  ,.  |  
|   :    / |   :    |:  ,      .-./'--'.     / |  ,   /;  :   .'   \|   ;/        ;  :   .'   \ 
 \   \ .'  /    \  /  `--`----'      `--'---'   ---`-' |  ,     .-./'---'         |  ,     .-./ 
  `---`    `-'----'                                     `--`---'                   `--`---'     

endef
define coffe




                      (
                        )     (
                 ___...(-------)-....___
             .-""       )    (          ""-.
       .-'``'|-._             )         _.-|
      /  .--.|   `""---...........---""`   |
     /  /    |                             |
     |  |    |                             |
      \  \   |                             |
       `\ `\ |                             |
         `\ `|                             |
         _/ /\                             /
        (__/  \                           /
     _..---""` \                         /`""---.._
  .-'           \                       /          '-.
 :               `-.__             __.-'              :
 :                  ) ""---...---"" (                 :
  '._               `"--...___...--"`              _.'
    \""--..__                              __..--""/
     '._     """----.....______.....----"""     _.'
        `""--..,,_____            _____,,..--""`
                      `"""----"""`



endef
export cbus
export coffe

.PHONY: all clean fclean re

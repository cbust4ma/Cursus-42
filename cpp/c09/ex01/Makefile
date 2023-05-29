define bogus
-march=native: Esta opción genera código para la arquitectura 
de la máquina donde se está compilando. Esto puede mejorar el 
rendimiento de su programa al usar las características específicas 
de la arquitectura.

-finline-functions: Esta opción sugiere al compilador que intente inlinear 
las funciones que llama. En algunos casos, esto puede mejorar el rendimiento.

-funroll-loops: Esta opción sugiere al compilador que intente desenrollar 
los ciclos en su código. En algunos casos, esto puede mejorar el rendimiento.
endef
NAME = RPN

SRC = main.cpp\
      RPN.cpp
	 

OBJ = $(addprefix obj/, $(SRC:.cpp=.o))#$(SRC:.cpp=.o)
#wpedantic -pedantic.errors
#Emita todas las advertencias exigidas por las estrictas normas ISO C e ISO C++; rechace todos los programas que utilicen extensiones prohibidas y algunos otros programas que no sigan las normas ISO C e ISO C++.
OBJDIRS := $(sort $(dir $(OBJ)))

LIBS = $(BOOSTLIBS) $(SFMLLIBS)
override HEADERS := RPN.hpp

override HEADERS := $(addprefix includes/,$(HEADERS))

CPPC = c++ -MD -O2 -Wpedantic -pedantic-errors -g3 -fstack-protector -finline-functions

CXXFLAGS = -std=c++98 -march=native -funroll-loops #-ffast-math

CPPFLAGS = -Wall -Wextra -Werror -fsanitize=address -fno-omit-frame-pointer 

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
	@echo "[🔥 DONE 🔥] $<;"

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
	@$(cbustama) [✅ $@ has been successfully created] $<;
	@echo "$(CYAN)$$coffe$(EOC)"
	@sleep 1
	@clear
	@echo "$(CYAN)$$cbus$(EOC)"

#	@$(ECHO) Compiling $@

#	@$(CPCC) $(FLAGS) -c $(SRC)
#	@$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	@/bin/rm -rf obj
	@/bin/rm -f *.d
	@$(cbustama) [Delete...];
	@echo "$(WHT)[CLean Done]$(EOC)"

fclean: clean
	@/bin/rm -rf $(NAME)
	@$(cbustama) [🗑️ $(NAME) has been deleted] $<;
	
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
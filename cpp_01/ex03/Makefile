NAME = war

CCX = c++ #g++  no mec, c++ no resto
CCXFLAGS = -Wall -Wextra -Werror -std=c++98 -g



SRCS = main.cpp HumanB.cpp HumanA.cpp Weapon.cpp


all: $(NAME)

$(NAME):
	$(CCX) $(CCXFLAGS) $(SRCS) -o $(NAME)
	@clear
	@echo "✅ ${NAME} is compiled."


clean:
	@rm -rf $(NAME)
	@clear
	@echo "🗑️ executable removed."

re: clean all

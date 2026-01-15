NAME = convert

CCX = c++
CCXFLAGS = -Wall -Wextra -Werror -std=c++98 -g



SRCS = main.cpp converters.cpp ScalarConverter.cpp which_type.cpp


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

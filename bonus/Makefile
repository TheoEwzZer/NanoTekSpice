##
## EPITECH PROJECT, 2024
## NanoTekSpice
## File description:
## Digital Electronics
##

NAME	=	nanotekspice

TEST_NAME	=	unit_tests

CC		=	g++ -g3
RM		=	rm -rf

SRC			=	$(shell find src -type f -name "*.cpp")

TESTS_SRC	=	$(shell find tests src -type f -name "*.cpp" -not -name "Main.cpp")

OBJ			=	$(SRC:.cpp=.o)
TESTS_OBJ	=	$(TESTS_SRC:.cpp=.o)

WARN	= 	-std=c++20 -Wall -Wextra -Werror

$(NAME):
	@$(CC) -o $(NAME) $(SRC) $(WARN)

all:	$(NAME)

clean:
	@$(RM) $(OBJ)
	@find . -name "*~" -delete -o -name "#*#" -delete
	@$(RM) vgcore.*
	@$(RM) a.out
	@find . -name "*.gc*" -delete

fclean:	clean
	@$(RM) $(NAME)

re:		fclean all

unit_tests: $(TESTS_OBJ)
	@$(CC) -o $(TEST_NAME) $(TESTS_OBJ) -std=c++20 -lcriterion

tests_run: unit_tests
	./unit_tests

.PHONY: all clean fclean re tests_run

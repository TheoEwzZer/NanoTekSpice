##
## EPITECH PROJECT, 2024
## NanoTekSpice
## File description:
## Digital Electronics
##

NAME	=	nanotekspice

CC		=	g++ -g3
RM		=	rm -rf

SRC		=	$(shell find src -type f -name "*.cpp")

OBJ		=	$(SRC:.cpp=.o)

WARN	= 	-std=c++20 -Wall -Wextra -Werror

$(NAME):
	@$(CC) -o $(NAME) $(SRC) $(WARN)

all:	$(NAME)

clean:
	@$(RM) $(OBJ)
	@find . -name "*~" -delete -o -name "#*#" -delete
	@$(RM) vgcore.*
	@$(RM) a.out
	@find . -name *.gc* -delete

fclean:	clean
	@$(RM) $(NAME)

re:		fclean all

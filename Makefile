##
## EPITECH PROJECT , [ YEAR ]
## [ NAME_OF_THE_PROJECT ]
## File description : meaningful
## No file there , just an epitech header example .
## You can even have multiple lines if you want !
##

SRC	=	myworld.c

OBJ	=	$(SRC:.c=.o)

NAME	=	myworld

CC	= 	gcc

TESTS_DIR = tests/

TESTS_SRC = $(TESTS_DIR)test_myworld.c

TESTS_OBJ = $(TESTS_SRC:.c=.o)

TESTS_NAME = unit_tests

TESTS_FLAGS = -lcriterion --coverage

all: $(NAME)

$(NAME):	$(OBJ)
		$(CC) -g3 $(OBJ) -o $(NAME) $(CSFML)
clean:
	rm -f *.o
	rm -f src/*.o
	rm -f $(TESTS_DIR)*.o
	rm -f *.gcda
	rm -f *.gcno

fclean: clean
	rm -f $(NAME)
	rm -f $(TESTS_NAME)

re: fclean all

.PHONY: all clean fclean re tests_run

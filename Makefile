##
## EPITECH PROJECT , [ YEAR ]
## [ NAME_OF_THE_PROJECT ]
## File description : meaningful
## No file there , just an epitech header example .
## You can even have multiple lines if you want !
##

SRC	=	src/extra_fun.c\
		src/create_stuff.c\
		src/myworld.c

OBJ	=	$(SRC:.c=.o)

NAME	=	myworld

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -lm

CC	= 	gcc

# Dirección de la carpeta de pruebas
TESTS_DIR = tests/

# Archivos de prueba (ajusta estos según tus pruebas)
TESTS_SRC = $(TESTS_DIR)test_myworld.c

# Objetos de prueba
TESTS_OBJ = $(TESTS_SRC:.c=.o)

# Nombre del ejecutable de pruebas
TESTS_NAME = unit_tests

# Flags para criterio (framework de pruebas de Epitech)
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

# Regla para compilar y ejecutar las pruebas unitarias
tests_run: $(TESTS_OBJ) $(filter-out src/myworld.o, $(OBJ))
	$(CC) -o $(TESTS_NAME) $(TESTS_OBJ) $(filter-out src/myworld.o, $(OBJ)) $(TESTS_FLAGS) $(CSFML)
	./$(TESTS_NAME)

.PHONY: all clean fclean re tests_run
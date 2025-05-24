CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Bureaucrat
SRC = main.cpp Bureaucrat.cpp
OBJ = ${SRC:.cpp=.o}

all: ${NAME}

${NAME} : ${OBJ}
	${CPP} ${FLAGS} -o ${NAME} ${SRC}

%.o: %.cpp Bureaucrat.hpp
	${CPP} ${FLAGS} -c $< -o $@

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: clean
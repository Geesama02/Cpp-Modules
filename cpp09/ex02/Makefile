CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = PmergeMe
SRC = main.cpp PmergeMe.cpp
OBJ = ${SRC:.cpp=.o}

all: ${NAME}

${NAME} : ${OBJ}
	${CPP} ${FLAGS} -o ${NAME} ${SRC}

%.o: %.cpp PmergeMe.hpp	
	${CPP} ${FLAGS} -c $< -o $@

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: clean
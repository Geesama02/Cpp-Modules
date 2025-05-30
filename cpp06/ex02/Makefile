CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = getType
SRC = main.cpp Base.cpp
OBJ = ${SRC:.cpp=.o}

all: ${NAME}

${NAME} : ${OBJ}
	${CPP} ${FLAGS} -o ${NAME} ${SRC}

%.o: %.cpp Base.hpp Data.hpp A.hpp B.hpp C.hpp
	${CPP} ${FLAGS} -c $< -o $@

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: clean
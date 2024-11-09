CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow
NAME = DiamondTrap
SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJ = ${SRC:.cpp=.o}

all: ${NAME}

${NAME} : ${OBJ}
	${CPP} ${FLAGS} -o ${NAME} ${SRC}

%.o: %.cpp ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp
	${CPP} ${FLAGS} -c $< -o $@

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
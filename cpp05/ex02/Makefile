CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = AForm
SRC = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
OBJ = ${SRC:.cpp=.o}

all: ${NAME}

${NAME} : ${OBJ}
	${CPP} ${FLAGS} -o ${NAME} ${SRC}

%.o: %.cpp Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp
	${CPP} ${FLAGS} -c $< -o $@

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: clean
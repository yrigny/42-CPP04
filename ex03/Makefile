# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/11 11:49:53 by yrigny            #+#    #+#              #
#    Updated: 2024/07/22 18:29:24 by yrigny           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp \
	AMateria.cpp Ice.cpp Cure.cpp \
	Character.cpp \
	MateriaSource.cpp

INCLUDE = AMateria.hpp Ice.hpp Cure.hpp \
	Character.hpp ICharacter.hpp \
	MateriaSource.hpp IMateriaSource.hpp

OBJ = $(SRC:.cpp=.o)

NAME = ex03

GREEN = \033[1;32m

NONE = \033[0m

QUIET = 0

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJ): %.o: %.cpp $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@ -D QUIET=$(QUIET)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

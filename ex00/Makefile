# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/11 11:49:53 by yrigny            #+#    #+#              #
#    Updated: 2024/07/18 14:24:51 by yrigny           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp

INCLUDE = Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp

OBJ = $(SRC:.cpp=.o)

NAME = ex00

GREEN = \033[1;32m

NONE = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJ): %.o: %.cpp $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

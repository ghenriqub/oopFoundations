# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/14 18:23:55 by ghenriqu          #+#    #+#              #
#    Updated: 2026/02/22 18:47:18 by ghenriqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# program name
NAME = scavtrap

SRC = 		main.cpp \
			ClapTrap.cpp \
			ScavTrap.cpp
HEADERS =	ClapTrap.hpp \
			ScavTrap.hpp

# compiling flags:
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

# files and objects:
OBJ = $(SRC:.cpp=.o)

# rm files and objects
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[0;32mDone ✓\033[m"

clean:
	@$(RM) $(OBJ)
	@echo "\033[0;32mClean ✓\033[m"

%.o: %.cpp
	@$(CC) $(CPPFLAGS) -c $< -o $@

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;32mFClean ✓\033[m"

re: fclean all

.PHONY: all clean fclean re


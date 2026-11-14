# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/07 16:46:33 by ghenriqu          #+#    #+#              #
#    Updated: 2026/11/07 16:46:35 by ghenriqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= PmergeMe

# srcs and objects
SRC = 	main.cpp PmergeMe.cpp
OBJ = $(SRC:.cpp=.o)

# compiling flags:
CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

# rm files and objects
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[0;32mDone ✓\033[m"

clean:
	@$(RM) $(OBJ)
	@echo "\033[0;32mClean ✓\033[m"

%.o: %.cpp
	@$(CXX) $(CPPFLAGS) -c $< -o $@

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;32mFClean ✓\033[m"

re: fclean all

.PHONY: all clean fclean re

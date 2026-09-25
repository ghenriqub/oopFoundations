# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/25 16:59:03 by ghenriqu          #+#    #+#              #
#    Updated: 2026/09/25 16:59:09 by ghenriqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= identify

OBJ_PATH	=./obj/

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

RM			= rm -rf

SRC 		=	main.cpp \
				Base.cpp

OBJ 		= $(addprefix $(OBJ_PATH), $(notdir $(SRC:.cpp=.o)))
DEP 		= $(OBJ:.o=.d)

$(OBJ_PATH)%.o: %.cpp
				@printf "\n$(CY)Generating object...$(RC)\n"
				@mkdir -p $(OBJ_PATH)
				$(CC) $(CFLAGS) -MMD -MP -c $< -o $@
				@printf "\n$(GR)Object ready!$(RC)\n"

$(NAME): 	$(OBJ)
				@printf "\n$(CY)Generating executable...$(RC)\n"
				$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
				@printf "\n$(GR)Done!$(RC)\n"

-include $(DEP)

.PHONY:		all clean fclean re leak

all:		$(NAME)

re:			fclean all

clean:
			$(RM) $(OBJ) $(OBJ_PATH)
			@printf "\n$(RE)Objects removed!$(RC)\n\n"

fclean:		clean
			$(RM) $(NAME)
			@printf "\n$(RE)Executables removed!$(RC)\n\n"

leak:		all
			valgrind --leak-check=full --track-origins=yes ./${NAME}

# Colors
CY			= \033[36;1m
YE			= \033[33;1m
GR			= \033[32;1m
RE			= \033[31;1m
RC			= \033[0m

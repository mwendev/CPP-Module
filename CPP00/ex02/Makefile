# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 22:30:21 by mwen              #+#    #+#              #
#    Updated: 2022/02/11 18:05:21 by mwen             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	account
SRCS		=	Account.cpp tests.cpp
CFLAG		=	-Wall -Wextra -Werror -std=c++98

.SILENT:

all:		$(NAME)
$(NAME):	$(OBJ)
			c++ $(CFLAG) $(SRCS) $^ -o $(NAME)
			printf '\033[32m[ ✔ ] %s\n\033[0m' "Created account"

./objects/%.o: ./sources/%.cpp
	mkdir -p objects
	c++ -c $< -o $@

clean:
	rm -rf objects
	/bin/rm -f *.o
	/bin/rm -rf ./objects/*.o
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Cleaned account"

fclean: clean
	/bin/rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fcleaned account"

re: fclean all

.PHONY: clean fclean re all test

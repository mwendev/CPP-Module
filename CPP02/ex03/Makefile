# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 22:45:49 by mwen              #+#    #+#              #
#    Updated: 2022/02/13 17:22:43 by mwen             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	a.out
SRCS		=	main.cpp Fixed.cpp Point.cpp bsp.cpp
CFLAG		=	-Wall -Wextra -Werror -std=c++98

.SILENT:

all:		$(NAME)
$(NAME):	$(OBJ)
			c++ $(CFLAG) $(SRCS) $^ -o $(NAME)
			printf '\033[32m[ ✔ ] %s\n\033[0m' "Created a.out"

./objects/%.o: ./sources/%.cpp
	mkdir -p objects
	c++ -c $< -o $@

clean:
	rm -rf objects
	/bin/rm -f *.o
	/bin/rm -rf ./objects/*.o
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Cleaned a.out"

fclean: clean
	/bin/rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fcleaned a.out"

re: fclean all

.PHONY: clean fclean re all test
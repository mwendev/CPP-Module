# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 22:45:49 by mwen              #+#    #+#              #
#    Updated: 2022/02/19 22:04:56 by mwen             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	class_casting
SRCS		=	main.cpp Base.cpp
CFLAG		=	-Wall -Wextra -Werror -std=c++98

.SILENT:

all:		$(NAME)
$(NAME):	$(OBJ)
			c++ $(CFLAG) $(SRCS) $^ -o $(NAME)
			printf '\033[32m[ ✔ ] %s\n\033[0m' "Created class_casting"

./objects/%.o: ./sources/%.cpp
	mkdir -p objects
	c++ -c $< -o $@

clean:
	rm -rf objects
	/bin/rm -f *.o
	/bin/rm -rf ./objects/*.o
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Cleaned class_casting"

fclean: clean
	/bin/rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fcleaned class_casting"

re: fclean all

.PHONY: clean fclean re all test
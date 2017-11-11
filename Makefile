#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msymkany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/11 11:19:01 by msymkany          #+#    #+#              #
#    Updated: 2017/11/11 11:19:06 by msymkany         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME := ft_gkrellm

CXX := @clang++
FL := -Wall -Wextra -Werror

SOURCE := main.cpp \
        DateTimeModule.cpp \
        IMonitorModule.cpp \
        HostnameModule.cpp \
        OSModule.cpp \

OBJECTS := $(SOURCE:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
		@$(CXX) $(FL) $(OBJECTS) -o $(NAME)
		@echo "The project is ready"

%.o: %.cpp
	$(CXX) $(FL) -c $< -o $@

.PHONY: clean fclean re

clean:
	@rm -f $(OBJECTS)
	@rm -f *~ *#
	@echo "It's clean"

fclean: clean
	@rm -f $(NAME)

re: fclean all
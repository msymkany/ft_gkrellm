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
CFLAGS = -F./libraries/SDL
SDL_FLAGS =  -framework SDL2 -framework SDL2_image -framework SDL2_ttf


SOURCE := main.cpp \
        DateTimeModule.cpp \
        IMonitor.cpp \
        HostnameModule.cpp \
        OSModule.cpp \
        RAMModule.cpp \
        CPUModule.cpp \
        NetModule.cpp \
        NCurcesDisplay.cpp \
        SDLDisplay.cpp \

OBJECTS := $(SOURCE:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
		@$(CXX) $(CFLAGS) $(SDL_FLAGS) $(FL) $(OBJECTS) -o $(NAME) -lncurses
		@echo "The project is ready"

%.o: %.cpp
	$(CXX) $(CFLAGS) $(FL) -c $< -o $@

.PHONY: clean fclean re

clean:
	@rm -f $(OBJECTS)
	@rm -f *~ *#
	@echo "It's clean"

fclean: clean
	@rm -f $(NAME)

re: fclean all

sdl2:
	cp -r libraries/SDL/SDL2_image.framework ~/Library/Frameworks/
	cp -r libraries/SDL/SDL2.framework ~/Library/Frameworks/
	cp -r libraries/SDL/SDL2_ttf.framework ~/Library/Frameworks/
##
## EPITECH PROJECT, 2021
## B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic [WSL]
## File description:
## Makefile
##

SRC	= 	src/ecs/EntityManager.cpp	\
		src/ecs/Scene.cpp			\
		src/ecs/ASystem.cpp			\
		src/ecs/ComponentMap.cpp	\
		src/Game.cpp				\
        src/raylib/Window.cpp

CXX = g++

AR = ar rvs

CXXFLAGS = -W -Wextra -Werror -I./include -lraylib -lopengl32 -lgdi32 -lwinmm -lpthread

LDFLAGS =

NAME = engine

OBJ = $(SRC:.cpp=.o)

.PHONY: all clean fclean re engine
all: $(OBJ) compile

%.o:    %.c
	echo -e "\e[0;94mCompiled\t\e[0;95m$<\e[39m -> \e[38;5;208m$@\e[39m"
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(LDFLAGS)

compile: $(OBJ)
	$(AR) $(NAME).a $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME).a

re: fclean all

debug: CXXFLAGS += -ggdb
debug: all
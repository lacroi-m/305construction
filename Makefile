##
## Makefile for  in /home/ze/305construction
## 
## Made by ze
## Login   <maxime.lacroix@epitech.eu>
## 
## Started on  Tue Nov 14 13:20:48 2017 ze
## Last update Tue Nov 14 18:18:49 2017 ze
##

CPP	= g++ -std=c++11 -I./incs -Wall -Wextra -Werror

NAME	= 305construction

RM	= rm -f

SRC	 = $(foreach dir,$(shell find srcs -type d),$(wildcard $(dir)/*.cpp))

OBJ     = $(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):$(OBJ)
	$(CPP) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:     fclean all

.PHONY: all clean fclean re

%.o: %.cpp
	$(CPP) -c $< -o $@ $(CFLAGS)

.PHONY: all clean fclean re

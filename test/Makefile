##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME	= projTester

CC		= gcc

RM		= rm -f

SRC		= src/main.c \
		src/print_flag_h.c \
		

OBJ		= $(SRC:.c=.o)

LIBFLAG	= -L lib/my/ -lmy

CFLAGS = -g

all: $(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) $(SRC) -o $(NAME) $(LIBFLAG) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:		clean
	rm -f lib/my/libmy.a
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

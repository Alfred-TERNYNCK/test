##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME	= FASTAtools

CC		= gcc

RM		= rm -f

SRC		= src/main.c \
		src/print_flag_h.c \
		src/option.c \
		src/flag_1.c \
		src/flag_2.c \
		src/flag_3.c \

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

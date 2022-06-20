##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME= libmy.a

OBJ= *.o

RM= rm -f *.o

SRC= *.c

all: $(NAME)

$(NAME):
	 gcc -c $(SRC)
	 ar rc $(NAME) $(OBJ)
	 make clean

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

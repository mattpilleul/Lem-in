##
## EPITECH PROJECT, 2019
## CPE_lemin_2019
## File description:
## Makefile
##

SRC	=	my_getnbr.c	\
		my_put_nbr.c	\
		my_putstr.c 	\
		my_revstr.c 	\
		my_strcmp.c		\
		my_strdup.c 	\
		my_strlen.c

OBJ	=	$(SRC:.c=.o)

NAME	=	NAME

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc libmy.a $(OBJ)

$(OBJ): $(SRC)
	@gcc -c $(SRC) -g

clean:
	@rm *.o
	@rm *a
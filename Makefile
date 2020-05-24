##
## EPITECH PROJECT, 2020
## Makefile for lemin
## File description:
## lemin
##

MAKEFLAGS	+=	--no-print-directory

SRC	=	./src/main.c	\
		./src/parse_arg.c	\
		./src/clean_string.c	\
		./src/arrange_arg.c	\
		./src/check_error.c	\
		./src/check_room.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -I./include -g

RED			=	\033[0;31m
GREEN		=	\033[0;32m
NC			=	\033[0m
GREY		=	\033[90m
BG_COLOR	=	\033[36m

NAME1	=	lem_in

NAME	=	NAME

all:	flags $(OBJ)
		@make -C ./lib/my
		@gcc -o $(NAME1) $(OBJ) $(CFLAGS) -L./lib/my -lmy

flags:
	@echo -e '${BG_COLOR}Flags: $(CFLAGS)${NC}'

%.o:	%.c
	@echo -e '${GREEN} [ OK ]${NC} Building : $<'
	@$(CC) -o $@ -c $< $(LDFLAGS) $(CFLAGS)

clean:
	@echo -e '${RED}Cleaning sources${NC}'
	@make clean -C ./lib/my
	@rm -f $(OBJ)
	@rm -f $(NAME1)
	@echo -e '${RED}Clean${NC} : OK'

fclean:	clean
	@rm -f $(NAME1)
	@echo -e '${RED}Fclean${NC}: ./$(NAME) removed'

re:	fclean all

.PHONY: re fclean clean all
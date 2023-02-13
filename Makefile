##
## MINISHELL1 PROJECT, 2023
## bsminishell
## File description:
## Makefile
##

CC	=	GCC
CCFLAGS	=	-Wextra -Wall -Werror

SRC	=	src/main.c			\
		src/lib/my_putstr.c		\
		src/lib/my_putchar.c		\
		src/lib/my_strlen.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	bsminishell

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CCFLAGS) -g3

clean	:
	$(RM) $(OBJ)
	$(RM) -f *~
	cd includes && $(RM) -f *~
	cd src && $(RM) -f *~
	cd src/lib && $(RM) -f *~

fclean :	clean
	$(RM) -f $(NAME)

re	:	fclean all

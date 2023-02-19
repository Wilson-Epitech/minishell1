##
## MINISHELL1 PROJECT, 2023
## bsminishell
## File description:
## Makefile
##

CC	=	gcc
CCFLAGS	=	-Wextra -Wall -Werror
CFLAGS	=	-g3

SRC	=	src/main.c			\
		src/error_handling.c				\
		src/get_path.c						\
		src/exec.c							\
		src/lib/my_putstr.c		\
		src/lib/my_putchar.c		\
		src/lib/my_strlen.c		\
		src/lib/my_str_to_word_array_space.c	\
		src/lib/my_str_to_word_array_line.c	\
		src/lib/my_strcat.c				\
		src/lib/my_strcpy.c				\
		src/lib/my_revstr.c				\
		src/lib/my_strdup.c				\
		src/lib/my_strncmp.c			\

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CCFLAGS) $(CFLAGS)

clean	:
	$(RM) $(OBJ)
	$(RM) -f *~
	cd includes && $(RM) -f *~
	cd src && $(RM) -f *~
	cd src/lib && $(RM) -f *~

fclean :	clean
	$(RM) -f $(NAME)

re	:	fclean all

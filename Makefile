##
## Makefile for projet in /home/ghocha/Documents/C/projet
##
## Made by Gabriel Hochart
## Login   <ghocha@esgi.fr>
##
## Started on  Thu Dec  8 19:41:43 2016 Gabriel Hochart
## Last update Sun Jan  1 20:31:05 2017 Gabriel Hochart
##

NAME	= codec

CC	= gcc -g3

CFLAGS	= -Wall -Wextra
CFLAGS	+= -Iinclude
LDFLAGS	= -lSDLmain -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer

SRCS	=	sources/codec.c \
		sources/EncodingFullG4Matrix.c \
		sources/FormatMatrixTextToMatrix.c \
		sources/DecodingFullG4Matrix.c

OBJS	= $(SRCS:.c=.o)

RM	= rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	  $(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
	  $(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re

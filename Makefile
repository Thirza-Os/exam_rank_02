NAME	=	libftprintf.a

SRC =		ft_printf.c

HEADER	=	ft_printf.h
OBJECTS	=	$(SRC:.c=.o)
CFLAGS	=	-Wall -Wextra -Werror
CC		=	gcc

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	$(AR) rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
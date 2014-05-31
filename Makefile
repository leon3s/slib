NAME		=	slib.a

INCLUDES	=	-I includes

SRCPATH		=	srcs/

OBJPATH		=	objs/

SRCS		=	num.c \
				lp.c \
				print.c \
				count.c \

SRC		=	$(addprefix $(SRCPATH), $(SRCS))

OBJ		=	$(patsubst $(SRCPATH)%.c, $(OBJPATH)%.o, $(SRC))

CFLAGS		+=	-W -Wall -Wextra -Werror $(INCLUDES)

CC		=	gcc

all: $(NAME)

$(OBJ): | $(OBJPATH)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJPATH):
	mkdir -p $(OBJPATH)

clean:
	rm -rf $(OBJPATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(OBJPATH)%.o: $(SRCPATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re dir

NAME = fractol
PRF =  $(PRF_DIR)libftprintf.a

PRF_DIR = ./printf/
SRC_DIR = ./src/
INC_DIR = ./includes/

SRC = main\
initialized\
rendering\
event\

SRCS = $(addprefix ${SRC_DIR}, $(addsuffix .c, ${SRC}))

OBJB = $(SRCS:.c=.o)

CC = cc

CFLAG = -Wall -Werror -Wextra

.c.o :
	$(CC) $(CFLAG) -Imlx -c -I $(INC_DIR) -I $(PRF_DIR) $< -o $@

all : $(NAME)

$(NAME) : $(OBJB) $(PRF)
	$(CC) $(OBJB) $(PRF) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(PRF) : 
	@make -C $(PRF_DIR)

clean :
		rm -f $(OBJB) $(B_OBJB) && make -C $(PRF_DIR) clean

fclean : clean
		rm -f $(NAME) && make -C $(PRF_DIR) fclean

re : clean fclean all
NAME = libftprintf.a
LIBFT =  $(LBF_DIR)libft.a

LBF_DIR = ./libft/
SRC_DIR = ./src/
INC_DIR = ./includes/

SRC = ft_printf\
ft_print_chars\
ft_print_hex\
ft_print_nbrs\
ft_print_pointer\

SRCS = $(addprefix ${SRC_DIR}, $(addsuffix .c, ${SRC}))

OBJB = $(SRCS:.c=.o)

CC = cc

CFLAG = -Wall -Werror -Wextra

.c.o :
		$(CC) $(CFLAG) -c -I $(INC_DIR) -I $(LBF_DIR) $< -o $@

all : $(NAME)

$(NAME) : $(OBJB) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar -rc $(NAME) $(OBJB)

$(LIBFT) : 
		make -C $(LBF_DIR) bonus

clean :
		rm -f $(OBJB) $(B_OBJB) && make -C $(LBF_DIR) clean

fclean : clean
		rm -f $(NAME) && make -C $(LBF_DIR) fclean

re : clean fclean all
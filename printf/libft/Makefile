# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: risasada <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 16:47:19 by risasada          #+#    #+#              #
#    Updated: 2023/06/21 14:11:41 by risasada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c\
ft_bzero.c\
ft_calloc.c\
ft_isalpha.c\
ft_isalnum.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_itoa.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memmove.c\
ft_memset.c\
ft_putchar_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_putstr_fd.c\
ft_split.c\
ft_strchr.c\
ft_strdup.c\
ft_striteri.c\
ft_strjoin.c\
ft_strlcpy.c\
ft_strlcat.c\
ft_strlen.c\
ft_strmapi.c\
ft_strncmp.c\
ft_strnstr.c\
ft_strrchr.c\
ft_strtrim.c\
ft_substr.c\
ft_tolower.c\
ft_toupper.c\

B_SRCS = ft_lstadd_back_bonus.c\
ft_lstadd_front_bonus.c\
ft_lstclear_bonus.c\
ft_lstdelone_bonus.c\
ft_lstiter_bonus.c\
ft_lstlast_bonus.c\
ft_lstnew_bonus.c\
ft_lstsize_bonus.c\
ft_lstmap_bonus.c\


OBJB = $(SRCS:.c=.o)

B_OBJB = $(B_SRCS:.c=.o)

CC = cc

CFLAG = -Wall -Werror -Wextra

ifdef WITH_BONUS
	OBJB_ALL = $(OBJB) $(B_OBJB)
else 
	OBJB_ALL = $(OBJB)
endif

.c.o :
		$(CC) $(CFLAG) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJB_ALL)
	ar -rcs $@ $^

bonus :
	@make WITH_BONUS=1

clean : 
		rm -f $(OBJB) $(B_OBJB)

fclean : clean
		rm -f $(NAME)

re : clean fclean all

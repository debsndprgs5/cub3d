# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysebban <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 17:31:38 by ysebban           #+#    #+#              #
#    Updated: 2023/02/13 10:39:00 by ysebban          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isdigit.c ft_itoa.c       ft_putnbr_fd.c  ft_strlcpy.c    ft_tolower.c \
	ft_atoi.c       ft_memchr.c     ft_putstr_fd.c  ft_strlen.c     ft_toupper.c \
	ft_bzero.c      ft_memcmp.c     ft_split.c      ft_strmapi.c \
	ft_calloc.c     ft_memcpy.c     ft_strchr.c     ft_strncmp.c \
	ft_isalnum.c    ft_memmove.c    ft_strdup.c     ft_strnstr.c \
	ft_isalpha.c    ft_memset.c     ft_striteri.c   ft_strrchr.c \
	ft_isascii.c    ft_putchar_fd.c ft_strjoin.c    ft_strtrim.c \
	ft_isprint.c    ft_putendl_fd.c ft_strlcat.c    ft_substr.c \
	ft_printf.c 	my_putnbr_base.c get_next_line.c colors.c \
	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c \
	ft_lstadd_back.c ft_str_is_numeric.c  maths.c		ft_double_split.c 

SRC_bonus = ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.	ft_lstadd_back.c 


OBJS = $(SRC:.c=.o)

OBJS_bonus = $(SRC:.c=.o)


WWW = -Wall -Wextra -Werror

$(NAME):
	gcc $(WWW) -c $(SRC) 
	ar rc $(NAME) $(OBJS)

$(BONUS):
	gcc $(WWW) -c $(SRC_bonus) 
	ar rc $(NAME) $(OBJS_bonus)


all: $(NAME)

bonus : $(BONUS)

clean:
	rm -f $(OBJS) $(OBJS_bonus)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all 


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/25 15:54:14 by nverbrug          #+#    #+#              #
#    Updated: 2021/01/04 16:01:25 by nverbrug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c \
	ft_bzero.c \
	ft_intlen.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_itoa_base.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putchar.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putnbr.c \
	ft_putstr_fd.c \
	ft_putstr.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_add_returnline.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	get_next_line.c \
	get_next_line_utils.c \
	free_str.c \
	ft_strdup_text.c

NAME = libft.a
OBJS = $(SRC:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror -I$(HEADER)
GCC = gcc
RM = rm -rf
HEADER = ./


all: $(NAME)

$(OBJS): $(SRC)
	$(GCC) $(CFLAGS) -c $(SRC)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all test clean fclean re


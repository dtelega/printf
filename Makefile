#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtelega <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/17 12:42:58 by dtelega           #+#    #+#              #
#    Updated: 2017/02/21 18:05:32 by dtelega          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

SRC = put_len.c ft_printf.c clen_spec.c ft_intlen.c ft_putstr.c ft_putchar_fd.c d_i_get_s.c ft_atoi_l.c ft_atoi_ll.c ft_atoi.c ft_bzero.c ft_itoa_base_lun.c ft_itoa_base_un.c ft_itoa_base.c ft_itoa_ll.c ft_itoa_long.c ft_itoa.c ft_llintlen.c ft_longintlen.c ft_putchar.c ft_putstr_fd.c ft_strcmp.c ft_strcpy.c ft_strjoin.c ft_strlen.c ft_strnew.c ft_tolower.c ft_tolowstr.c ft_without_tr.c get_flag.c get_some_spec.c rules.c rules_2.c rules_3.c x_x_get_s.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all


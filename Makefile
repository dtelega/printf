#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtelega <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/17 12:42:58 by dtelega           #+#    #+#              #
#    Updated: 2017/02/18 14:37:14 by dtelega          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c ft_atoi_ll.c ft_itoa_base_uintmax.c ft_itoa_base_lun.c x_x_get_s.c d_i_get_s.c ft_itoa_ll.c ft_llintlen.c ft_itoa_sig.c ft_itoa_base_un.c clen_spec.c ft_atoi_l.c ft_dtoa.c ft_itoa_base.c ft_itoa_long.c ft_longintlen.c ft_more_memory.c ft_putlongnbr.c ft_tolowstr.c get_flag.c get_some_spec.c rules.c rules_2.c rules_3.c ft_putmap_fd.c ft_intlen.c ft_lenmap.c ft_strrev.c ft_putmap.c ft_lstmap.c ft_lstiter.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstnew.c ft_itoa.c ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_strsplit.c ft_strtrim.c ft_strjoin.c ft_strsub.c ft_strnequ.c ft_strequ.c ft_strmapi.c ft_strmap.c ft_striteri.c ft_striter.c ft_strclr.c ft_strdel.c ft_strnew.c ft_memdel.c ft_memalloc.c ft_putnbr.c ft_strrchr.c ft_strchr.c ft_strlcat.c ft_strncat.c ft_strcat.c ft_toupper.c ft_tolower.c ft_isprint.c ft_isascii.c ft_isalnum.c ft_isdigit.c ft_isalpha.c ft_memccpy.c ft_memcmp.c ft_strnstr.c ft_strdup.c ft_strlen.c ft_memset.c ft_bzero.c ft_memmove.c ft_memchr.c ft_memcpy.c ft_putchar.c ft_putstr.c ft_strcmp.c ft_atoi.c ft_strcpy.c ft_strncpy.c ft_strstr.c ft_strncmp.c

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


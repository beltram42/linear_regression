# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alambert <alambert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 18:46:28 by alambert          #+#    #+#              #
#    Updated: 2022/06/28 12:04:44 by alambert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ft_absf.c \
		ft_absi.c \
		ft_atoi.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_free.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_iscntrl.c \
		ft_isdigit.c \
		ft_islower.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_isupper.c \
		ft_itoa.c \
		ft_itoav.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c\
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_malgets.c \
		ft_malmove.c \
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
		ft_sadd.c \
		ft_sdiv.c \
		ft_smult.c \
		ft_split.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncat.c \
		ft_strncpy.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnlen.c \
		ft_strnstr.c \
		ft_strpbrk.c \
		ft_strrchr.c \
		ft_strspncspn.c \
		ft_strspnfb.c \
		ft_strtok_r.c \
		ft_strtol.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		get_next_line.c \


OBJS = $(FILES:.c=.o)


NAME = lib42.a


CC = gcc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f
AR = ar rcs

.c.o: 
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY : clean fclean re

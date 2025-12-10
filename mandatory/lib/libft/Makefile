# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvalino- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 14:17:37 by dvalino-          #+#    #+#              #
#    Updated: 2023/06/21 17:42:08 by dvalino-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

MY_SOURCE = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	    ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
	    ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	    ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	    ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	    ft_atoi.c ft_calloc.c ft_strdup.c ft_strjoin.c ft_split.c \
	    ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	    ft_putnbr_fd.c ft_substr.c ft_strmapi.c ft_striteri.c \
	    ft_strtrim.c get_next_line.c get_next_line_utils.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
	ft_lstmap_bonus.c

MY_OBJECTS = ${MY_SOURCE:.c=.o}

BONUS_OBJ = ${BONUS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

CC = gcc

$(NAME): $(MY_OBJECTS)
	ar -rc $(NAME) $(MY_OBJECTS)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

clean:
	rm -f $(MY_OBJECTS) $(BONUS_OBJ)

fclean: clean
	rm -f ${NAME}

re: fclean all

bonus: $(MY_OBJECTS) $(BONUS_OBJ)
	ar -rc $(NAME) $(MY_OBJECTS) $(BONUS_OBJ)

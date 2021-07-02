# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atory <atory@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/25 19:35:50 by atory             #+#    #+#              #
#    Updated: 2021/04/25 19:35:50 by atory            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

FT_LIST =	ft_memset.c		ft_strrchr.c	ft_calloc.c		ft_split.c\
			ft_bzero.c		ft_strnstr.c	ft_strdup.c\
			ft_memcpy.c		ft_strncmp.c	ft_substr.c\
			ft_memccpy.c	ft_atoi.c		ft_strjoin.c\
			ft_memmove.c	ft_isalpha.c	ft_strtrim.c\
			ft_memchr.c		ft_isdigit.c	ft_strmapi.c\
			ft_memcmp.c		ft_isalnum.c	ft_itoa.c\
			ft_strlen.c		ft_isascii.c	ft_putchar_fd.c\
			ft_strlcpy.c	ft_isprint.c	ft_putstr_fd.c\
			ft_strlcat.c	ft_toupper.c	ft_putendl_fd.c\
			ft_strchr.c		ft_tolower.c	ft_putnbr_fd.c

BONUS_FT_LIST = ft_lstnew.c				ft_lstadd_back.c\
				ft_lstadd_front.c		ft_lstdelone.c\
				ft_lstsize.c			ft_lstclear.c\
				ft_lstlast.c			ft_lstiter.c\
				ft_lstmap.c
OBJS =			$(addprefix objects/, $(FT_LIST:.c=.o))
BONUS_OBJS = 	$(addprefix objects/, $(BONUS_FT_LIST:.c=.o))

RM = @rm -f

CFLAGS = -Wall -Wextra -Werror -g

.PHONY = all clean fclean re

all:	objects $(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $?

objects :
				@mkdir $@

objects/%.o :	%.c $(HEADER)
			    gcc $(FLAGS)  -c $< -o $@

bonus: 			objects $(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)  $?

clean:
				@rm -rf objects/

fclean:			clean
				$(RM) $(NAME)

re:	fclean all


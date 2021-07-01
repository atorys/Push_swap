#-------------------------NAME--------------------------/
NAME =		push_swap
#------------------------SOURCES------------------------/

INCLUDES =	./
VPATH =     libft \
			files \
            files/algorithm \
            files/stack_manipulations

HEADERS	=	push_swap.h \
			libft/libft.h
LIBRARY	=	libft/libft.a

FILES = 	push_swap.c \
			input_checker.c \
			operations.c \
			double_operations.c \
			forming.c \
			tools.c \
			utils.c
O_FILES = 	$(addprefix objects/, $(FILES:.c=.o))

#-----------ADDITIONAL--------------------------------/

CFLAGS =	-Wall -Wextra -Werror -O3
BL =		\033[1m\033[32m
W =			\033[38;2;255;255;255

#-----------RULES-------------------------------------/

.PHONY =	all	clean fclean re


all	=		$(NAME)

$(NAME) :	objects $(O_FILES) $(LIBRARY)
			@$(CC) $(FLAGS) $(O_FILES) $(LIBRARY) -o $(NAME)
			@printf %s ./$(NAME) | pbcopy

objects :
			@mkdir $@

$(LIBRARY) :
			make -C libft/

objects/%.o :	%.c $(HEADERS)
			    gcc $(FLAGS) -I $(INCLUDES) -c $< -o $@


#-------CLEAN

clean :
			@rm -rf objects/
			@make clean -C libft/

fclean :	clean
			@rm -f $(NAME)
			@make fclean -C libft/

re :        fclean $(NAME)

.PHONY =	all clean fclean re
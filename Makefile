#=============={ NAME }==============#
NAME =		push_swap
#============={ SOURCES }============#

INCLUDES =	./

HEADERS	=	push_swap.h \
			libft/libft.h
LIBRARY	=	libft/libft.a

FILES = 	push_swap.c \

O_FILES	=	$(FILES:.c=.o)

FLAGS =		-Wall -Wextra -Werror -O3
G =			\033[38;2;154;205;50
W =			\033[38;2;255;255;255

#=============={ RULES }=============#

all	=		$(NAME)

$(NAME) :	$(O_FILES) $(HEADERS)
			@$(CC) $? $(FLAGS) -o $(NAME)
			@echo ""
			@echo "$(G);1m wwwwwwwwww  DONE!  wwwwwwwwww"
			@echo "$(W);1m ENTER COMMAND + V AND STACK A"
			@echo "$(G);1m wwwwwwwwwwwwwwwwwwwwwwwwwwwww\n"
			@printf %s ./$(NAME) | pbcopy

$(LIBRARY) :
			make -C libft/

%.o :		%.c $(HEADERS)
			gcc $(FLAGS) -I $(INCLUDES) -c $< -o $@

clean :
			@rm -f $(O_FILES)
			@make clean -C libft/

fclean :	clean
			@rm -f $(NAME)
			@make fclean -C libft/

re :
			flean all

.PHONY =	all clean fclean re
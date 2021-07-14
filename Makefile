#-------------------------NAME--------------------------/
NAME =		push_swap
#------------------------SOURCES------------------------/

INCLUDES =	./
VPATH =     libft \
			files \
			includes \
			files/checker \
            files/algorithm \
            files/stack_manipulations

HEADERS	=	push_swap.h \
			libft/libft.h \
			get_next_line.h
LIBRARY	=	libft/libft.a

#--------------------FILES--------------------------/

FILES = 	push_swap.c \
			input_checker.c \
			operations.c \
			double_operations.c \
			forming.c \
			mini_sort.c \
			huge_sort.c \
			tools.c \
			utils.c
O_FILES = 	$(addprefix objects/, $(FILES:.c=.o))

#-------------------BONUS-FILES

B_FILES =	input_checker.c \
			utils.c \
			operations.c \
			double_operations.c \
			forming.c \
			checker.c \
			get_next_line.c \
			get_next_line_utils.c \

B_O_FILES = $(addprefix objects/, $(B_FILES:.c=.o))

#-----------ADDITIONAL--------------------------------/

CFLAGS =	-Wall -Wextra -Werror -O3
W =			\033[38;2;255;255;255
P =			\033[38;2;255;74;150
P2 =		\033[38;2;200;74;180
P3 =		\033[38;2;150;74;210
P4 =		\033[38;2;100;74;240

#-----------RULES-------------------------------------/

.PHONY =	all	clean fclean re


all	:		$(NAME)
bonus:		objects $(B_O_FILES) checker

$(NAME) :	objects $(O_FILES) $(LIBRARY)
			@$(CC) $(FLAGS) $(O_FILES) $(LIBRARY) -o $(NAME)
			@clear ;
			@echo "\n$(P);1m                                 d8"
			@echo "$(P);1m                                 88"
			@echo "$(P2);1m      88d888b. dP    dP ,d888'   88d8888b.        ,d888'   dP  dP  dP .d8888b. 88d888b."
			@echo "$(P2);1m      88'  '88 88    88 Y8ooooo. 88'   '88        Y8ooooo. 88  88  88 88'  '88 88'  '88"
			@echo "$(P3);1m      88.  .88 88.  .88       88 88     88              88 88.88b.88' 88.  .88 88.  .88"
			@echo "$(P3);1m      8Y888P'  '888888' '88888P' 8P     dP d8888P '88888P' 8888P Y8P  '88888P8 8Y888P'"
			@echo "$(P4);1m      88                                                                       88"
			@echo "$(P4);1m      8P                                                                       8P"
			@echo "  "
			@echo "$(W);m                            [ press CMD+V and add stack A ]\n";
			@printf %s ./$(NAME) | pbcopy

checker: 	$(B_O_FILES) $(LIBRARY)
			@$(CC) $(FLAGS) $(B_O_FILES) $(LIBRARY) -o checker

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
			@echo "removing [objects] [libft/objects]"

fclean :	clean
			@rm -f $(NAME)
			@rm -f checker
			@make fclean -C libft/
			@echo "removing [push_swap] [checker] [libft.a]"

re :        fclean all

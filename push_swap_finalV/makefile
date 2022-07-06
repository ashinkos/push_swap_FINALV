NAME= push_swap
SRC = ./mandatory/ft_actions.c ./mandatory/ft_actions_2.c ./mandatory/ft_fill_stack.c ./mandatory/ft_lstadd_back.c\
		./mandatory/ft_lstadd_front.c ./mandatory/ft_lstlast.c ./mandatory/ft_lstnew.c ./mandatory/ft_lstsize.c\
		./mandatory/ft_putstr.c ./mandatory/ft_strcmp.c ./mandatory/ft_strlen.c ./mandatory/ft_isdigit.c ./mandatory/ft_check_arg.c ./mandatory/ft_atoi.c ./mandatory/ft_sorting.c\
		./mandatory/ft_actions_3.c ./mandatory/ft_lis.c ./mandatory/ft_bigsort.c ./mandatory/ft_push_a.c\
		./mandatory/help_lis.c ./mandatory/help_push_a.c\

BONUS_NAME = checker
SRC_BONUS = ./bonus/getnl.c ./bonus/checker.c ./bonus/instruct_1.c ./bonus/instruct_2.c ./mandatory/ft_lstadd_back.c\
		./mandatory/ft_lstadd_front.c ./mandatory/ft_lstlast.c ./mandatory/ft_lstnew.c ./mandatory/ft_lstsize.c\
		./mandatory/ft_putstr.c ./mandatory/ft_strcmp.c ./mandatory/ft_strlen.c ./mandatory/ft_isdigit.c ./mandatory/ft_check_arg.c ./mandatory/ft_atoi.c \
		
CC = cc
FLAGS= -Wall -Werror -Wextra
PARA  = -c 

OBJ= $(SRC:.c=.o)

OBJ_BONUS= $(SRC_BONUS:.c=.o)

%.o : %.c 
	$(CC) $(PARA) $(FLAGS) $<  -o $@


all: $(NAME)
	
$(NAME): $(OBJ)
		${CC} $(OBJ) -o ${NAME}

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)

re: fclean all

bonus: $(OBJ_BONUS)
	$(CC)   $(OBJ_BONUS) -o $(BONUS_NAME)
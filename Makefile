NAME = minishell
CFLAGS = -Wall -Werror -Wextra
SOURCE = dev.c core.c

OBJ = $(SOURCE:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft/
	@echo "Compiling $(NAME)..."
	@gcc $(CFLAGS) $(OBJ) -o $(NAME) -L libft/ -lft
clean :
	@make -C libft/ clean
	@echo "Removing $(OBJ) ..."
	@rm -rf $(OBJ)

fclean : clean
	@make -C libft/ fclean
	@echo "Removing $(NAME) ..."
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re

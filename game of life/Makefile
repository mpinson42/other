NAME = game_of_life

SRC = ./srcs/main.c 

FLAGS = -Wall -Wextra -Werror

SRC2 = main.o 

all: $(NAME)

$(NAME): $(SRC)
	@echo "mpinson" > auteur
	@make -C ./libft all
	@cp ./libft/libft.a ./lib
	gcc -o $(NAME) $(FLAGS) -I ./include -L ./lib -lft $(SRC) 


clean:
	/bin/rm -f $(SRC2)
	@make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all
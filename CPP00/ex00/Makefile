NAME =	megaphone

CC =	c++
CFLAGS =	-Wall -Wextra -Werror
CFLAGS +=	-std=c++98

SRC =	megaphone.cpp
OBJ =	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

subject: all
	./$(NAME)	"shhhhh... I think the students are asleep..."
	./$(NAME)	Damnit " ! " "Sorry students, I thought this thing was off."
	./$(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f ._*

re: fclean all

.PHONY: all clean fclean re subject
NAME =	harlFilter

CC =	c++
CFLAGS +=	-Wall -Wextra -Werror
CFLAGS +=	-std=c++98

INCL_HDR :=	$(shell find . -type f -name '*.hpp' -exec dirname "{}" \; | \
					uniq | sed -e 's/^/-I/g')

SRC =	$(SRC_MAIN) $(SRC_CLASS)
SRC_MAIN =	main.cpp
SRC_CLASS =	Harl.cpp

OBJ =	$(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) $(INCL_HDR) -c $< -o $@

subject: all
	./$(NAME) "WARNING"
	./$(NAME) "I am not sure how tired I am today..."

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f ._*

re: fclean all

.PHONY: all clean fclean re subject

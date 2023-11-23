NAME =	bsp

CC =	c++
CFLAGS +=	-Wall -Wextra -Werror
CFLAGS +=	-std=c++98
# CFLAGS +=	-g -fsanitize=address

INCL_HDR :=	$(shell find . -type f -name '*.hpp' -exec dirname "{}" \; | \
					uniq | sed -e 's/^/-I/g')

SRC =	$(SRC_MAIN) $(SRC_CLASS) $(SRC_FUNC) $(SRC_NMSPC)
SRC_MAIN =	main.cpp
SRC_CLASS =	Fixed.cpp\
			Point.cpp
SRC_FUNC =	bsp.cpp
SRC_NMSPC =	print.cpp

OBJ =	$(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) $(INCL_HDR) -c $< -o $@

subject: all
	./$(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f ._*

re: fclean all

.PHONY: all clean fclean re subject

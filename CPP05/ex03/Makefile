NAME =	forms

CC =	c++
CFLAGS +=	-Wall -Wextra -Werror
DEPFLAGS +=	-MMD -MF $(DEP_DIR)$*.d

INCL_HDR :=	$(shell find .. -type f -name '*.hpp' -exec dirname "{}" \; | \
					uniq | grep -v -e ex00 -e ex01 | sed -e 's/^/-I/g')

SRC =	$(SRC_MAIN) $(SRC_CLASS) $(SRC_FUNC) $(SRC_PREV)
SRC_MAIN =	main.cpp
SRC_CLASS =	Intern.cpp
SRC_FUNC =	
SRC_PREV =	../ex02/Bureaucrat.cpp	../ex02/AForm.cpp	../ex02/ShrubberyCreationForm.cpp	../ex02/RobotomyRequestForm.cpp	../ex02/PresidentialPardonForm.cpp

DIRS =	$(OBJ_DIR) $(DEP_DIR)
OBJ_DIR =	obj/
TEMP = $(notdir $(SRC))
OBJ =	$(TEMP:%.cpp=$(OBJ_DIR)%.o)
DEP_DIR =	dep/
DEP =	$(TEMP:%.cpp=$(DEP_DIR)%.d)

all: $(DIRS) $(NAME)

$(DIRS):
	@mkdir $(DIRS)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: %.cpp
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(INCL_HDR) -c $< -o $@

$(OBJ_DIR)%.o: ../ex02/%.cpp
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(INCL_HDR) -c $< -o $@

-include $(DEP)

subject: all
	./$(NAME)

clean:
	@rm -f $(OBJ) $(DEP)

fclean: clean
	@rm -f $(NAME)
	@rm -f *_shrubbery
	@rm -f ._*
	@rmdir $(DIRS) 2> /dev/null || true

re: fclean all

.PHONY: all clean fclean re subject

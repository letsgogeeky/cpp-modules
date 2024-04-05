NAME := accountant

CC := g++
CFLAGS := -Werror -Wextra -Wall -std=c++98 -g

SRC := Account.cpp tests.cpp

SRC_DIR := .
OBJ_DIR := obj

OBJ := $(addprefix $(OBJ_DIR)/, $(subst /,@,$(SRC:.cpp=.o)))

all:
	@$(MAKE) $(NAME) -j

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(CFLAGS) && echo "Compiled $(NAME) successfully..!"

$(OBJ): $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

## OBJ_DIR can be replaced by INCLUDE directory incase you need to include a library
.SECONDEXPANSION:
$(OBJ_DIR)/%.o: $(SRC_DIR)/$$(subst @,/,$$*).cpp
	@$(CC) $(CFLAGS) $(addprefix -iquote ,$(OBJ_DIR)) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re test

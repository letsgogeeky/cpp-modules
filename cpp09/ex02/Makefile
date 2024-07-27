NAME := PmergeMe

CC := c++
CFLAGS := -Werror -Wextra -Wall -std=c++98 -g

SRC := main.cpp

SRC_DIR := .
OBJ_DIR := obj

OBJ := $(addprefix $(OBJ_DIR)/, $(subst /,@,$(SRC:.cpp=.o)))

all:
	@$(MAKE) $(NAME) -j

$(NAME): $(OBJ)
	@python3 anim.py &
	@ANIMATION_PID=$$!;
	@$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
	@sleep  7.5
	@touch stop_animation.txt
	@wait $$ANIMATION_PID 2>/dev/null && echo "Cool isn't it?"

## OBJ_DIR can be replaced by INCLUDE directory incase you need to include a library
.SECONDEXPANSION:
$(OBJ_DIR)/%.o: $(SRC_DIR)/$$(subst @,/,$$*).cpp
	@$(CC) $(CFLAGS) $(addprefix -iquote ,$(OBJ_DIR)) -c $< -o $@

$(OBJ): $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re

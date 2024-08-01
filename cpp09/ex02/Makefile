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
	@$(CC) $(OBJ) -o $(NAME) $(CFLAGS) && touch .$(NAME)-compiled
	@if test -f .$(NAME)-compiled; then \
		echo "Compilation Complete: $(NAME) is ready!"; \
		echo "       ___________  "; \
		echo "      '._==_==_=_.' "; \
		echo "      .-\\:CPP09 /-.    "; \
		echo "     | (|:.ex02 |) |    "; \
		echo "      '-|:.     |-'     "; \
		echo "        \\::.    /      "; \
		echo "         '::. .'        "; \
		echo "           ) (          "; \
		echo "         _.' '._        "; \
		echo "        '-------'       "; \
		rm -f .$(NAME)-compiled; \
	fi

## OBJ_DIR can be replaced by INCLUDE directory incase you need to include a library
.SECONDEXPANSION:
$(OBJ_DIR)/%.o: $(SRC_DIR)/$$(subst @,/,$$*).cpp
	@$(CC) $(CFLAGS) $(addprefix -iquote ,$(OBJ_DIR)) -c $< -o $@

$(OBJ): $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

test:
	@python3 test_sort.py

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re

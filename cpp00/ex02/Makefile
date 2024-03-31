# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramymoussa <ramymoussa@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 17:40:36 by ramoussa          #+#    #+#              #
#    Updated: 2024/03/31 12:46:16 by ramymoussa       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := accountant

CC := g++
CFLAGS := -Werror -Wextra -Wall -std=c++98 -g

SRC := Account.cpp main.cpp
SRC_TEST := Account.cpp tests.cpp

SRC_DIR := .
OBJ_DIR := obj

OBJ := $(addprefix $(OBJ_DIR)/, $(subst /,@,$(SRC:.cpp=.o)))
OBJ_TEST := $(addprefix $(OBJ_DIR)/, $(subst /,@,$(SRC_TEST:.cpp=.o)))

all:
	@$(MAKE) $(NAME) -j

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(CFLAGS) && echo "Compiled $(NAME) successfully..!"

test: $(OBJ_TEST)
	@$(CC) $(OBJ_TEST) -o $(NAME)_test $(CFLAGS) && echo "Compiled $(NAME)_test successfully..!"

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

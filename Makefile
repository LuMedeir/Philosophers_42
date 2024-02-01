# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 15:25:37 by lumedeir          #+#    #+#              #
#    Updated: 2024/01/31 12:09:16 by lumedeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c src

NAME = philo
INCLUDE = -I./include
SRC =	philosophers.c \
		init.c \
		time.c \
		routine.c \
		monitoring.c \
		actions.c \
		clean.c \
		utils.c
OBJ = obj
SRCOBJ = $(SRC:%.c=${OBJ}/%.o)
CFLAG = -Wall -Werror -Wextra -g3

# -fsanitize=thread

all: $(NAME)
$(NAME): $(SRCOBJ)
	$(CC) $^ -o $(NAME) -pthread
	@echo "\e[1;31mThe Makefile of [PHILOSOPHERS] has been compiled!🤠\033[0m"
${OBJ}/%.o : %.c
	mkdir -p $(OBJ) 
	$(CC) -c $< -o $@ $(CFLAG) $(INCLUDE)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -f philo
re: fclean all
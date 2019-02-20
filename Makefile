# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knaumov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/05 22:08:06 by knaumov           #+#    #+#              #
#    Updated: 2018/12/05 22:28:02 by knaumov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = -Iincludes -Ilibft

SRCS = 	srcs/main.c \
		srcs/backtracking/find_all_connections_between_start_and_end.c \
		srcs/backtracking/algorithm.c \
		srcs/creating_graph/if_connected.c \
		srcs/creating_graph/creating_graph.c \
		srcs/reading_input/reading_input.c \
		srcs/reading_input/check_if_number.c \
	   	srcs/reading_input/checks.c \
		srcs/solution/finding_solution.c \
		srcs/solution/assign_paths.c \
		srcs/solution/move_ants.c \
		srcs/utils/find_index.c \
		srcs/utils/add_char.c \
		srcs/utils/printing_checks.c \
		srcs/utils/struct_operations/t_rooms.c \
		srcs/utils/struct_operations/t_links.c \
		srcs/utils/struct_operations/t_list.c \
		srcs/utils/struct_operations/t_ant.c \
		srcs/utils/struct_operations/t_path.c 

LIBFT = -L ./libft -lft

OBJ		=	$(SRCS:.c=.o)

EXEC = lem-in

RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;36m
RED_EXTRA = \033[1;31m
GREEN_EXTRA = \033[1;32m
BLUE_EXTRA = \033[1;36m

%.o:%.c
			@echo "$(GREEN) - Creating $(GREEN_EXTRA)$<...$(RESET)"
			@gcc -Wall -Wextra -Werror -c $< -o $@ $(INCLUDES) -g

all: $(EXEC)

$(EXEC): $(OBJ)
	@make -C libft
	@echo "$(GREEN)Compiling executable $(GREEN_EXTRA)$(EXEC)$(RESET)"
	@gcc -Wall -Wextra -Werror -o $(EXEC) $(OBJ) $(INCLUDE) $(LIBFT) -g
	@echo "$(BLUE_EXTRA)$(EXEC)$(BLUE): Complete$(RESET)"

clean:
	@if [ -a "srcs/main.o" ]; then \
	echo "$(RED)Deleting objects for $(RED_EXTRA)$(EXEC)$(RESET)"; \
	/bin/rm -rf $(OBJ); \
	fi
	@make -C libft clean
	@echo "$(BLUE_EXTRA)clean$(BLUE): Complete$(RESET)"

fclean: clean
	@if [ -a "$(EXEC)" ]; then \
	echo "$(RED)Deleting executable $(RED_EXTRA)$(EXEC)$(RESET)"; \
	/bin/rm -f $(EXEC); \
	fi

	@make -C libft fclean
	@echo "$(BLUE_EXTRA)fclean$(BLUE): Complete$(RESET)"

re: fclean all

.PHONY: clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/05 22:08:06 by knaumov           #+#    #+#              #
#    Updated: 2019/02/25 13:28:26 by amelikia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = -I includes -I libft

SRCS = 	srcs/main.c \
		srcs/backtracking/find_all_connections_between_start_and_end.c \
		srcs/backtracking/algorithm.c \
		srcs/creating_graph/if_connected.c \
		srcs/creating_graph/creating_graph.c \
		srcs/reading_input/reading_input.c \
		srcs/reading_input/check_if_number.c \
		srcs/reading_input/checks.c \
		srcs/utils/return_name_from_index.c \
		srcs/utils/find_index.c \
		srcs/utils/add_char.c \
		srcs/utils/printing/print_ant_farm.c \
		srcs/utils/printing/print_connections.c \
		srcs/utils/printing/print_graph.c \
		srcs/utils/printing/print_list.c \
		srcs/utils/printing/print_path.c \
		srcs/utils/printing/print_usage.c \
		srcs/utils/struct_operations/t_rooms.c \
		srcs/utils/struct_operations/t_links.c \
		srcs/utils/struct_operations/t_list.c \
		srcs/utils/struct_operations/t_ant.c \
		srcs/utils/struct_operations/t_path.c \
		srcs/utils/struct_operations/t_moves.c \
		srcs/utils/cleaners_p1.c \
		srcs/utils/cleaners_p2.c \
		srcs/reading_input/readers.c \
		srcs/solution_opt/finding_solution.c \
		srcs/solution_opt/assign_paths.c \
		srcs/solution_opt/move_ants.c \
		srcs/solution_opt/update_moves.c \
		srcs/solution_opt/prepare_new_path.c 

		#srcs/solution/finding_solution.c \
		srcs/solution/assign_paths.c \
		srcs/solution/move_ants.c \
		srcs/solution/match_to_others.c 

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
			@gcc -Wall -Wextra -Werror -c $< -o $@ $(INCLUDES) #-g -fsanitize=address -fsanitize=undefined

all: $(EXEC)

$(EXEC): $(OBJ)
	@make -C libft
	@echo "$(GREEN)Compiling executable $(GREEN_EXTRA)$(EXEC)$(RESET)"
	@gcc -Wall -Wextra -Werror -o $(EXEC) $(OBJ) $(INCLUDE) $(LIBFT) #-g -fsanitize=address -fsanitize=undefined
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

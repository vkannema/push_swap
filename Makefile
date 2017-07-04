# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/14 15:23:53 by vkannema          #+#    #+#              #
#    Updated: 2017/03/17 14:05:46 by vkannema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECK = checker
PSWAP = push_swap
CHECK_DIR = check
PUSH_DIR = pswap
O_CHECKDIR = check/objects
O_PUSHDIR = pswap/objects
INCLUDES = -I ./includes -I ./Libft/includes
LIB = -L./Libft/ -lftprintf
CHECK_FILES = check/check_op1.c \
 	check/checker.c \
	check/handle_error.c \
	check/list.c \
	check/list_print.c \
	check/main.c \
	check/rotate_reverse.c \
	check/swap_push.c
O_CHECK = $(CHECK_FILES:$(CHECK_DIR)/%.c=$(O_CHECKDIR)/%.o)
PUSH_FILES = pswap/algo.c \
	pswap/big_lists.c \
	pswap/list.c \
	pswap/little_lists.c \
	pswap/main.c \
	pswap/operation2.c \
	pswap/operations.c \
	pswap/operations1.c \
	pswap/rotate_reverse.c \
	pswap/split_array.c \
	pswap/swap_push.c \
	pswap/handle_errors.c
O_PUSH = $(PUSH_FILES:$(PUSH_DIR)/%.c=$(O_PUSHDIR)/%.o)
FLAGS = -Wall -Wextra -Werror -g

all : $(CHECK) $(PSWAP)

$(CHECK): $(O_CHECK)
	make -C Libft
	@gcc $(FLAGS) $(LIB) $(O_CHECK) -o $(CHECK)
	@printf "\033[0;33m CHECKER FINISHED !\033[0;0m\n"

$(O_CHECKDIR)/%.o: $(CHECK_DIR)/%.c
	@mkdir -p $(O_CHECKDIR)
	@gcc $(FLAGS) $(INCLUDES) -o $@ -c $< \
	 && printf "\033[0;0m%-34s\033[1;30m -->>\t\033[0;32m$@\033[0;0m\n" "$<"

$(PSWAP): $(O_PUSH)
	@gcc $(FLAGS) $(LIB) $(O_PUSH) -o $(PSWAP)
	@printf "\033[0;33m PUSH_SWAP FINISHED !\033[0;0m\n"

$(O_PUSHDIR)/%.o: $(PUSH_DIR)/%.c
	@mkdir -p $(O_PUSHDIR)
	@gcc $(FLAGS) $(INCLUDES) -o $@ -c $< \
	&& printf "\033[0;0m%-34s\033[1;30m -->>\t\033[0;32m$@\033[0;0m\n" "$<"

clean :
	@rm -rf $(O_CHECKDIR) $(O_PUSHDIR)
	@make clean -C ./Libft
	@echo "Objects cleaned"

fclean : clean
	@make fclean -C ./Libft
	@rm -f $(CHECK) $(PSWAP)
	@echo "Deleted exec"

re : fclean all

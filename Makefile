OBJS = \
	push_swap_action.o \
	push_swap_brute_force.o \
	push_swap_helper.o \
	push_swap_lis.o \
	push_swap_utils.o \
	push_swap_calculate_rotation.o \
	push_swap_manage_rotation.o \
	push_swap_verify_input.o \
	push_swap_normalize.o \
	push_swap_main_helper.o \

all: submodule libft.a push_swap push_swap_bonus

push_swap: push_swap_main.c $(OBJS)
	cc $^ -L./42libft/ft_base -lft -L./42libft/ft_math -lftmath -o $@

push_swap_bonus: push_swap_bonus.c $(OBJS)
	cc $^ -L./42libft/ft_base -lft -L./42libft/ft_math -lftmath -L./42libft/ft_gnl -lftgnl -o $@

%.o: %.c \
	cc -c $< -Wall -Wextra -Werror -o $@

submodule:
	git submodule update --init --recursive

libft.a:
	make -C ./42libft all

clean:
	rm -f $(OBJS)
	make -C ./42libft clean

fclean: clean
	rm -f push_swap push_swap_bonus
	make -C ./42libft fclean

re: fclean all

.PHONY: all clean fclean re

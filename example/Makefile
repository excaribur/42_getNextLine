NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MKLIB = ar crs

SRC_DIR		= ./srcs
LIBFT_DIR	= ./libft
INCS_DIR	= ./includes
BUILD_DIR	= build

LIBFT		= $(LIBFT_DIR)/libft.a
SRCS =	ft_printf.c \
		ft_utilprintf_1.c\
		ft_utilprintf_2.c\
		ft_helper_1.c\
		ft_helper_2.c

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(MKLIB) $(NAME) $(OBJS)
	@echo "===== DONE ====="

$(OBJS): $(BUILD_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "==== Compiling $< ===="
	@$(CC) -c $(CFLAGS) -I $(INCS_DIR) -I $(LIBFT_DIR) $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	/bin/rm -r -f $(BUILD_DIR)
fclean: clean
	make fclean -C $(LIBFT_DIR)
	/bin/rm -f $(NAME)
re: fclean all

main: re
	@$(CC) main.c -L . -I $(INCS_DIR) -lftprintf -o main
	@echo
	@echo
	@echo "\033[0;32m==== TEST ====\033[0m"
	@./main
	@echo "\033[0;32m==== DONE TEST ====\033[0m"

mem: re
	@$(CC) main.c -L . -I $(INCS_DIR) -lftprintf -o main
	@echo
	@echo
	@echo "\033[0;32m==== TEST LEAK ====\033[0m"
	@valgrind -q --leak-check=full --track-origins=yes ./main
	@echo "\033[0;32m==== DONE TEST LEAK ====\033[0m"

SRCS =	push_swap.c \
		instructions_a.c \
		instructions_b.c \
		utils_a.c \
		utils_b.c \
		push_in_list.c \
		checks.c \
		init_and_frees.c \
		case_500.c \
		case_100.c \
		choose_path.c \
		process_moves.c \
		count.c \
		case_5_helper.c \



 
NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g # -g3-fsanitize=address

OBJ_DIR = objs
SRCS_DIR = srcs
INC_DIR = includes

OBJ = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

.c.o:
	${CC} ${CFLAGS} -c$< -o ${<:.c=.o}

all:
	@$(MAKE) -j $(NAME)

$(NAME): $(OBJ)
		${CC} $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c | .gitignore
		@mkdir -p $(OBJ_DIR)
		${CC} $(CFLAGS) -I $(INC_DIR) -c $< -o $@

.gitignore:
		@echo $(NAME) > .gitignore

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)

fclean:	clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
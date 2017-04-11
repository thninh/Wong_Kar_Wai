
DEBUG	= yes
FLAGS=-Wall -Wextra -Werror
NAME	= game_2048
LDFLAGS	= -I./include/
SRC		= \
		  main.c algo.c control.c menu_ncurses.c check_map.c funct_ncurses.c \
		  set_funct.c display_result.c gen_new_number.c
OBJ		= $(SRC:.c=.o)
	SRCDIR	= ./src/
	OBJDIR	= ./obj/
	INCDIR	= ./include/
	SRCS	= $(addprefix $(SRCDIR), $(SRC))
	OBJS	= $(addprefix $(OBJDIR), $(OBJ))
	INCS	= $(addprefix $(INCDIR), $(INC))

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	@gcc $(FLAGS) -o $@ $^ -L./libft/ -lft -lncurses -lform -g
	@echo "\\033[1;32mSuccess.✔︎\\033[0;39m"

$(OBJS): $(SRCS)
ifeq ($(DEBUG),yes)
	@echo "\\033[1;31mDEBUG COMPILATION...\\033[0;39m"
else
	@echo "\\033[1;31mCompilation with -Wall -Wextra -Werror...\\033[0;39m"
endif

	@make -C libft/
	@echo "\\033[1;34mGenerating objects... Please wait.\\033[0;39m"
	@gcc $(FLAGS) -c $(SRCS) $(LDFLAGS)
	@mkdir -p $(OBJDIR)
	@mv $(OBJ) $(OBJDIR)

.PHONY: clean fclean re

clean:
	@echo "\\033[1;34mDelete objects ✔︎\\033[0;39m"
	@rm -f $(OBJS)
	@rm -Rf $(OBJDIR)

fclean: clean
	@make fclean -C libft/
	@echo "\\033[1;34mDelete $(NAME) ✔︎\\033[0;39m"
	@rm -f $(NAME)
	@rm -f scores.txt

re: fclean all

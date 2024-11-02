NAME 		= 	push_swap

CC 			= 	cc
CFLAGS 		= 	-Wall -Wextra -Werror -g -I includes

SRC 		= 	algo a_position b_position moves parsing main \
				push rotate reverse swap stack

LIB 		= 	Libstache-Divine/libft.a

SRC_BONUS 	= 	main parsing push reverse rotate stack swap

SRCS 		= 	$(addsuffix .c, $(addprefix src/, $(SRC)))
OBJS 		= 	$(SRCS:.c=.o)

NAME_BONUS 	= 	checker
BONUS 		= 	$(addsuffix .c, $(addprefix bonus/, $(SRC_BONUS)))
OBJS_BONUS 	= 	$(BONUS:.c=.o)

# Cible principale
all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJS) $(LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo "\033[0;95m→ Compilation réussie pour $(NAME)\033[0m"

# Compilation du programme checker (bonus)
$(NAME_BONUS): $(OBJS_BONUS) $(LIB)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIB) -o $(NAME_BONUS)
	@echo "\033[0;95m→ Compilation réussie pour $(NAME_BONUS)\033[0m"

# Appel de libft
$(LIB):
	@echo "\033[0;95m→ Compilation de libft\033[0m"
	@$(MAKE) --quiet -C Libstache-Divine > /dev/null 2>&1

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	@rm -rf $(OBJS) $(OBJS_BONUS)
	@$(MAKE) --quiet -C Libstache-Divine clean
	@echo "\033[0;96m→ Nettoyage des fichiers objets terminé\033[0m"

# Nettoyage complet, incluant libft
fclean: clean 
	@rm -rf $(NAME) $(NAME_BONUS)
	@$(MAKE) --quiet -C Libstache-Divine fclean
	@echo "\033[0;96m→ Nettoyage complet terminé\033[0m"

re: fclean all

bonus: $(NAME_BONUS)

.PHONY: all clean fclean re bonus
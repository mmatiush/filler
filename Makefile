NAME :=			mmatiush.filler

SRC_DIR :=		./src/
OBJ_DIR :=		./obj/
INC_DIR :=		./libft/inc/

SRC :=			mmatiush.filler.c fil_additional_func.c fil_parse.c \
get_fil_player_char.c get_coordinates.c

OBJ :=			$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

CC :=			gcc -g
CC_FLAGS :=		-Wall -Wextra -Werror

LIBFT_DIR :=	./libft/
LIBFT := 		$(LIBFT_DIR)libft.a

all: lib obj_dir $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(CC_FLAGS) $(OBJ) $(LIBFT) -I $(INC_DIR)
	@echo "Compiling [ $(NAME) ]"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)filler.h
	@$(CC) -c $< -o $@ $(CC_FLAGS) -I $(INC_DIR)
	@echo "Linking" [ $< ]

lib:
	@make -C $(LIBFT_DIR)

obj_dir:
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -f $(OBJ) $(LIBFT_OBJ)
	@make -C $(LIBFT_DIR) clean
	@echo "Cleaning" [ object files $(NAME) ]

fclean:
	@rm -f $(OBJ) $(LIBFT_OBJ)
	@echo "Cleaning" [ object files $(NAME) ]
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo "Cleaning" [ $(NAME) ]
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
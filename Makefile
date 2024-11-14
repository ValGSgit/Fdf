FRAEMWORKS= minilibx-linux/libmlx.a -Lminilibx-linux -lmlx -lX11 -lXext -lm

FLAGS=cc -Werror -Wextra -Wall 

NAME = fdf
BONUS_NAME = fdf_bonus

OBJ_P = obj/

SRC_PATH = srcs/

BONUS_SRC = events_bonus.c
MAND_SRC = events.c

SRC = colors.c coordinates.c draw.c errors.c fdf.c \
ft_split.c functions.c functionalities.c modes.c parse_map.c \
parsing_functions.c get_next_line.c get_next_line_utils.c ft_printf.c\
ft_printhex.c ft_printint.c ft_printptr.c ft_printunsigned.c \

INCS	= -I ./includes/
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
SOBJ	= $(addprefix $(OBJ_P), $(SRC:.c=.o))
MAND_OBJ = $(OBJ_P)events.o
BONUS_OBJ = $(OBJ_P)events_bonus.o

all: $(OBJ_P) $(NAME)

$(NAME): $(SOBJ) $(MAND_OBJ)
	$(FLAGS) $(SOBJ) $(MAND_OBJ) -o $(NAME) $(FRAEMWORKS) -g
	@printf $(MAKE_LOGO)

bonus : $(OBJ_P) $(BONUS_NAME)

$(BONUS_NAME): $(SOBJ) $(BONUS_OBJ)
	@rm -f obj/events.o
	$(FLAGS) $(SOBJ) $(BONUS_OBJ) -o $(BONUS_NAME) $(FRAEMWORKS) -g
	@printf $(MAKE_LOGO)

$(OBJ_P):
	mkdir -p $(OBJ_P)

MAKE_LOGO="\n \033[0;33m░▒▓██████████████▓▒░ ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░▒▓████████▓▒░▒▓█▓▒░▒▓█▓▒░      ░▒▓████████▓▒░\n \
 \033[0;90m░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░       \n \
 \033[0;91m░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░       \n \
 \033[0;92m░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░▒▓███████▓▒░░▒▓██████▓▒░ ░▒▓██████▓▒░ ░▒▓█▓▒░▒▓█▓▒░      ░▒▓██████▓▒░  \n \
 \033[0;93m░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░       \n \
 \033[0;94m░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░       \n \
 \033[0;95m░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░▒▓█▓▒░      ░▒▓█▓▒░▒▓████████▓▒░▒▓████████▓▒░\n \
 \033[0;96m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n \
 \033[0;97m ░▒▓██████▓▒░ ░▒▓██████▓▒░░▒▓██████████████▓▒░░▒▓███████▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓████████▓▒░▒▓███████▓▒░ \n \
 \033[0;96m░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒ \n \
 \033[0;95m░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒ \n \
 \033[0;94m░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓███████▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓██████▓▒░ ░▒▓█▓▒░░▒▓█▓▒ \n \
 \033[0;93m░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒ \n \
 \033[0;91m░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒ \n \
 \033[0;90m ░▒▓██████▓▒░ ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░▒▓████████▓▒░▒▓████████▓▒░▒▓███████▓▒░ \n\n" \

$(OBJ_P)%.o: $(SRC_PATH)%.c
	$(FLAGS) $(INCS) -c $< -o $@

$(BONUS_OBJ): $(SRC_PATH)$(BONUS_SRC)
	$(FLAGS) $(INCS) -c $< -o $@

clean:
	@printf "\033[0;32m\e[1m ==> Fdf has been cleaned up successfully! \n"
	@rm -rf $(OBJ_P)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus 

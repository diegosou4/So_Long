NAME = so_long

SRC_MAP = readmap.c maputils.c createmap.c checkmap.c inicializemap.c utilsreadmap.c namemap.c 
SRC_EVENT = mouseevent.c keyevent.c animations.c 
SRC_EVENTB = animations.c countmove.c keyevent.c utilsb.c
SRC_GAME =  draw_map.c game_rules.c load_free.c 
SRC_UTILS = paint.c pixel.c sleep.c utils1.c split.c calloc.c ft_putnbr.c 
SRC_EXTERN = get_next_line_utils.c get_next_line.c 
SRC = $(addprefix ./src/map/, $(SRC_MAP)) \
      $(addprefix ./src/event/, $(SRC_EVENT)) \
      $(addprefix ./src/game/, $(SRC_GAME)) \
      $(addprefix ./src/utils/, $(SRC_UTILS)) \
      $(addprefix ./src/externfunc/get_next_line/, $(SRC_EXTERN))
SRC_BONUS = $(addprefix ./bonus/map/, $(SRC_MAP)) \
			$(addprefix ./bonus/event/, $(SRC_EVENTB)) \
			$(addprefix ./bonus/game/, $(SRC_GAME)) \
			$(addprefix ./bonus/utils/. $(SRC_UTILS)) \
			$(addprefix ./bonus/externfunc/get_next_line/, $(SRC_EXTERN))
SRCOBJ = src/obj/
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFLAGS = -lXext -lX11
LIB = minilibx-linux/libmlx_Linux.a
OBJ = $(addprefix $(SRCOBJ), $(SRC:./src/%.c=%.o))
OBJB = $(addprefix $(SRCOBJ), $(SRC:./bonus/%.c=%.o))

all: $(NAME)

$(NAME): $(OBJ)
	@${CC} ${CFLAGS} -g main.c ${OBJ} ${LIB} ${LIBFLAGS} -o $(NAME)

$(SRCOBJ)%.o: src/%.c
	@mkdir -p $(SRCOBJ)
	@mkdir -p $(dir $@)
	@${CC} ${CFLAGS} -c $< -o $@

bonus: $(NAME)

$(NAME): $(OBJB)
	@${CC} ${CFLAGS} -g main.c ${OBJB} ${LIB} ${LIBFLAGS} -o $(NAME)

$(SRCOBJ)%.o: bonus/%.c
	@mkdir -p $(SRCOBJ)
	@mkdir -p $(dir $@)
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf $(SRCOBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

SRC = ./src/event/keyevent.c \
    ./src/utils/paint.c \
    ./src/utils/pixel.c \
    ./src/map/readmap.c \
    ./src/game/load.c \
    ./src/utils/sleep.c \
    ./src/event/animations.c \
    ./src/externfunc/get_next_line/get_next_line_utils.c \
    ./src/externfunc/get_next_line/get_next_line.c \
    ./src/utils/utils1.c \
    ./src/utils/split.c \
    ./src/utils/calloc.c \
    ./src/utils/ft_putnbr.c \
    ./src/map/maputils.c \
    ./src/map/createmap.c \
    ./src/map/checkmap.c \
    ./src/map/inicializemap.c \
    ./src/map/utilsreadmap.c \
    ./src/game/draw_map.c \
    ./src/game/draw_wall.c \
    ./src/game/free_game.c \
    ./src/game/draw_choise.c \
    ./src/game/game_rules.c

CC = cc -Wall -Wextra -Werror main.c ${SRC}
LIB = minilibx-linux/libmlx_Linux.a

all:
	${CC} ${LIB} -lX11 -lXext	
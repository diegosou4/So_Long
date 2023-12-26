SRC = ./src/keyevent.c \
    ./src/paint.c \
    ./src/pixel.c \
    ./src/map/readmap.c \
    ./src/load.c \
    ./src/sleep.c \
    ./src/utils.c \
    ./src/animations.c \
    ./src/countmove.c \
    ./src/externfunc/get_next_line/get_next_line_utils.c \
    ./src/externfunc/get_next_line/get_next_line.c \
    ./src/utils1.c \
    ./src/split.c \
    ./src/calloc.c \
    ./src/maputils.c \
    ./src/map/createmap.c \
    ./src/map/checkmap.c \
    ./src/map/inicializemap.c \
    ./src/map/utilsreadmap.c \
    ./src/game/draw_map.c \
    ./src/game/draw_wall.c \
    ./src/game/free_game.c \
    ./src/game/game_rules.c

CC = cc  -Wall -Wextra -Werror main.c ${SRC}
LIB = minilibx-linux/libmlx_Linux.a

all:
	${CC} ${LIB} -lX11 -lXext	
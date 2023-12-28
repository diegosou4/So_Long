SRC = ./src/event/keyevent.c \
    ./src/utils/paint.c \
    ./src/utils/pixel.c \
    ./src/map/readmap.c \
    ./src/game/load.c \
    ./src/utils/sleep.c \
    ./src/event/animations.c \
    ./src/event/mouseevent.c \
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
    ./src/map/namemap.c \
    ./src/game/draw_map.c \
    ./src/game/draw_wall.c \
    ./src/game/free_game.c \
    ./src/game/draw_choise.c \
    ./src/game/game_rules.c

SRCBONUS =  ./src/utils/paint.c \
    ./src/utils/pixel.c \
    ./src/map/readmap.c \
    ./src/game/load.c \
    ./src/utils/sleep.c \
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
    ./src/map/namemap.c \
    ./src/game/draw_map.c \
    ./src/game/draw_wall.c \
    ./src/game/free_game.c \
    ./src/game/draw_choise.c \
    ./src/game/game_rules.c \
    ./bonus/animations.c \
    ./bonus/countmove.c \
    ./bonus/keyevent.c \
        ./bonus/utils.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = minilibx-linux/libmlx_Linux.a

all:
	${CC} main.c ${SRCBONUS}  ${LIB} -lX11 -lXext -o so_long


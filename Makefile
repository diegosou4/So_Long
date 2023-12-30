NAME = so_long
SRC = ./src/map/readmap.c \
    ./src/game/load_free.c \
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
    ./src/utils/paint.c \
    ./src/utils/pixel.c \
    ./src/event/keyevent.c \
    ./src/event/animations.c \
    ./src/game/game_rules.c \
    ./src/event/mouseevent.c
    
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFLAGS = -lXext -lX11
LIB = minilibx-linux/libmlx_Linux.a

all:
	${CC} -g main.c ${SRC}  ${LIB} ${LIBFLAGS} -o ${NAME}


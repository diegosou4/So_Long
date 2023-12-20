SRC = ./src/keyevent.c \
    ./src/paint.c \
    ./src/pixel.c \
    ./src/map/readmap.c \
    ./src/load.c \
    ./src/sleep.c \
    ./src/animations.c \
    ./src/utils.c \
    ./src/countmove.c \
    ./src/externfunc/get_next_line/get_next_line_utils.c \
    ./src/externfunc/get_next_line/get_next_line.c \
    ./src/utils1.c \
    ./src/split.c \
    ./src/calloc.c \
    ./src/maputils.c \
    ./src/createmap.c \
    ./src/checkmap.c \
    ./src/map/inicializemap.c \
    ./src/map/utilsreadmap.c

CC = cc  -g main.c ${SRC}
LIB = minilibx-linux/libmlx_Linux.a

all:
	${CC} ${LIB} -lX11 -lXext	
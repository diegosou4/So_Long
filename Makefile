
CC = cc -g main.c ./src/keyevent.c ./src/paint.c ./src/pixel.c ./src/load.c ./src/sleep.c ./src/animations.c ./src/utils.c ./src/countmove.c
LIB = minilibx_linux/libmlx_Linux.a \

all:
	${CC} ${LIB} -lX11 -lXext
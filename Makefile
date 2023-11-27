
CC = cc -g main.c ./src/keyevent.c ./src/paint.c ./src/pixel.c ./src/load.c
LIB = minilibx_linux/libmlx_Linux.a \

all:
	${CC} ${LIB} -lX11 -lXext
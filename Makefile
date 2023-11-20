
CC = cc main.c
LIB = minilibx_linux/libmlx_Linux.a \

all:
	${CC} ${LIB} -lX11 -lXext
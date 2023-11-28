SRC = ./src/keyevent.c \
	./src/paint.c \
	./src/pixel.c \
	./src/readmap.c \
	./src/load.c \
	./src/sleep.c \
	./src/animations.c \
	./src/utils.c \
	./src/countmove.c \
	./src/externfunc/get_next_line/get_next_line_utils.c \
	./src/externfunc/get_next_line/get_next_line.c

CC = cc -g main.c ${SRC}
LIB = minilibx_linux/libmlx_Linux.a

all:
	${CC} ${LIB} -lX11 -lXext	
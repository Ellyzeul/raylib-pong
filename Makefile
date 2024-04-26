CC=C:/raylib/w64devkit/bin/gcc.exe
CFLAGS=-lraylib -lgdi32 -lwinmm
GAMENAME=Pong

all:
	$(CC) -o $(GAMENAME).exe src/*.c main.c $(CFLAGS)

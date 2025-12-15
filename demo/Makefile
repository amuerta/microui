DEMO=-DDEMO_RAYLIB


all: build run

build: 
	cc -o main main.c -ggdb -lraylib -lX11 -lGL -lm $(DEMO)

run: 
	./main

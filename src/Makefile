# compile: make main
# clean: make clean
flag = -pedantic-errors -std=c++11

creenrenderer.o: screenrenderer.cpp screenrenderer.h
	g++ $(flag) -c screenrenderer.cpp

pacman.o: pacman.cpp pacman.h
	g++ $(flag) -c pacman.cpp

ghost.o: ghost.cpp ghost.h
	g++ $(flag) -c ghost.cpp

pellet.o: pellet.cpp pellet.h
	g++ $(flag) -c pellet.cpp

maze.o: maze.cpp maze.h
	g++ $(flag) -c maze.cpp

player.o: player.cpp player.h
	g++ $(flag) -c player.cpp

makemaze.o: makemaze.cpp makemaze.h
	g++ $(flag) -c makemaze.cpp

maingame.o: maingame.cpp maingame.h
	g++ $(flag) -c maingame.cpp

main.o: main.cpp 
	g++ $(flag) -c main.cpp

main: main.o screenrenderer.o maze.o pacman.o pellet.o ghost.o makemaze.o maingame.o player.o
	g++ $(flag) screenrenderer.o pacman.o ghost.o pellet.o maze.o player.o makemaze.o maingame.o main.o -o main -lncurses

clean:
	rm -f *.o main

.PHONY: clean
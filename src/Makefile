screenrenderer.o: screenrenderer.cpp screenrenderer.h
	g++ -c screenrenderer.cpp
pacman.o: pacman.cpp pacman.h
	g++ -c pacman.cpp
ghost.o: ghost.cpp ghost.h
	g++ -c ghost.cpp
pellet.o: pellet.cpp pellet.h
	g++ -c pellet.cpp
maze.o: maze.cpp maze.h
	g++ -c maze.cpp
player.o: player.cpp player.h
	g++ -c player.cpp
makemaze.o: makemaze.cpp makemaze.h
	g++ -c makemaze.cpp
maingame.o: maingame.cpp maingame.h
	g++ -c maingame.cpp
main.o: main.cpp 
	g++ -c main.cpp
main: main.o screenrenderer.o maze.o pacman.o pellet.o ghost.o makemaze.o maingame.o player.o
	g++ -pedantic-errors -std=c++11 screenrenderer.o pacman.o ghost.o pellet.o maze.o player.o makemaze.o maingame.o main.o -o main -lncurses
clean:
	rm -f *.o main

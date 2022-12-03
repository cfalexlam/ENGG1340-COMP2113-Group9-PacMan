# usage: go to the make directory
# compile: make game
# clean: make clean

src_dir = ../src/
flags = -pedantic-errors -std=c++11

ghost.o: $(src_dir)ghost.cpp $(src_dir)ghost.h
	g++ $(flags) -c $<

pacman.o: $(src_dir)pacman.cpp $(src_dir)pacman.h
	g++ $(flags) -c $<

pellet.o: $(src_dir)pellet.cpp $(src_dir)pellet.h
	g++ $(flags) -c $<

player.o: $(src_dir)player.cpp $(src_dir)player.h
	g++ $(flags) -c $<

maze.o: $(src_dir)maze.cpp $(src_dir)maze.h
	g++ $(flags) -c $<

screenrenderer.o: $(src_dir)screenrenderer.cpp $(src_dir)screenrenderer.h
	g++ $(flags) -c $<

maingame.o: $(src_dir)maingame.cpp $(src_dir)maingame.h
	g++ $(flags) -c $<

makemaze.o: $(src_dir)makemaze.cpp $(src_dir)makemaze.h
	g++ $(flags) -c $<

main.o: $(src_dir)main.cpp
	g++ $(flags) -c $<

main: ghost.o pacman.o pellet.o player.o maze.o screenrenderer.o maingame.o makemaze.o main.o
	g++ $(flags) $^ -o $@ -lncurses

clean:
	rm -rf *.o main

.PHONY: clean
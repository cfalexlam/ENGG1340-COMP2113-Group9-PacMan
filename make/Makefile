# usage: go to the make directory
# compile: make game
# clean: make clean

src_dir = ../src/
test_dir = ../test/
flag = -pedantic-errors -std=c++11

ghost.o: $(src_dir)ghost.cpp $(src_dir)ghost.h
	g++ $(flag) -c $<

main.o: $(src_dir)main.cpp $(src_dir)main.h
	g++ $(flag) -c $<

maze.o: $(src_dir)maze.cpp $(src_dir)maze.h
	g++ $(flag) -c $<

pacman.o: $(src_dir)pacman.cpp $(src_dir)pacman.h
	g++ $(flag) -c $<

pellet.o: $(src_dir)pellet.cpp $(src_dir)pellet.h
	g++ $(flag) -c $<

player.o: $(src_dir)player.cpp $(src_dir)player.h
	g++ $(flag) -c $<

screenrenderer.o: $(src_dir)screenrenderer.cpp $(src_dir)screenrenderer.h
	g++ $(flag) -c $<

test.o: $(test_dir)test.cpp
	g++ $(flag) -c $<

game: ghost.o main.o maze.o pacman.o pellet.o player.o screenrenderer.o test.o
	g++ $(flag) $^ -o $@ -lncurses

clean:
	rm -rf *.o game

.PHONY: clean
#include <iostream>
#include <vector>
#include <ncurses.h>
#include <unistd.h>
#include <fstream>
using namespace std;
void printmap(int l,int w, vector< vector<char> > map,int pointerRow, int pointerCol)
{
	for (int i=0;i<l;i++)
	{
		for (int j=0;j<w;j++)
			if (i==pointerRow and j==pointerCol)
				printw("%c<",map[i][j]);
			else
				printw("%c ",map[i][j]);
		printw("\n");
	}
}
int main(){
	vector<vector<char> > map;
	int length,width;
	int pointerRow=1,pointerCol=1;
	cout << "Length: ";
	cin >> length;
	cout << "width: ";
	cin >> width;
	for (int i=0;i<length;i++)
	{
		vector<char> temp;
		for (int j=0;j<width;j++)
			if (i==0 or i==length-1 or j==0 or j==width-1)
				temp.push_back('=');
			else
				temp.push_back('_');
		map.push_back(temp);
	}
	int input;
	initscr();
	noecho();
	keypad(stdscr,true);
	nodelay(stdscr,false);
	do
	{
		
		clear();
		printmap(length,width,map,pointerRow,pointerCol);
		printw("input: ");
		input = getch();
		printw("\n");
		switch(input){
			case KEY_UP:
				pointerRow = max(1,pointerRow-1);
				break;
			case KEY_DOWN:
				pointerRow = min(length-2,pointerRow+1);
				break;
			case KEY_LEFT:
				pointerCol = max(1,pointerCol-1);
				break;
			case KEY_RIGHT:
				pointerCol = min(width-2,pointerCol+1);
				break;
			case int('='):
				map[pointerRow][pointerCol] = '=';
				break;
			case int('G'):
				map[pointerRow][pointerCol] = 'G';
				break;
			case int('X'): case int('x'):
				map[pointerRow][pointerCol] = 'X';
				break;
			case KEY_BACKSPACE:
				map[pointerRow][pointerCol] = '_';
				break;
		
		}

	}
	while (input != 'q');
	echo();
	endwin();
    savemap(length, width, map);
	return 1;
}


void savemap(int l,int w, vector<vector<char> > map) {
    // check position of player
    ofstream fout;
    fout.open("../map/playermap.txt");

    if (fout.fail()){       
		cout << "Fail to create map" << endl;
		exit(1);     
	}

    for (int i=0; i<map.size(); i++) {
        for (int j=0; j<map[i].size(); j++) {
            if (map[i][j] == 'X') {
                fout << i << ' ' << j << endl;  
            }
        }
    }

    int NoGhost = 0;
    vector <vector <int> > ghosts;
    vector <int> ghost;
    for (int i=0; i<map.size(); i++) {
        for (int j=0; j<map[i].size(); j++) {
            if (map[i][j] == 'G') {
                NoGhost += 1;
                ghost.push_back(i);
                ghost.push_back(j);
                ghosts.push_back(ghost);
            }
        }
    }
    fout << NoGhost << endl;
}


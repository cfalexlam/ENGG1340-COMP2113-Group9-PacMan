#include <iostream>
#include <vector>
#include <ncurses.h>
#include <unistd.h>
#include <fstream>
#include "makemaze.h"
using namespace std;

void savemap(int l,int w, vector<vector<char> > map);


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
int makemaze(){
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
        printw("Rules:\n1. Use up down left right to control the place to insert character.\n");
        printw("2. Type G, X, O and = to insert ghosst, player, pellets and walls respectively.\n");
        printw("3. Do not insert more than 1 player.\n");
        printw("4. Press q to save and quit.");
        printw("\n");
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
            case int('G'):case int('g'):
                map[pointerRow][pointerCol] = 'G';
                break;
            case int('X'): case int('x'):
                map[pointerRow][pointerCol] = 'X';
                break;
            case int('O'):case int('o'):
                map[pointerRow][pointerCol] = 'O';
                break;
            case KEY_BACKSPACE:
                map[pointerRow][pointerCol] = '_';
                break;
        
        }

    }
    while (input != 'q' or !mapIsValid(map) );
    echo();
    endwin();
    //savemap(length, width, map);
    clear();
    return 1;
}
void fill(int row,int col,vector<vector<char>> mapcopy)
{

    if (row<0 || row>=mapcopy.size() || col < 0 || col>= mapcopy[0].size())
        return;
    if (mapcopy[row][col]=='=' or mapcopy[row][col]=='*')
        return;
    mapcopy[row][col] = '*';
    fill(row+1,col,mapcopy);
    fill(row-1,col,mapcopy);
    fill(row,col+1,mapcopy);
    fill(row,col-1,mapcopy);
    clear();
}
bool mapIsValid(vector<vector<char>> map)
{
    printw("test");
    getch();
    vector<vector<char>> mapcopy;
    for (int row = 0 ; row < map.size() ; row++)
        for (int col = 0 ; col < map[0].size() ; col++)
            if (map[row][col]!='=')
            {
                mapcopy = map;
                fill(row,col,mapcopy);
                printw("end");
                getch();
                goto BREAK;
            }
  
    BREAK:
    for (int row = 0 ; row < mapcopy.size() ; row++)
        for (int col = 0 ; col < mapcopy[0].size() ; col++)
            if (mapcopy[row][col]!='=' and mapcopy[row][col]!='*' )
            {
                return false;
            }
    return true;
}
void savemap(int l,int w, vector<vector<char> > map) {
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
    for (int i = 0; i < map.size(); i++) {
        for (int j=0; j<map[i].size(); j++) {
            if (map[i][j] == 'G') {
                vector <int> ghost;
                NoGhost += 1;

                ghost.push_back(i);
                ghost.push_back(j);

                ghosts.push_back(ghost);
            }
        }
    }
    fout << NoGhost << endl;

    for (int  i= 0; i < ghosts.size(); i++) {
        fout << ghosts[i][0] << ' ' << ghosts[i][1] << endl;
    }


    int NoPellet = 0;
    vector <vector <int> > pellets;
    for (int i = 0; i < map.size(); i++) {
        for (int j=0; j<map[i].size(); j++) {
            if (map[i][j] == 'O') {
                vector <int> pellet;
                NoPellet += 1;

                pellet.push_back(i);
                pellet.push_back(j);

                pellets.push_back(pellet);
            }
        }
    }
    fout << NoPellet << endl;

    for (int  i= 0; i < pellets.size(); i++) {
        fout << pellets[i][0] << ' ' << pellets[i][1] << endl;
    }

    for (int i=0; i<l; i++) {
        for (int j=0; j<w; j++) {
            if (map[i][j] == 'X' || map[i][j] == 'O' || map[i][j] == 'G' || map[i][j] == '_') 
                fout << '.';
            else
                fout << map[i][j];
        }
        fout << endl;
    }

    fout.close();
}
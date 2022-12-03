#include <iostream>
#include <vector>
#include <ncurses.h>
#include <unistd.h>
#include <fstream>
#include "makemaze.h"
using namespace std;

void makemaze(){
    int length,width;
    string filename;
    int pointerRow=1,pointerCol=1;

    cout << "filename: " ;
    cin >> filename;

    cout << "Length: ";
    cin >> length;

    cout << "width: ";
    cin >> width;

    vector< vector<char> > maze;
    for (int i=0;i<length;i++)
    {
        vector<char> temp;
        for (int j=0;j<width;j++)
            if (i==0 or i==length-1 or j==0 or j==width-1)
                temp.push_back('=');
            else
                temp.push_back('_');
        maze.push_back(temp);
    } 

    int input;
    initscr();
    noecho();
    keypad(stdscr,true);
    nodelay(stdscr,false);
    while(1)
    {
        clear();
        printw("Rules:\n1. Use up down left right to control the place to insert character.\n");
        printw("2. Type G, X, O and = to insert ghosst, player, pellets and walls respectively.\n");
        printw("3. Do not insert more than 1 player.\n");
        printw("4. Press q to save and quit.");
        printw("\n");
        printmap(maze,pointerRow,pointerCol);
        input = getch();

        switch(input)
        {
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
                maze[pointerRow][pointerCol] = '=';
                break;
            case int('G'):case int('g'):
                maze[pointerRow][pointerCol] = 'G';
                break;
            case int('X'): case int('x'):
                maze[pointerRow][pointerCol] = 'X';
                break;
            case int('O'):case int('o'):
                maze[pointerRow][pointerCol] = 'O';
                break;
            case KEY_BACKSPACE:
                maze[pointerRow][pointerCol] = '_';
                break;
            case 's': case 'S':
                if (mapIsConnected(maze))
                {
                    printw("valid\n");
                    goto SAVE;
                }
                else
                    printw("no valid\n");
                getch();
                break;

        }
    }
    
    SAVE:savemap(maze,filename);
    echo();
    endwin();
    clear();
    return;
}
        
void savemap(vector<vector<char> > maze,string filename) {

    ofstream fout("../map/"+filename+".txt");

    if (fout.fail()){       
        cout << "Fail to create map" << endl;
        exit(1);     
    }

    for (int i=0; i<maze.size(); i++)         //pacman
        for (int j=0; j<maze[i].size(); j++) 
            if (maze[i][j] == 'X') 
                fout << i << ' ' << j << endl;  

    fout << GetSymbolNumber(maze,'G') << endl; //ghost
    for (int i = 0; i < maze.size(); i++)    
        for (int j=0; j<maze[i].size(); j++) 
            if (maze[i][j] == 'G') 
                fout << i << ' ' << j << endl;

    fout << GetSymbolNumber(maze,'O') << endl; //pellet
    for (int i = 0; i < maze.size(); i++)  
        for (int j=0; j<maze[i].size(); j++) 
            if (maze[i][j] == 'O') 
                fout << i << ' ' << j << endl;

    for (int i=0; i<maze.size(); i++) {   //maze
        for (int j=0; j<maze[i].size(); j++) {
            if (maze[i][j] == 'X' || maze[i][j] == 'O' || maze[i][j] == 'G' || maze[i][j] == '_') 
                fout << '.';
            else
                fout << maze[i][j];
        }
        fout << endl;
    }

    fout.close();
}

void fill(int row,int col,vector<vector<char>> &maze)
{
    if (row<0 || row>=maze.size() || col < 0 || col>= maze[0].size())
        return;
    if (maze[row][col]=='=' or maze[row][col]=='*')
        return;
    maze[row][col] = '*';
    fill(row+1,col,maze);
    fill(row-1,col,maze);
    fill(row,col+1,maze);
    fill(row,col-1,maze);
}

bool mapIsConnected(vector<vector<char>> maze)
{
    for (int row = 0 ; row < maze.size() ; row++)      //check maze is connected
        for (int col = 0 ; col < maze[0].size() ; col++)
            if (maze[row][col]!='=')
            {
                fill(row,col,maze);
                goto BREAK;
            }
    BREAK:

    for (int row = 0 ; row < maze.size() ; row++)
        for (int col = 0 ; col < maze[0].size() ; col++)
            if (maze[row][col]!='=' and maze[row][col]!='*' )
                return false;
    return true;
}

void printmap(vector< vector<char> > map,int pointerRow, int pointerCol)
{
    for (int i=0;i<map.size();i++)
    {
        for (int j=0;j<map[0].size();j++)
            if (i==pointerRow and j==pointerCol)
                printw("%c<",map[i][j]);
            else
                printw("%c ",map[i][j]);
        printw("\n");
    }
}

int GetSymbolNumber(vector<vector<char>> maze,char symbol){
    int count=0;
    for(int i = 0; i < maze.size(); i++) 
        for (int j=0; j<maze[0].size(); j++) 
            if (maze[i][j] == symbol) 
                count+=1;
    return count;

}
    
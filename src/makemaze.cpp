#include <iostream>
#include <vector>
#include <ncurses.h>
#include <unistd.h>
#include <fstream>
#include "makemaze.h"
#include "screenrenderer.h"
using namespace std;

void makemaze(){
    int row,col;
    string filename;
    int pointerRow=1,pointerCol=1;

    cout << "Filename: ";
    cin >> filename;

    cout << "Length: ";
    cin >> row;

    cout << "Width: ";
    cin >> col;

    vector< vector<char> > maze;
    for (int i=0;i<row;i++)
    {
        vector<char> temp;
        for (int j=0;j<col;j++)
            if (i==0 or i==row-1 or j==0 or j==col-1)
                temp.push_back('=');
            else
                temp.push_back('_');
        maze.push_back(temp);
    } 

    int input;
    ScreenRenderer screen;
    screen.keyboardModeOpen();
    screen.keyboardModeWB();
    while(1)
    {
        clear();
        printw("Rules:\n1. Use arrow keys to navigate to insert characters.\n");
        printw("2. Type G, X, O and = to insert ghosts, player, pellets and walls respectively.\n");
        printw("3. Press backspace to delete the inserted characters \n");
        printw("4. Press n to insert a row and j to delete a row \n");
        printw("5. Press m to insert a column and k to delete a column \n");
        printw("6. Press s to save and quit \n");
        printw("7. Press q to quit \n");
        printmap(maze,pointerRow,pointerCol);
        input = getch();

        switch(input)
        {
            case KEY_UP:
                pointerRow = max(1,pointerRow-1);
                break;
            case KEY_DOWN:
                pointerRow = min(row-2,pointerRow+1);
                break;
            case KEY_LEFT:
                pointerCol = max(1,pointerCol-1);
                break;
            case KEY_RIGHT:
                pointerCol = min(col-2,pointerCol+1);
                break;
            case int('q'):case int('Q'):
                goto QUIT;
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
            case 'n':case 'N':
                addRow(maze);
                row+=1;
                break;
            case 'm':case 'M':
                addCol(maze);
                col+=1;
                break;
            case 'j':case 'J':
                if (row>3)
                {
                    if (pointerRow==row-2)
                        pointerRow--;
                    delRow(maze);
                    row-=1;
                    
                }
                break;
            case 'k':case 'K':
                if (col>3)
                {
                    if (pointerCol==col-2)
                        pointerCol--;
                    delCol(maze);
                    col-=1;
                    
                }
                break;
            case KEY_BACKSPACE:
                maze[pointerRow][pointerCol] = '_';
                break;

            case 's': case 'S':                 //save maze
                if (GetSymbolNumber(maze,'G')==0)
                {
                    printw("Require at least 1 ghost ");
                    getch();
                    break;
                }
                if (GetSymbolNumber(maze,'X')==0)
                {
                    printw("Require 1 pacman ");
                    getch();
                    break;
                }
                if (GetSymbolNumber(maze,'X')>1)
                {
                    printw("Require 1 pacman only ");
                    getch();
                    break;
                }
                if (!mazeIsConnected(maze))
                {
                    printw("The maze is not connected");
                    getch();
                    break;
                }
                printw("Maze saved");
                getch();
                goto SAVE;
                break;

        }
    }
    
    SAVE:savemap(maze,filename);
    QUIT:screen.keyboardModeClose();
    return;
}
        
void savemap(vector<vector<char> > maze,string filename) {

    ofstream fout("../map/"+filename+".txt");

    if (fout.fail()){       
        cout << "Fail to create map" << endl;
        exit(1);     
    }

    for (int i=0; i<maze.size(); i++)         //write in pacman
        for (int j=0; j<maze[i].size(); j++) 
            if (maze[i][j] == 'X') 
                fout << i << ' ' << j << endl;  

    fout << GetSymbolNumber(maze,'G') << endl; //write in ghost
    for (int i = 0; i < maze.size(); i++)    
        for (int j=0; j<maze[i].size(); j++) 
            if (maze[i][j] == 'G') 
                fout << i << ' ' << j << endl;

    fout << GetSymbolNumber(maze,'O') << endl; //write in pellet
    for (int i = 0; i < maze.size(); i++)  
        for (int j=0; j<maze[i].size(); j++) 
            if (maze[i][j] == 'O') 
                fout << i << ' ' << j << endl;

    for (int i=0; i<maze.size(); i++) {   //write in maze
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

bool mazeIsConnected(vector<vector<char>> maze)
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
void addRow(vector<vector<char> > &maze){
    vector<char> temp = maze[0];
    for (int i=0;i<maze[0].size();i++)
        if (i==0 or i==maze[0].size()-1)
            maze[maze.size()-1][i]='=';
        else
            maze[maze.size()-1][i]='_';
    maze.push_back(temp);
}

void delRow(vector<vector<char> > &maze){
    vector<char> temp = maze[0];
    maze.pop_back();
    maze.pop_back();
    maze.push_back(temp);
}

void delCol(vector<vector<char> > &maze){
    for (int i=0;i<maze.size();i++)
    {
        maze[i].pop_back();
        maze[i].pop_back();
        maze[i].push_back('=');
    }
    
}

void addCol(vector<vector<char> > &maze){
    for (int i=0;i<maze.size();i++)
        if (i==0 or i==maze.size()-1)
            maze[i][maze[i].size()-1]='=';
        else
            maze[i][maze[i].size()-1]='_';
    for (int i=0;i<maze.size();i++)
        maze[i].push_back('=');
}
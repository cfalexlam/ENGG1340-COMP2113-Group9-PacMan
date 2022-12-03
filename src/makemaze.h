#ifndef MAKEMAZE_H
#define MAKEMAZE_H
#include <vector>
using namespace std;

void makemaze();
void savemap(vector<vector<char> > maze,string filename);
void printmap(vector< vector<char> > maze,int pointerRow, int pointerCol);
void fill(int row,int col,vector<vector<char>> &maze);
bool mapIsConnected(vector<vector<char>> maze);
int GetSymbolNumber(vector<vector<char>> maze,char symbol);
#endif
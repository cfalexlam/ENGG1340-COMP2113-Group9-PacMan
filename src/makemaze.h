#ifndef MAKEMAZE_H
#define MAKEMAZE_H

#include <vector>
#include <string>

using namespace std;

void makemaze();
void addRow(vector < vector < char > > & maze);
void addCol(vector < vector < char > > & maze);
void delRow(vector < vector < char > > & maze);
void delCol(vector < vector < char > > & maze);
void savemap(vector < vector < char > > maze, string filename);
void printmap(vector < vector < char > > maze, int pointerRow, int pointerCol);
void fill(int row, int col, vector < vector < char > > & maze);
bool mazeIsConnected(vector < vector < char > > maze);
int GetSymbolNumber(vector < vector < char > > maze, char symbol);
#endif
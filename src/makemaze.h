#ifndef MAKEMAZE_H
#define MAKEMAZE_H
#include <vector>
using namespace std;

void savemap(int l,int w, vector<vector<char> > map);
void printmap(int l,int w, vector< vector<char> > map,int pointerRow, int pointerCol);
int makemaze();
void fill(int row,int col,vector<vector<char>> map);
bool mapIsValid(vector<vector<char>> map);
#endif
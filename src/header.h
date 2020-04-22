#ifndef BOARD_H
#define BOARD_H

#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

void Chessplace(char pole[][9]);
void move_p(char pole[][9]);
int move_check(int x1, int x2, int y1, int y2, char pole[][9]);

#endif

#include "header.h"
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int move_check(int x1, int x2, int y1, int y2, char pole[][9], string step)
{
    int flag = 0;
    if ((x1 == x2) && (x1 == y2)) {
        cout << "\nERROR\n";
        return 0;
    }
    switch (pole[x1][y1]) {
    case ' ':
        cout << "\nERROR\n";
        return 0;

    case 'P':
        if ((y1 == y2) && (x1 - x2 == 1) && (pole[x2][y2] == ' '))
            flag = 1;
        if ((y1 == y2) && (x1 - x2 == 2) && (x1 == 6)
            && (pole[x2][y2] == ' ')) {
            if (pole[x2 + 1][y2] == ' ') {
                flag = 1;
            } else {
                cout << "\nERROR\n";
                return 0;
            }
        }
        if ((x1 - x2 == 1) && (pole[x2][x2] != ' ')
            && ((y1 - y2 == 1) || (y2 - y1 == 1)))
            flag = 1;
        break;

    case 'p':
        if ((y1 == y2) && (x2 - x1 == 1) && (pole[x2][y2] == ' '))
            flag = 1;
        if ((y1 == y2) && (x2 - x1 == 2) && (x1 == 1)
            && (pole[x2][y2] == ' ')) {
            if (pole[x2 - 1][y2] == ' ') {
                flag = 1;
            } else {
                cout << "\nERROR\n";
                return 0;
            }
        }
        if ((x2 - x1 == 1) && (pole[x2][y2] != ' ')
            && ((y2 - y1 == 1) || (y1 - y2 == 1)))
            flag = 1;
        break;

    default:
        flag = 1;
        break;
    }
    if (pole[x1][y1] != 'P' && pole[x1][y1] != 'p') {
        cout << "Error! Try again" << endl;
        return 0;
    }

    if (step[2] == '-') {
        if (pole[x2][y2] == ' ') {
        } else {
            cout << "Incorrect" << endl;
            return 0;
        }
    } else if (step[2] == 'x') {
        if (pole[x2][y2] != ' ') {
            flag = 1;
            return flag;
        } else {
            cout << "Incorrect" << endl;
            return 0;
        }
    }

    return flag;
}

void move_p(char pole[][9])
{
    int x1 = 9, x2 = 9, y1 = 0, y2 = 0;
    string step;
    cout << endl << "Your move: ";
    cin >> step;
    if (step == "exit") {
        cout << "Exit the programm";
        exit(0);
    }
    if (step.length() != 5) {
        cout << "\nERROR\n";
        return;
    }
    switch (step[0]) {
    case 'a':
        y1 = 1;
        break;
    case 'b':
        y1 = 2;
        break;
    case 'c':
        y1 = 3;
        break;
    case 'd':
        y1 = 4;
        break;
    case 'e':
        y1 = 5;
        break;
    case 'f':
        y1 = 6;
        break;
    case 'g':
        y1 = 7;
        break;
    case 'h':
        y1 = 8;
        break;
    default:
        cout << "\nERROR\n";
        return;
    }
    switch (step[1]) {
    case '1':
        x1 = 7;
        break;
    case '2':
        x1 = 6;
        break;
    case '3':
        x1 = 5;
        break;
    case '4':
        x1 = 4;
        break;
    case '5':
        x1 = 3;
        break;
    case '6':
        x1 = 2;
        break;
    case '7':
        x1 = 1;
        break;
        x1 = 0;
        break;
    default:
        cout << "\nERROR\n";
        return;
    }

    switch (step[3]) {
    case 'a':
        y2 = 1;
        break;
    case 'b':
        y2 = 2;
        break;
    case 'c':
        y2 = 3;
        break;
    case 'd':
        y2 = 4;
        break;
    case 'e':
        y2 = 5;
        break;
    case 'f':
        y2 = 6;
        break;
    case 'g':
        y2 = 7;
        break;
    case 'h':
        y2 = 8;
        break;
    default:
        cout << "\nERROR\n";
        return;
    }
    switch (step[4]) {
    case '1':
        x2 = 7;
        break;
    case '2':
        x2 = 6;
        break;
    case '3':
        x2 = 5;
        break;
    case '4':
        x2 = 4;
        break;
    case '5':
        x2 = 3;
        break;
    case '6':
        x2 = 2;
        break;
    case '7':
        x2 = 1;
        break;
    case '8':
        x2 = 0;
        break;
    default:
        cout << "\nERROR\n";
        return;
    }

    if (move_check(x1, x2, y1, y2, pole, step)) {
        if (pole[x1][y1] == 'P') {
            pole[x2][y2] = 'P';
            pole[x1][y1] = ' ';
        } else if (pole[x1][y1] == 'p') {
            pole[x2][y2] = 'p';
            pole[x1][y1] = ' ';
        }
    }
    cout << endl;
    cout << endl;
}

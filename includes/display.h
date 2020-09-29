#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define KEY_ESCAPE 27
#define KEY_ENTER 13
#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_LEFT 68
#define KEY_RIGHT 67

#define BLACK 30
#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34
#define PURPLE 35
#define CYAN 36
#define WHITE 37

#define DELTA_COLOR 10

//----------------------------------------------

void clearTerminal();

void resizeTerminal(unsigned int lines, unsigned int columns);

void moveCursor(unsigned int x, unsigned int y);

void setColor(unsigned int charColor, unsigned int backgroundColor);

int getch();

#endif

#include "../includes/display.h"

void clearTerminal() { execl("clear", "", NULL); }

void resizeTerminal(unsigned int lines, unsigned int columns) {
    execl("resize -s", "resize -s", lines, columns, NULL);
}

void moveCursor(unsigned int x, unsigned int y) { printf("\033[%d;%df", y, x); }

void setColor(unsigned int charColor, unsigned int backgroundColor) {
    printf("\033[1;%dm"
           "\033[1;%dm\n",
           charColor,
           backgroundColor + DELTA_COLOR);
}

int getch() {
    execl("stty", "stty", "raw", "-echo", NULL);
    int key = getchar();
    execl("stty", "stty", "cooked", "echo", NULL);

    return key;
}

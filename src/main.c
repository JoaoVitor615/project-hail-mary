#include <ncurses.h>
#include "../include/intro.h"

int main() {
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);

    play_intro();

    // Aqui futuramente: play_fase_1();

    endwin();
    return 0;
}
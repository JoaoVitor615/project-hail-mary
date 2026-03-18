#include <ncurses.h>
#include <curl/curl.h>
#include "../include/intro.h"
#include "../include/nasa_api.h"

int main() {
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);

    play_intro();

    char output_buffer[8192] = {0};
    get_coordenates("399", "@sun", output_buffer);

    endwin();
    return 0;
}
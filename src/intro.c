#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "constants.h"

void typewriter(int y, int x, const char* text, int speed_ms) {
    for (int i = 0; text[i] != '\0'; i++) {
        mvaddch(y, x + i, text[i]);
        refresh();
        usleep(speed_ms * 1000);
    }
}

void play_intro() {
    int screen_y, screen_x;
    getmaxyx(stdscr, screen_y, screen_x);

    start_color();
    init_pair(COLOR_PAIR_PRIMARY, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(COLOR_PAIR_PRIMARY) | A_BOLD);

    // Centralized title
    int start_y = (screen_y / 2) - 2;
    int title_x = (screen_x - strlen(TITLE_TEXT)) / 2;
    typewriter(start_y, title_x, TITLE_TEXT, TYPE_SPEED_SLOW);

    usleep(WAIT_TIME_MS);

    // Today's date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char date_str[20];
    sprintf(date_str, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    
    int date_x = (screen_x - strlen(date_str)) / 2;
    typewriter(start_y + 1, date_x, date_str, TYPE_SPEED_FAST);

    // Author
    int author_x = (screen_x - strlen(AUTHOR_TEXT)) / 2;
    typewriter(start_y + 3, author_x, AUTHOR_TEXT, TYPE_SPEED_FAST);

    attroff(COLOR_PAIR(COLOR_PAIR_PRIMARY));
    
    // Start prompt
    int prompt_x = (screen_x - strlen(START_PROMPT)) / 2;
    mvprintw(screen_y - 2, prompt_x, START_PROMPT);
    refresh();
    getch();
}
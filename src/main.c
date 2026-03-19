#include <ncurses.h>
#include <curl/curl.h>
#include "../include/intro.h"
#include "../include/nasa_api.h"
#include "constants.h"

int main() {
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);

    play_intro();

    endwin();

    Vector2D solarSystemCoords[5] = { 0 };

    solarSystemCoords[0] = get_coordenates(ID_SUN, ID_SUN);
    solarSystemCoords[1] = get_coordenates(ID_MERCURY, ID_SUN);
    solarSystemCoords[2] = get_coordenates(ID_VENUS, ID_SUN);
    solarSystemCoords[3] = get_coordenates(ID_EARTH, ID_SUN);
    solarSystemCoords[4] = get_coordenates(ID_MARS, ID_SUN);

    for (int i = 0; i < 5; i++) {
        printf("Planet %d - X: %f, Y: %f\n", i, solarSystemCoords[i].x, solarSystemCoords[i].y);
    }

    return 0;
}
#ifndef CONSTANTS_H
#define CONSTANTS_H

// Time Configuration (ms)
#define TYPE_SPEED_SLOW 100
#define TYPE_SPEED_FAST 50
#define WAIT_TIME_MS    1500000 // ms for usleep

// Intro Texts
#define TITLE_TEXT     "PROJECT HAIL MARY"
#define AUTHOR_TEXT    "Created By JoaoVitor615"
#define START_PROMPT   "Press any key to start..."

// Color Pairs
#define COLOR_PAIR_PRIMARY 1

// NASA's JPL Horizons IDs
#define ID_SUN     "@sun"
#define ID_MERCURY "199"
#define ID_VENUS   "299"
#define ID_EARTH   "399"
#define ID_MARS    "499"

#define RESPONSE_START_COORDINATES "$$SOE"

// BASE API URL for NASA's JPL Horizons
#define HORIZONS_API_URL "https://ssd.jpl.nasa.gov/api/horizons.api"

#endif
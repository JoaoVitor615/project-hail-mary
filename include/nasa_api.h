#ifndef NASA_API_H
#define NASA_API_H

typedef struct {
    double x;
    double y;
} Vector2D;

Vector2D get_coordenates(const char* planet_id, const char* center);

#endif
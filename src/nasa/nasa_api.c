#include "constants.h"
#include "nasa_api.h"
#include <curl/curl.h>
#include <string.h>

Vector2D parse_coordinates(const char* data);

size_t write_data(void *ptr, size_t size, size_t nmemb, void *data){
    size_t realsize = size * nmemb;
    strcat(data, (char *)ptr);
    return realsize;
};

Vector2D get_coordenates(const char* planet_id, const char* center) {

    CURL *curl = curl_easy_init();
    char output_buffer[8192] = {0};
    Vector2D coords = {0.0, 0.0};

    if(curl) {
        
        char url[512];
        sprintf(url, "%s?format=text&COMMAND='%s'&OBJ_DATA='NO'&MAKE_EPHEM='YES'&EPHEM_TYPE='VECTORS'&CENTER='%s'&START_TIME='2026-03-16'&STOP_TIME='2026-03-17'&STEP_SIZE='1d'&OUT_UNITS='AU-D'&VEC_TABLE=3", HORIZONS_API_URL, planet_id, center);

        CURLcode result;

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, output_buffer);

        result = curl_easy_perform(curl);
        if(result != CURLE_OK) {
            fprintf(stderr, "Request failed: %s\n", curl_easy_strerror(result));
        }

        coords = parse_coordinates(output_buffer);
    }

    return coords;


}

Vector2D parse_coordinates(const char* data) {
    Vector2D coords = {0.0, 0.0};

    const char* start_str = strstr(data, RESPONSE_START_COORDINATES);
    if (!start_str) return coords;

    const char* x_str = strstr(data, "X =");
    if (!x_str) return coords;

    if(sscanf(x_str, "X =%lf Y =%lf", &coords.x, &coords.y) != 2) {
        return coords;
    };

    return coords;
}
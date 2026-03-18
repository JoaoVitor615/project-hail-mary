#include "constants.h"
#include <curl/curl.h>
#include <string.h>

size_t write_data(void *ptr, size_t size, size_t nmemb, void *data){
    size_t realsize = size * nmemb;
    strcat(data, (char *)ptr);
    return realsize;
};

void get_coordenates(const char* planet_id, const char* center, char* output_buffer) {

    CURL *curl = curl_easy_init();

    if(curl) {
        
        char url[512];
        sprintf(url, "%s?format=text&COMMAND='%s'&OBJ_DATA='NO'&MAKE_EPHEM='YES'&EPHEM_TYPE='VECTORS'&CENTER='%s'&START_TIME='2026-03-16'&STOP_TIME='2026-03-17'&STEP_SIZE='1d'&OUT_UNITS='AU-D'&VEC_TABLE=3", HORIZONS_API_URL, planet_id, center);

        printf("Requesting data from NASA API...\nURL: %s\n", url);
        CURLcode result;

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, output_buffer);

        result = curl_easy_perform(curl);
        if(result != CURLE_OK) {
            fprintf(stderr, "Request failed: %s\n", curl_easy_strerror(result));
        }

        printf("Response:\n%s\n", output_buffer);
    }

}
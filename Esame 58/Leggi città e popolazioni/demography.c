#include "demography.h"

struct city* read_cities(const char* filename, uint32_t* n) {
    FILE* f = fopen(filename, "rb");
    if (f == NULL) {
        return NULL;
    }

    fread(n, sizeof(uint32_t), 1, f); //memorizzo il numero di elementi nel file nella variabile puntata da n

    struct city* cities = malloc(*n * sizeof(struct city));
    if (cities == NULL) {
        fclose(f);
        return NULL;
    }

    for (uint32_t i = 0; i < *n; i++) {
        char cityname[256]; //aumentato la dimensione dell'array per includere il carattere terminatore '\0'
        size_t bytesread = fread(cityname, sizeof(char), 255, f);
        if (bytesread == 0) {
            break;
        }
        cityname[bytesread] = '\0'; //aggiunto il carattere terminatore al nome della città

        cities[i].name = malloc(bytesread + 1); //alloco memoria per il campo name
        if (cities[i].name == NULL) {
            break;
        }
        strncpy(cities[i].name, cityname, bytesread + 1); //utilizzo strncpy per copiare il nome della città

        uint32_t citypop = 0;
        size_t bytespopread = fread(&citypop, sizeof(uint32_t), 1, f);
        if (bytespopread != 1) {
            break;
        }
        cities[i].population = citypop;
    }

    fclose(f);
    return cities;
}
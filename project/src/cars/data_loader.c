#include "car_db_functions.h"


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int read_data(car_db *db, const char *file_name) {
    FILE *fp;
    if ((fp = fopen(file_name, "r")) == NULL) {
        printf("Cannot open file.\n");
        return -1;
    }

    db->size = 0;
    car c;
    char *token;
    char *buf;
    size_t n;
    while (getline(&buf, &n, fp) != -1) {
        token = strtok(buf, DELIM);

        c.model = token;
        token = strtok(NULL, DELIM);
        c.body_shape = token;
        token = strtok(NULL, DELIM);
        sscanf(token, "%zu", &(c.enginev));
        token = strtok(NULL, DELIM);
        sscanf(token, "%zu", &(c.speed));
        token = strtok(NULL, DELIM);
        sscanf(token, "%zu", &(c.fuel_consum));
        _append(db, c);
    }

    _calclate_normalization(db);

    fclose(fp);
    if (buf != NULL)
        free(buf);
    return 0;
}

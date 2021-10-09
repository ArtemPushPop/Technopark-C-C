#ifndef CARS_FUNCTIONS
#define CARS_FUNCTIONS

#include <glob.h>

typedef struct car {
    size_t enginev;
    size_t speed;
    size_t fuel_consum;
    char *body_shape;
    char *model;
} car;


typedef struct car_db {
    car *car_items;
    double ozh_disp[2][3];   //нужно для правильного нахождения ближайшей машины.
    size_t size;
} car_db;


int read_data(car_db *, const char *);

size_t find_nearest(const car_db *, const car);

int write_data(car_db *, const char *);

int init(car_db *);

int print_car(const car);

int add(struct car_db *, const car, const size_t);

int add_prompt(car_db *);

int append(car_db *, const car);

int delete(car_db *, const size_t);

int clear(car_db *);

int print_all(const car_db);

#endif //CARS_FUNCTIONS


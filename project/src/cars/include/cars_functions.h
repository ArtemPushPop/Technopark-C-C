#pragma once


#include "car_db_functions.h"


#include <glob.h>


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


#include "car_db_functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *available_models[] = {"Nissan", "Bugatty", "Mercedes", "BMW", "Pejo", "Audi"};
size_t models_number = 6;
char *body_shapes[] = {"hatch back", "sports car", "limousine", "van", "pick-up truck", "four-door sedan"};
size_t body_number = 6;


/*
в данном файле представлены функции, реализующие пользовательский интерфейс для работы с
данной библиотекой. Они будут использоваться для валидации правильности введенных данных.
 */


int init(car_db *db) {
    db->size = 0;
    return 0;
}


int print_car(const car c) {
    printf("----%s---\n", c.model);
    printf("Мощность двигателя : %zu \n", c.enginev);
    printf("Скорость           : %zu \n", c.speed);
    printf("Потребление топлива: %zu \n", c.fuel_consum);
    printf("Форма кузова       : %s\n", c.body_shape);
    return 0;
}

int print_all(const car_db bd) {
    for (int i = 0; i < bd.size; i++)
        print_car(bd.car_items[i]);
    return 0;
}


int add(struct car_db *db, const car c, const size_t pos) {
    //выполнение какой либо валидации, в нашем случае ничего подобного сделать нельзя.
    //если бы можно было проверить строки на правильность внутри структуры, то разместить
    //данный код следует здесь.
    if (pos > db->size)
        return -1;  //неправильный параметр позиции
    _add(db, c, pos);
    _calclate_normalization(db);
    return 0;
}


int _prompt_string(char **str, size_t type) {
    char str_t[11];
    size_t size;
    char **check;
    if (type == MODEL_PROMPT) {
        strcpy(str_t, "model");
        check = available_models;
        size = models_number;
    } else if (type == BACK_PROMPT) {
        strcpy(str_t, "body shape");
        check = body_shapes;
        size = body_number;
    }


    size_t scanned = 0;
    char buffer[200];
    while (scanned != 1) {
        printf("type in %s: ", str_t);
        if (scanf("%s", buffer) != 1)
            printf("INPUT ERROR, TRY AGAIN\n");
        else {
            int i = 0;
            while ((i < size) && (strcmp(buffer, check[i]) != 0))
                i++;
            if (i == size)
                printf("wrong %s, message admin if your lovely %s is not in our pool!\n"
                       "for now insert valid %s.\n", str_t, str_t, str_t);
            else {
                scanned = 1;
                *str = (char *) malloc(sizeof(char) * strlen(buffer));
                strcpy(*str, buffer);
            }
        }
    }
    return scanned;
}


int _prompt_int(size_t *i) {
    while (scanf("%zu", i) != 1)
        printf("ERROR, try again\n");
    return 0;
}


int add_prompt(car_db *db) {
    car c;
    _prompt_string(&(c.model), MODEL_PROMPT);
    _prompt_string(&(c.body_shape), BACK_PROMPT);

    printf("enter car speed: ");
    _prompt_int(&(c.speed));

    printf("enter fuel consumption: ");
    _prompt_int(&(c.fuel_consum));

    printf("enter engine power: ");
    _prompt_int(&(c.enginev));

    _append(db, c);
    _calclate_normalization(db);
    free(c.body_shape);
    free(c.model);
    return 0;
}

int append(car_db *db, const car c) {
    //possible validation
    _append(db, c);
    _calclate_normalization(db);
    return 0;

}


int delete(car_db *db, const size_t pos) {
    if (pos >= db->size)
        return -1;  //неправильный параметр позиции
    _delete(db, pos);
    _calclate_normalization(db);
    return 0;
}


int clear(car_db *db) {
    char c;
    printf("proceed clearing? Y/N : ");
    while ((scanf("%c", &c) != 1) && ((c != 'Y') || (c != 'N'))) {
        printf("WRONG ANSWER\n");
        printf("proceed clearing? Y/N : ");
    }
    if (c == 'N') {
        printf("No clearing done.\n");
        return 0;
    } else {
        printf("Making clear.\n");
        _clear(db);
        return 0;
    }
}


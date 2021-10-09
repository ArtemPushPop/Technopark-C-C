#include "cars_functions.h"
#include "main.h"


int main(){
    car_db db;
    init(&db);
    read_data(&db, DATA_FILE);

    car c;
    add_prompt(&db, stdin);
    c = db.car_items[db.size - 1];
    printf("\n\n\n");

    print_all(db);
    print_car(db.car_items[find_nearest(db, c)]);
}

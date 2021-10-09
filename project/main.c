#include "cars_functions.h"
#include "main.h"


int main(){
    car_db db;
    init(&db);
    read_data(&db, "../data/data.txt");
    clear(&db);

    print_all(db);
}

#include "car_db_functions.h"


#include <string.h>


size_t find_nearest(const car_db * db, const car c){
    if (db->size == 0)
        return -1; //невозможно выполнить поиск в пустом массиве

    double metric_lowest, metric;
    size_t nearest = 0;
    metric_lowest = (double)(c.enginev - db->car_items[0].enginev) / db->ozh_disp[1][0] +\
                    (double)(c.speed - db->car_items[0].speed) / db->ozh_disp[1][1] +\
                    (double)(c.fuel_consum - db->car_items[0].fuel_consum) / db->ozh_disp[1][2] +\
                    (double)strcmp(c.body_shape, db->car_items[0].body_shape);
    for (int i = 1; i < db->size; i++){
        metric    = (double)(c.enginev - db->car_items[0].enginev) / db->ozh_disp[1][0] +\
                    (double)(c.speed - db->car_items[0].speed) / db->ozh_disp[1][1] +\
                    (double)(c.fuel_consum - db->car_items[0].fuel_consum) / db->ozh_disp[1][2] +\
                    (double)strcmp(c.body_shape, db->car_items[0].body_shape);
        if (metric < metric_lowest) {
            nearest = i;
            metric_lowest = metric;
        }
    }
    return nearest;
}

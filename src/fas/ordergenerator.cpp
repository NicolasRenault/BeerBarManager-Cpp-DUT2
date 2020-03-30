#include "header/ordergenerator.h"
#include <iostream>
#include <QRandomGenerator>
#include "header/order.h"

void generateOrder(Order & order) {
    int time = QRandomGenerator::global()->bounded(8, 16);

    Beer *beer = new Beer("lofle", 0, 0, 0, "", "", new Recipe(5));
    order.setBeer(beer);
    order.setTime(time * 60);
    order.setMaxtime(time * 60);
}

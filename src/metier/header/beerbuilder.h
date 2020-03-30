#ifndef BEERBUILDER_H
#define BEERBUILDER_H

#include <QObject>
#include "metier/header/beer.h"

Beer *buildBeer(QString hopIng, QString maltyIng, int preparationTime, QString name);


#endif // BEERBUILDER_H


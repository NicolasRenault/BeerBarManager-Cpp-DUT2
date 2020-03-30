#ifndef RANDOMEVENTFACTORY_H
#define RANDOMEVENTFACTORY_H

#include <QObject>

#include <event/header/event.h>
#include <event/header/blaze.h>
#include <event/header/brokenequipement.h>
#include <event/header/competition.h>
#include <event/header/customer.h>
#include <event/header/deliveryproblem.h>
#include <event/header/fight.h>
#include <event/header/fine.h>
#include <event/header/inspectorate.h>
#include <event/header/nothing.h>
#include <event/header/reception.h>
#include <event/header/strike.h>
#include <event/header/tax.h>
#include <event/header/unveilling.h>
#include <event/header/weather.h>


class RandomEventFactory : public QObject
{
    Q_OBJECT

private:

public:
    static Event* createEvent(int event);
    static int randTime(int hour);

signals:

public slots:
};

#endif // RANDOMEVENTFACTORY_H

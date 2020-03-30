#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <QObject>
#include "eventlauncher.h"
#include "randomeventfactory.h"
using namespace std;

class EventManager : public QObject
{
    Q_OBJECT


private:
    static const int NBEVENT = 50;
    array<EventLauncher*, NBEVENT> listEvent;
    enum event  {
        NOTHING,
        BLAZE,
        BROKENEQUIPEMENT,
        COMPETITION,
        CUSTOMER,
        DELIVERYPROBLEM,
        FIGHT,
        FINE,
        INSPECTORATE,
        RECEPTION,
        STRIKE,
        TAX,
        UNVEILLING,
        WEATHER
    };


public:
    EventManager();
    void launchEvent(int hour, int minute);
    EventLauncher* getRandomEvent();
    void clearList();
    void fillList(Bar* bar);
    void sortList();

signals:

public slots:

};

#endif // EVENTMANAGER_H

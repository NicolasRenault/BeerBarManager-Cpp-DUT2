#ifndef EVENTLAUNCHER_H
#define EVENTLAUNCHER_H

#include <QObject>

#include <event/header/event.h>

class EventLauncher : public QObject
{
    Q_OBJECT
public:
    EventLauncher(int hour, int minutes, Event* event);
    int getHour();
    int getMinutes();
    void launch();
    bool isSmaller(EventLauncher* biggerEventLauncher);
    Event* getEvent();

signals:

public slots:

private:
    int hour;
    int minutes;
    Event* event;
};

#endif // EVENTLAUNCHER_H

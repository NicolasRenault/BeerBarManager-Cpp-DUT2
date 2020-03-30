#include "header/eventlauncher.h"

EventLauncher::EventLauncher(int hour, int minutes, Event *event) : hour(hour), minutes(minutes), event(event)
{

}

int EventLauncher::getHour()
{
    return hour;
}

int EventLauncher::getMinutes()
{
    return minutes;
}

void EventLauncher::launch()
{
    event->lauchEvent();
}

bool EventLauncher::isSmaller(EventLauncher *biggerEventLauncher)
{
    if(hour < biggerEventLauncher->getHour() &&
            minutes < biggerEventLauncher->getMinutes())
        return true;
    else return false;
}

Event *EventLauncher::getEvent()
{
    return event;
}


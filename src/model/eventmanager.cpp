#include "header/eventmanager.h"
#include <model/header/eventmanager.h>

EventManager::EventManager()
{

}

void EventManager::launchEvent(int hour, int minute)
{
    if (listEvent.front()->getHour()==hour &&
            listEvent.front()->getMinutes()==minute){

        listEvent.front()->launch();
        listEvent.front() = new EventLauncher(999, 999, RandomEventFactory::createEvent(event::NOTHING));
        sortList();
    }
}

EventLauncher* EventManager::getRandomEvent()
{
    int rand1 = rand() % 100 + 1;
    Event* event;
    
    switch (rand1) {
        case 1 :
        case 2 :
            event = RandomEventFactory::createEvent(event::BLAZE);
            break;
        case 3 :
        case 4 :
            event = RandomEventFactory::createEvent(event::COMPETITION);
            break;
        case 5 :
        case 6 :
        case 7 :
        case 8 :
        case 9 :
            event = RandomEventFactory::createEvent(event::BROKENEQUIPEMENT);
        break;
        case 10 ... 14 :
            event = RandomEventFactory::createEvent(event::FINE);
        break;
        case 15 ... 19 :
            event = RandomEventFactory::createEvent(event::INSPECTORATE);
        break;
        case 20 ... 24 :
            event = RandomEventFactory::createEvent(event::STRIKE);
        break;
        case 25 ... 33 :
            event = RandomEventFactory::createEvent(event::DELIVERYPROBLEM);
        break;
        case 34 ... 42 :
            event = RandomEventFactory::createEvent(event::RECEPTION);
        break;
        case 43 ... 51 :
            event = RandomEventFactory::createEvent(event::TAX);
        break;
        case 52 ... 62 :
            event = RandomEventFactory::createEvent(event::FIGHT);
        break;
        case 63 ... 73 :
            event = RandomEventFactory::createEvent(event::WEATHER);
        break;
        case 74 ... 100 :
            event = RandomEventFactory::createEvent(event::CUSTOMER);
        break;
        default :
            event = RandomEventFactory::createEvent(event::NOTHING);
        break;
            
    }
    int hour = rand() % 24 + 8;
    int minutes = rand() % 60;
    EventLauncher* eventLauncher = new EventLauncher(hour, minutes, event);
    return eventLauncher;
}

void EventManager::clearList()
{
    listEvent = array<EventLauncher *, NBEVENT>();
}

void EventManager::fillList(Bar* bar)
{
    for (int i = 0; i <= NBEVENT; ++i) {
        listEvent[i] = getRandomEvent();
        listEvent[i]->getEvent()->setBar(bar);
    }
    sortList();
}

void EventManager::sortList()
{
    EventLauncher* min = listEvent[0];
    EventLauncher* tmp;
    for (int i = 0; i <= NBEVENT; ++i) {
        for (int j = 0; j < NBEVENT; ++j) {
            if(listEvent[j]->isSmaller(min)) {
                min=listEvent[j];
            }
        }
        tmp = listEvent[i];
        listEvent[i] = min;
        min = tmp;
    }
}



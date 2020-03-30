#include "header/randomeventfactory.h"

Event *RandomEventFactory::createEvent(int noEvent)
{
    Event* event;
    switch (noEvent) {
        case 1 :
            event = new Blaze("Blaze", RandomEventFactory::randTime(1));
        break;
        case 2 :
            event = new BrokenEquipement("Broken Equipement");
        break;
        case 3 :
            event = new Competition("Competition");
        break;
        case 4 :
            event = new Customer("Customer", RandomEventFactory::randTime(1));
        break;
        case 5 :
            event = new DeliveryProblem("Delivery Problem");
        break;
        case 6 :
            event = new Fight("Fight", RandomEventFactory::randTime(1));
        break;
        case 7 :
            event = new Fine("Fine");
        break;
        case 8 :
            event = new Inspectorate("Inspecorate", RandomEventFactory::randTime(1));
        break;
        case 9 :
            event = new Reception("Reception", RandomEventFactory::randTime(1));
        break;
        case 10 :
            event = new Strike("Strike", RandomEventFactory::randTime(1));
        break;
        case 11 :
            event = new Tax("Tax");
        break;
        case 12 :
            event = new Unveilling("Unveilling", RandomEventFactory::randTime(1));
        break;
        case 13 :
            event = new Weather("Weather",RandomEventFactory::randTime(1));
        break;
        case 0:
        default :
            event = new Nothing();
    }
    return event;
}

int RandomEventFactory::randTime(int hour)
{
    int random = rand() % (hour+1000) + hour;

    return random*1000;
}


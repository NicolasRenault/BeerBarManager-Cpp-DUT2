#include "header/reception.h"

Reception::Reception(QString name, int time): Event(name, time)
{

}

void Reception::applyEvent(int time)
{
    timer->start(time);
    bar->setPopularity((bar->popularity()+15));
}

void Reception::reverse()
{
    bar->setPopularity((bar->wallet()-15));
}

#include "header/weather.h"

Weather::Weather(QString name, int time): Event(name, time)
{

}

void Weather::applyEvent(int )
{
    int random = rand() % 2 +1;
    if (random == 1) {
        weatherBonus = 3;
    }
    else weatherBonus = -3;

    bar->setPopularity((bar->popularity()+weatherBonus));
}

void Weather::reverse()
{
    bar->setPopularity((bar->popularity()-weatherBonus));
}

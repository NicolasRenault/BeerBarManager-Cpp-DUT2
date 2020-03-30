#ifndef WEATHER_H
#define WEATHER_H

#include "event.h"

class Weather : public Event
{

private:
    int weatherBonus;
public:
    Weather(QString name, int time);
    void applyEvent(int time) override;
    void reverse() override;
};

#endif // WEATHER_H

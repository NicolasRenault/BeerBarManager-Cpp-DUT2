#ifndef DAYOFFEMPLOYEE_H
#define DAYOFFEMPLOYEE_H

#include "event.h"

class DayOffEmployee : public Event
{
public:
    DayOffEmployee(QString name, int time);
    void applyEvent(int time) override;
    void reverse() override;
};

#endif // DAYOFFEMPLOYEE_H

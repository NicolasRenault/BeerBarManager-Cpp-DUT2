#ifndef STRIKE_H
#define STRIKE_H

#include "event.h"

class Strike : public Event
{
public:
    Strike(QString name, int time);
    void applyEvent(int time) override;
    void reverse() override;
};

#endif // STRIKE_H

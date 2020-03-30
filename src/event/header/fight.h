#ifndef FIGHT_H
#define FIGHT_H

#include "event.h"

class Fight : public Event
{
public:
    Fight(QString name, int time);
    void applyEvent(int time) override;
    void reverse() override;
};

#endif // FIGHT_H

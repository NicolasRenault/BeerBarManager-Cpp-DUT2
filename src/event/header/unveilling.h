#ifndef UNVEILLING_H
#define UNVEILLING_H

#include "event.h"

class Unveilling : public Event
{
public:
    Unveilling(QString name, int time);
    void applyEvent(int time) override;
    void reverse() override;
};

#endif // UNVEILLING_H

#ifndef BLAZE_H
#define BLAZE_H

#include "event.h"

class Blaze : public Event
{
public:
    Blaze(QString name, int time);
    void applyEvent(int time) override;
    void reverse() override;
};

#endif // BLAZE_H

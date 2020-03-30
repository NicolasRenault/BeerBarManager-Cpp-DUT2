#ifndef NOTHING_H
#define NOTHING_H

#include "event.h"

class Nothing : public Event
{
public:
    Nothing();
    void applyEvent() override;
};

#endif // NOTHING_H

#ifndef COMPETITION_H
#define COMPETITION_H

#include "event.h"

class Competition : public Event
{
public:
    Competition(QString name);
    void applyEvent() override;
};

#endif // COMPETITION_H

#ifndef INSPECTORATE_H
#define INSPECTORATE_H

#include "event.h"

class Inspectorate : public Event
{
public:
    Inspectorate(QString name, int time);
    void applyEvent(int time) override;
    void reverse() override;
};

#endif // INSPECTORATE_H

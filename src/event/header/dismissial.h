#ifndef DISMISSIAL_H
#define DISMISSIAL_H

#include "event.h"

class Dismissial : public Event
{
public:
    Dismissial(QString name);
    void applyEvent() override;
};

#endif // DISMISSIAL_H

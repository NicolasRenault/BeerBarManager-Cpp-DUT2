#ifndef FINE_H
#define FINE_H

#include "event.h"

class Fine : public Event
{
public:
    Fine(QString name);
    void applyEvent() override;
};

#endif // FINE_H

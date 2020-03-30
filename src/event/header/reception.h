#ifndef RECEPTION_H
#define RECEPTION_H

#include "event.h"

class Reception : public Event
{
public:
    Reception(QString name, int time);
    void applyEvent(int time) override;
    void reverse() override;
};

#endif // RECEPTION_H

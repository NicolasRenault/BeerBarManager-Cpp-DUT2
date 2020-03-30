#ifndef DELIVERYPROBLEM_H
#define DELIVERYPROBLEM_H

#include "event.h"

class DeliveryProblem : public Event
{
public:
    DeliveryProblem(QString name);
    void applyEvent() override;
};

#endif // DELIVERYPROBLEM_H

#ifndef TAX_H
#define TAX_H

#include "event.h"

class Tax : public Event
{
public:
    Tax(QString name);
    void applyEvent() override;
};

#endif // TAX_H

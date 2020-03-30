#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QObject>
#include "event.h"

class Customer : public Event
{

public:
    explicit Customer(QString name, int time);
    void applyEvent(int time) override;
    void reverse() override;

signals:

public slots:
};

#endif // CUSTOMER_H

#include "header/customer.h"

Customer::Customer(QString name, int time): Event(name, time)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(reverse()), this, SLOT(timeout()));
}

void Customer::applyEvent(int )
{

}

void Customer::reverse()
{

}

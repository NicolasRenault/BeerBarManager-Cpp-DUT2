#include "header/tax.h"

Tax::Tax(QString name): Event(name)
{

}

void Tax::applyEvent()
{
    int price = 800;
    bar->setWallet((bar->wallet()-price));
}

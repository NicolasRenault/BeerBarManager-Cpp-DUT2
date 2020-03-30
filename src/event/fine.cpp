#include "header/fine.h"

Fine::Fine(QString name) : Event(name)
{

}

void Fine::applyEvent()
{
    int price = 700;
    //TODO Message à l'utilisateur
    bar->setWallet((bar->wallet()-price));
}

#include "header/brokenequipement.h"

BrokenEquipement::BrokenEquipement(QString name): Event(name)
{

}

void BrokenEquipement::applyEvent()
{
    int price = 300;

    bar->setWallet((bar->wallet()-price));
    //TODO Message a l'utilisateur
}

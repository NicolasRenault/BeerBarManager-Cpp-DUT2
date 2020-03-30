#include "header/blaze.h"

Blaze::Blaze(QString name, int time): Event(name, time)
{

}

void Blaze::applyEvent(int time)
{
    int price = 1000;

    bar->setWallet((bar->wallet()-price));
    timer->start(time);
    //TODO Message a l'utilisateur
}

void Blaze::reverse()
{
    //TODO Relancer le jeu
}

#include "header/inspectorate.h"

#include <event/header/fine.h>

Inspectorate::Inspectorate(QString name, int time): Event(name,time)
{

}

void Inspectorate::applyEvent(int )
{
    int random = rand() % 4 + 1;
    //TODO Message a l'utilisateur
    timer->start();
    if (random == 1) {
        //TODO Message a l'utilisateur
        Event* fine = new Fine("fine");
        fine->applyEvent();
    }
}

void Inspectorate::reverse()
{
    //TODO Relancer le jeu
}

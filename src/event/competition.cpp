#include "header/competition.h"

Competition::Competition(QString name): Event(name)
{

}

void Competition::applyEvent()
{
    //TODO Message a l'utilisateur
    bar->setPopularity((bar->popularity()-10));
}


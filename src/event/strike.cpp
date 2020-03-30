#include "header/strike.h"

Strike::Strike(QString name, int time): Event(name, time)
{

}

void Strike::applyEvent(int time)
{
    timer->start(time);
}

void Strike::reverse()
{
    //TODO relancer le jeu
}

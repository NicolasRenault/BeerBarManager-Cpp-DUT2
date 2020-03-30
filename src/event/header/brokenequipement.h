#ifndef BROKENEQUIPEMENT_H
#define BROKENEQUIPEMENT_H

#include "event.h"

class BrokenEquipement : public Event
{
public:
    BrokenEquipement(QString name);
    void applyEvent() override;
};

#endif // BROKENEQUIPEMENT_H

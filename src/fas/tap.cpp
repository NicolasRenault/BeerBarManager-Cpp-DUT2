#include "header/tap.h"

Tap::Tap(QObject *)
    :m_actif(false)
{
}

bool Tap::actif() const
{
    return m_actif;
}

void Tap::setActif(bool actif)
{
    if (m_actif == actif)
        return;

    m_actif = actif;
    emit actifChanged(m_actif);
}

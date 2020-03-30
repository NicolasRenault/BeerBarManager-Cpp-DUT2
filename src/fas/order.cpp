#include "header/order.h"

#include <QDebug>

Order::Order(Beer* beer, int time)
    : m_time(time),
      m_beer(beer),
      m_maxtime(time)
{
    //setTime(time);
}

Order::~Order()
{
    delete m_beer;
}

int Order::time() const
{
    return m_time;
}

Beer *Order::beer() const
{
    return m_beer;
}


void Order::setTime(int time)
{
    if (m_time == time)
        return;

    m_time = time;

    if (m_time <= 0)
        emit failed();

    emit timeChanged(m_time);
}

void Order::setMaxtime(int maxtime)
{
    if (m_maxtime == maxtime)
        return;

    m_maxtime = maxtime;
    emit maxtimeChanged(m_maxtime);
}

void Order::setBeer(Beer *beer)
{
    if (m_beer == beer)
        return;

    m_beer = beer;
}

void Order::oneSecond()
{
    setTime(time() - 1);
}

int Order::maxtime() const
{
    return m_maxtime;
}

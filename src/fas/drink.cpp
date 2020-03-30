#include "./header/drink.h"
#include <QDebug>

Drink::Drink(int delay)
    :
        m_angle(1),
        m_delay(delay),
        m_foam(),
        m_beer(),
        m_x(0),
        m_y(0)
{
    reset();
}

Drink::~Drink()
{
    qDebug() << "here drink";
}

int Drink::angle() const
{
    return m_angle;
}

 Liquid *Drink::beer()
{
    return &m_beer;
}

 Liquid *Drink::foam()
{
    return &m_foam;
}

void Drink::oneSecond()
{

    m_foam.updateQuantity();
    m_beer.updateQuantity();


    if (m_foam.quantity() + m_beer.quantity() >= 100) {
        emit full();
    }
}

int Drink::x() const
{
    return m_x;
}

int Drink::y() const
{
    return m_y;
}

void Drink::reset()
{
    m_beer.setQte(0);
    m_foam.setQte(0);
    setAngle(0);
}

void Drink::setAngle(int angle)
{
    m_angle = angle;

    if (m_angle == 360 || m_angle == -360)
        m_angle = 0;


    m_beer.setQuotient(19.*m_delay/1000.);
    if (m_angle <= 5 && m_angle >= -5)
    {
        m_foam.setQuotient(7.*m_delay/1000);

    } else if ((m_angle <= 30 && m_angle >= 40) || (m_angle <= 320 && m_angle >= 310)
             || (m_angle <= -30 && m_angle >= -40) || (m_angle <= -320 && m_angle >= -310))
    {
        m_foam.setQuotient(1.*m_delay/1000);

    } else if ((m_angle > 80 && m_angle < 280) || (m_angle > -80 && m_angle < -280))
    {
        m_foam.setQuotient(-20.*m_delay/1000);
        m_beer.setQuotient(-20.*m_delay/1000);
    } else  {
        m_foam.setQuotient(2.5*m_delay/1000);
    }

    emit angleChanged(m_angle);
}

void Drink::setX(int x)
{
    if (m_x == x)
        return;

    m_x = x;
    emit xChanged(m_x);
}

void Drink::setY(int y)
{
    if (m_y == y)
        return;

    m_y = y;
    emit yChanged(m_y);
}

void Drink::moveDrink(int key)
{
    switch (key) {
    case Qt::Key_Right:
        setAngle(angle() + 5);
        break;
    case Qt::Key_Left:
        setAngle(angle() - 5);
        break;
    case Qt::Key_Z:
        setY(y() - 5);
        break;
    case Qt::Key_Q:
        setX(x() - 5);
        break;
    case Qt::Key_S:
        setY(y() + 5);
        break;
    case Qt::Key_D:
        setX(x() + 5);
        break;
    }
}

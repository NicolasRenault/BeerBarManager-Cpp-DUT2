#ifndef DRINK_H
#define DRINK_H

#include "liquid.h"

#include <QObject>

class Drink : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int angle READ angle WRITE setAngle NOTIFY angleChanged)
    Q_PROPERTY(int x READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(int y READ y WRITE setY NOTIFY yChanged)

public:
    Drink(int delay);
    ~Drink();

    int angle() const;
    Q_INVOKABLE Liquid *foam();
    Q_INVOKABLE Liquid *beer();
    void oneSecond();

    int x() const;
    int y() const;

    void reset();

public slots:
    void moveDrink(int key);
    void setAngle(int angle);

    void setX(int x);

    void setY(int y);

signals:
    void angleChanged(int angle);
    void full();

    void xChanged(int x);

    void yChanged(int y);

private:
    int m_angle;
    int m_delay;
    Liquid m_foam;
    Liquid m_beer;
    int m_x;
    int m_y;
};

#endif // DRINK_H

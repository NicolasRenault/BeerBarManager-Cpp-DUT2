#ifndef ORDER_H
#define ORDER_H

#include <QObject>
#include "../../metier/header/beer.h"

class Order : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int time READ time WRITE setTime NOTIFY timeChanged)
    Q_PROPERTY(int maxtime READ maxtime WRITE setMaxtime NOTIFY maxtimeChanged)

public:
    Order(Beer* beer, int time);
    ~Order();

    int time() const;
    Q_INVOKABLE Beer *beer() const;
    void setBeer(Beer *beer);
    void oneSecond();

    int maxtime() const;

public slots:
    void setTime(int time);

    void setMaxtime(int maxtime);

signals:
    void timeChanged(int time);
    void failed();

    void maxtimeChanged(int maxtime);

private:
    int m_time;
    Beer *m_beer;
    int m_maxtime;
};

#endif // ORDER_H

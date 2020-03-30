#ifndef FASGAME_H
#define FASGAME_H

#include "order.h"
#include "ordergenerator.h"
#include "drink.h"
#include "player.h"
#include "tap.h"

#include <QObject>
#include <QQmlContext>
#include <QTimer>
#include <QQmlApplicationEngine>

#define NBTAP 4

class FASGame : public QObject
{

    Q_OBJECT
    Q_PROPERTY(int time READ time WRITE setTime NOTIFY timeChanged)
    Q_PROPERTY(int tapSelected READ tapSelected WRITE setTapSelected NOTIFY tapSelectedChanged)
public:
    explicit FASGame(QQmlContext *context, int time);

    int time() const;
    bool isFinish();
    int tapSelected() const;

    ~FASGame();

public slots:
    void end();
    void setTime(int time);
    void keyEventListener(int key);
    void oneSecond();
    void setTapSelected(int tapSelected);
    void start();

signals:
    void timeChanged(int time);
    void tapSelectedChanged(int tapSelected);
    void noSwitch();
    void endGame(int point);

private:
    void serverOrder();
    void failOrder();
    void newOrder();

    bool m_finish = false;
    bool m_start_serv = false;
    int m_time;
    int m_delay;
    int m_tapSelected;


    Drink m_drink;
    Tap * m_taps[NBTAP];
    Player m_player;

    Order m_order;
    QQmlContext *m_context;
    QTimer m_perSecond;
};

#endif // FASGAME_H

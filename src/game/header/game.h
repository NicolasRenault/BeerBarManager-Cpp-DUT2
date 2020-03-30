#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QCloseEvent>

#include "metier/header/bar.h"
#include "metier/header/modelBeer.h"
#include "fas/header/fasgame.h"

class Game : public QObject
{
    Q_OBJECT
public:
    Game();
    ~Game();
    Game(QQmlContext *context);
    void init();

    FASGame *fasgame();

    Q_INVOKABLE void start();
    Q_INVOKABLE void startFAS();
    Q_INVOKABLE void startNotebook();
    Q_INVOKABLE void startGame();
    Q_INVOKABLE void createBeer(QString hopIng, QString maltyIng, int preparationTime, QString name);
    Q_INVOKABLE void fasGameEnd(int point);

signals:
    void switchToFAS();
    void switchToNotebook();
    void switchToGame();
    void nameChanged(QString name);
    void closeEvent(QCloseEvent *event);

private:

    bool isRunning;
    QQmlContext * m_context;
    Bar *m_bar;
    FASGame *m_fas;
    ModelBeer *m_modelBeer;
};

#endif // GAME_H

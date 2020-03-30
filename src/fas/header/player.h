#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

class Player : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int point READ point NOTIFY pointChanged)

public:
    Player();

    int point() const;
    void addPoint(int point);
    void removePoint(int point);

signals:
    void pointChanged(int point);
    void success();
    void failed();

private:
    int m_point;
};

#endif // PLAYER_H

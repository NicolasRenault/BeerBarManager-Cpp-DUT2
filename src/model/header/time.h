#ifndef TIME_H
#define TIME_H

#include <QTimer>
#include <model/header/eventmanager.h>



class Time : public QTimer
{
    Q_OBJECT

    Q_PROPERTY(int time READ time WRITE setTime NOTIFY timeChanged)
    Q_PROPERTY(int speedTime READ speedTime WRITE setSpeedTime NOTIFY speedTimeChanged)
    Q_PROPERTY(int hour READ hour WRITE setHour NOTIFY hourChanged)
    Q_PROPERTY(int minute READ minute WRITE setMinute NOTIFY minuteChanged)

public:
    Time(EventManager* eventManager);
    int time() const;
    int speedTime() const;
    int hour() const;
    int minute() const;
    void convetTimeToHour(int time);
    void increaseTime();
    void decreaseTime();
    void startTimer(int speed);
    void stopTimer();

public slots:
    void setTime(int time);
    void setSpeedTime(int speedTime);
    void setHour(int hour);
    void setMinute(int minute);
    void timePlus();

signals:
    void timeChanged(int time);
    void speedTimeChanged(int speedTime);
    void hourChanged(int hour);
    void minuteChanged(int minute);

private:
    EventManager* eventManager;
    int m_time;
    int m_speedTime;
    int m_hour;
    int m_minute;
    QTimer* timer;

    enum speed {
        NORMAL = 2000,
        FAST = 500
    };
};

#endif // TIME_H

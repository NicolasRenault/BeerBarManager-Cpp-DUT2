#include "header/time.h"


Time::Time(EventManager* eventManager) : eventManager(eventManager), m_time(0), m_speedTime(speed::NORMAL)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timout()), this, SLOT(timePlus()));
}

int Time::time() const
{
    return m_time;
}

int Time::speedTime() const
{
    return m_speedTime;
}

int Time::hour() const
{
    return m_hour;
}

int Time::minute() const
{
    return m_minute;
}

void Time::convetTimeToHour(int time)
{
    setHour(time/60);
    setMinute(time%60);
}

void Time::increaseTime()
{
    int speed = speedTime();
    switch (speed) {
        case speed::NORMAL :
            setSpeedTime(speed::FAST);
            break;
        default:
            break;
    }
}

void Time::decreaseTime()
{
    int speed = speedTime();
    switch (speed) {
        case speed::FAST :
            setSpeedTime(speed::NORMAL);
            break;
        default:
            break;
    }
}

void Time::startTimer(int speed)
{
    timer->start(speed);
}

void Time::stopTimer()
{
    timer->stop();
}

void Time::setTime(int time)
{
    if (m_time == time)
        return;

    m_time = time;
    convetTimeToHour(m_time);
    emit timeChanged(m_time);
}

void Time::setSpeedTime(int speedTime)
{
    if (m_speedTime == speedTime)
        return;

    m_speedTime = speedTime;
    stopTimer();
    startTimer(m_speedTime);
    emit speedTimeChanged(m_speedTime);
}

void Time::setHour(int hour)
{
    if (m_hour == hour)
        return;

    m_hour = hour;
    emit hourChanged(m_hour);
}

void Time::setMinute(int minute)
{
    if (m_minute == minute)
        return;

    m_minute = minute;
    emit minuteChanged(m_minute);
}

void Time::timePlus()
{
    setTime(time()+1);
    eventManager->launchEvent(hour(), minute());
}




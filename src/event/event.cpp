#include "event/header/event.h"

Event::Event(QString name): m_name(name), m_runtime(-1)
{
    setTime();
}

Event::Event(QString name, int time): m_name(name), m_runtime(time)
{
    setTime();
}

QString Event::name() const
{
    return m_name;
}

int Event::runtime() const
{
    return m_runtime;
}

void Event::lauchEvent()
{
    if (m_runtime == -1) applyEvent();
    else applyEvent(m_runtime);
}

void Event::setBar(Bar *barGame)
{
    bar = barGame;
}

void Event::setTime()
{
    timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, SIGNAL(reverse()), this, SLOT(timeout()));
    //TODO changer le SLOT de timer par une méthode (a définir)
}


void Event::setName(QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(m_name);
}

void Event::setRuntime(int runtime)
{
    if (m_runtime == runtime)
        return;

    m_runtime = runtime;
    emit runtimeChanged(m_runtime);
}

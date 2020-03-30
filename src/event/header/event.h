#ifndef EVENT_H
#define EVENT_H

#include <QObject>
#include <QTimer>
#include <metier/header/bar.h>

class Event : public QTimer
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int runtime READ runtime WRITE setRuntime NOTIFY runtimeChanged)
private:
    QString m_name;
    int m_runtime;

public:
    Bar* bar;
    QTimer* timer;

    explicit Event(QString name);
    explicit Event(QString name, int time);

    QString name() const;
    int runtime() const;
    void lauchEvent();
    virtual void applyEvent(){}
    virtual void applyEvent(int /*time*/){}
    virtual void reverse(){}
    void setBar(Bar* barGame);
    void setTime();

signals:

    void nameChanged(QString name);
    void runtimeChanged(int runtime);

public slots:
    void setName(QString name);
    void setRuntime(int runtime);
};

#endif // EVENT_H

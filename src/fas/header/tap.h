#ifndef TAP_H
#define TAP_H

#include <QObject>

class Tap : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool actif READ actif WRITE setActif NOTIFY actifChanged)

public:
    explicit Tap(QObject *parent = nullptr);
    bool actif() const;

public slots:
    void setActif(bool actif);

signals:
    void actifChanged(bool actif);

private:
    bool m_actif;
};

#endif // TAP_H

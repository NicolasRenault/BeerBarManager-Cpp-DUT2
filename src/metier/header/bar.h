#ifndef BAR_H
#define BAR_H

#include <QObject>

class Bar : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int wallet READ wallet WRITE setWallet NOTIFY walletChanged)
    Q_PROPERTY(int popularity READ popularity WRITE setPopularity NOTIFY popularityChanged)
    Q_PROPERTY(QString address READ address WRITE setAddress NOTIFY addressChanged)

public:

    Bar();
    Bar(QString barName, int barPopularity, int barWallet, QString barAddress);

    QString name() const;
    int popularity() const;
    int wallet() const;
    QString address() const;

signals:

    void popularityChanged(int popularity);
    void nameChanged(QString name);
    void walletChanged(int wallet);
    void addressChanged(QString address);

public slots:

    void setPopularity(int popularity);
    void setName(QString name);
    void setWallet(int wallet);
    void setAddress(QString address);

private :

    QString m_barName;
    int m_popularity;
    int m_wallet;
    QString m_address;
};

#endif // BAR_H

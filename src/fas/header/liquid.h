#ifndef LIQUID_H
#define LIQUID_H

#include <QObject>

class Liquid : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double quantity READ quantity NOTIFY quantityChanged)

public:
    explicit Liquid(QObject *parent = nullptr);
    ~Liquid();

    double quantity() const;
    double quotient() const;
    void updateQuantity();
    void setQte(double qte);

public slots:
    void setQuotient(double quotient);

signals:
    void quantityChanged(double quantity);

private:
    double m_quantity;
    double m_quotient;
};

#endif // LIQUID_H

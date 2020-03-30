#include "header/liquid.h"

#include <QDebug>

Liquid::Liquid(QObject *parent)
    : QObject(parent),
      m_quantity(-1),
      m_quotient(1)
{
}

Liquid::~Liquid() {
    qDebug() << "here liquid";
}

double Liquid::quantity() const
{
    return m_quantity;
}

double Liquid::quotient() const
{
    return m_quotient;
}

void Liquid::updateQuantity()
{
    m_quantity += m_quotient;
    if (m_quantity < 0)
        m_quantity = 0;

    emit quantityChanged(m_quantity);
}

void Liquid::setQte(double qte)
{
    m_quantity = qte;
    emit quantityChanged(m_quantity);
}

void Liquid::setQuotient(double quotient)
{
    m_quotient = quotient;
}

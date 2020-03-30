#include "header/bar.h"



Bar::Bar()
{

}

Bar::Bar(QString barName, int barPopularity, int barWallet, QString barAddress) : m_barName(barName), m_popularity(barPopularity), m_wallet(barWallet), m_address(barAddress)
{

}


int Bar::popularity() const
{
    return m_popularity;
}


QString Bar::name() const
{
    return m_barName;
}

int Bar::wallet() const
{
    return  m_wallet;
}

QString Bar::address() const
{
    return m_address;
}

void Bar::setPopularity(int popularity)
{
    if (m_popularity == popularity)
        return;

    m_popularity = popularity;
    emit popularityChanged(m_popularity);
}

void Bar::setName(QString name)
{
    if (m_barName == name)
        return;

    m_barName = name;
    emit nameChanged(m_barName);
}

void Bar::setWallet(int wallet)
{
    if (m_wallet == wallet)
        return;

    m_wallet = wallet;
    emit walletChanged(m_wallet);
}

void Bar::setAddress(QString address)
{
    if (m_address == address)
        return;

    m_address = address;
    emit addressChanged(m_address);
}


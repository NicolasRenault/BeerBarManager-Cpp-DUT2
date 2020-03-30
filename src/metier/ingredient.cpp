#include "header/ingredient.h"



Ingredient::Ingredient(QString ingredientName, QString ingredientType) : m_name(ingredientName), m_type(ingredientType)
{

}

QString Ingredient::name() const
{
    return m_name;
}

QString Ingredient::type() const
{
    return m_type;
}

void Ingredient::setName(QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(m_name);
}

void Ingredient::setType(QString type)
{
    if (m_type == type)
        return;

    m_type = type;
    emit typeChanged(m_type);
}

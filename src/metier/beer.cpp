#include "header/beer.h"

Beer::Beer(QString beerName, int beerAlcoholLevels,
           int beerIBU, int beerDensity, QString beerColor,
           QString beerType, Recipe* recipe)
    : m_name(beerName),
      m_alcoholeLevels(beerAlcoholLevels),
      m_IBU(beerIBU), m_density(beerDensity),
      m_color(beerColor), m_type(beerType), m_recipe(recipe)
{
}

QString Beer::name() const
{
    return m_name;
}

int Beer::alcoholeLevels() const
{
    return m_alcoholeLevels;
}

int Beer::IBU() const
{
    return m_IBU;
}

int Beer::density() const
{
    return m_density;
}

QString Beer::color() const
{
    return m_color;
}

QString Beer::type() const
{
    return m_type;
}

Recipe* Beer::recipe() const
{
    return m_recipe;
}

void Beer::setName(QString name)
{
    if (m_name == name)
        return;

    m_name = name;

    emit nameChanged(m_name);
}

void Beer::setAlcoholeLevels(int alcoholeLevels)
{
    if (m_alcoholeLevels == alcoholeLevels)
        return;

    m_alcoholeLevels = alcoholeLevels;
    emit alcoholeLevelsChanged(m_alcoholeLevels);
}

void Beer::setIBU(int IBU)
{
    if (m_IBU == IBU)
        return;

    m_IBU = IBU;
    emit IBUChanged(m_IBU);
}

void Beer::setDensity(int density)
{
    if (m_density == density)
        return;

    m_density = density;
    emit densityChanged(m_density);
}

void Beer::setColor(QString color)
{
    if (m_color == color)
        return;

    m_color = color;
    emit colorChanged(m_color);
}

void Beer::setType(QString type)
{
    if (m_type == type)
        return;

    m_type = type;
    emit typeChanged(m_type);
}

void Beer::setRecipe(Recipe* recipe)
{
    if (m_recipe == recipe)
        return;

    m_recipe = recipe;
    emit recipeChanged(m_recipe);
}



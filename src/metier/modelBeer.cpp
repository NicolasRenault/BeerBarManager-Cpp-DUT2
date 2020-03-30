#include "header/modelBeer.h"

#include <QDebug>

void ModelBeer::addBeer(Beer *beer){
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_beers << beer;
    endInsertRows();
}

Beer* ModelBeer::getBeer(int row) {
    return m_beers[row];
}


int ModelBeer::rowCount(const QModelIndex &) const
{
    return m_beers.count();
}

QVariant ModelBeer::data(const QModelIndex &index, int role) const{
    if (index.row() < 0 || index.row() >= m_beers.count())
        return QVariant();

    Beer * beer = m_beers[index.row()];

    switch (role) {
    case NameRole:
        return beer->name();
    case TypeRole:
        return beer->type();
    case VolRole:
        return beer->alcoholeLevels();
    case DensityRole:
        return beer->density();
    case IBURole:
        return beer->IBU();
    case ColorRole:
        return beer->color();
    case RecipeRole:
        return QVariant::fromValue(beer->recipe());
    case BeerRole:
    case Qt::DisplayRole:
        return QVariant::fromValue(beer);
    }
    throw "bug";
}

bool ModelBeer::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.row() < 0 || index.row() >= m_beers.count())
        return false;

    if(data(index,role)==value)
        return true;

    Beer * beer = m_beers[index.row()];
    switch (role) {
    case NameRole:
        beer->setName(value.toString());
        break;
    case TypeRole:
        beer->setType(value.toString());
        break;
    case VolRole:
        beer->setAlcoholeLevels(value.toInt());
        break;
    case DensityRole:
        beer->setDensity(value.toInt());
        break;
    case IBURole:
        beer->setIBU(value.toInt());
        break;
    case ColorRole:
        beer->setColor(value.toString());
        break;
    case RecipeRole:
        beer->setRecipe(qvariant_cast<Recipe *>(value));
        break;
    }

    QVector<int> roles;
    roles.append(role);

    QModelIndex topLeft=index.sibling(0,0);
    QModelIndex bottomRight=index.sibling(m_beers.count()-1,0);

    emit dataChanged(topLeft,bottomRight,roles);

    return true;


}

bool ModelBeer::removeRows(int row, int count, const QModelIndex &parent)
{
    if (row < 0 || row+count >= m_beers.count())
        return false;
    beginRemoveRows(parent,row,row+count-1);
    for (int nb = 0; nb < count; ++nb) {
        m_beers.removeAt(row);
    }
    endRemoveRows(); return true;

}

bool ModelBeer::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent,row,row+count-1);
    for (int nb = 0; nb < count; ++nb) {
        m_beers.insert(row, new Beer("Biere vide",0,10,1600,"blanche","vide",new Recipe(0)));
    }
    endInsertRows();
    return true;

}

void ModelBeer::refresh()
{

}


QHash<int, QByteArray> ModelBeer::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[NameRole] = "name";
    roles[TypeRole] = "type";
    roles[VolRole] = "vol";
    roles[DensityRole] = "density";
    roles[BeerRole] = "beer";
    roles[IBURole]="IBU";
    roles[ColorRole]="color";
    roles[RecipeRole]="recipe";

    return roles;

}


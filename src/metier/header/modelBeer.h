#ifndef BEERMODEL_H
#define BEERMODEL_H

#include <QAbstractListModel>
#include "beer.h"

class ModelBeer :  public QAbstractListModel
{
    Q_OBJECT
public:
    enum BeerRoles {
        NameRole = Qt::UserRole + 1,
        TypeRole,
        VolRole,
        BeerRole,
        DensityRole,
        IBURole,
        ColorRole,
        RecipeRole
    };
    void addBeer(Beer *beer);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole);
    Q_INVOKABLE bool removeRows(int row, int count, const QModelIndex &parent= QModelIndex());
    Q_INVOKABLE bool insertRows(int row, int count, const QModelIndex & parent = QModelIndex());

    Q_INVOKABLE void refresh();
    Q_INVOKABLE Beer *getBeer(int row);
protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<Beer*> m_beers;

};

#endif // BEERMODEL_H

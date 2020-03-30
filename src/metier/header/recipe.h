#ifndef RECIPE_H
#define RECIPE_H

#include <QObject>
#include "ingredient.h"
#include <vector>

using namespace std;

class Recipe : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int preparationTime READ preparationTime WRITE setPreparationTime NOTIFY preparationTimeChanged)

private:


    int m_preparationTime;
    std::vector<Ingredient*> listIngredient;

public:

    explicit Recipe( int recipePreparationTime);
    int preparationTime() const;
    vector<Ingredient *> getListIngredient();

public slots:

    void setPreparationTime(int preparationTime);
    void addIngredient( Ingredient *ingredient);
    void deleteIngredient(Ingredient* ingredient);


signals:
    void beerIDChanged(int beerID);
    void preparationTimeChanged(int preparationTime);
};

#endif // RECIPE_H

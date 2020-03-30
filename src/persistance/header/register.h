#ifndef REGISTER_H
#define REGISTER_H


#include <QObject>
#include <vector>

#include "../../metier/header/beer.h"

class Register : public QObject
{
     Q_OBJECT
private:

    vector<Ingredient *> listIngredient;
    vector<Beer *> listBeer;
    vector<Recipe *> listRecipe;

public:
    Register();

    vector<Ingredient *> getListIngredient() const;
    void setListIngredient(const vector<Ingredient *> &value);
    vector<Beer *> getListBeer() const;
    void setListBeer(const vector<Beer *> &value);
    vector<Recipe *> getListRecipe() const;
    void setListRecipe(const vector<Recipe *> &value);

    void addIngredient(Ingredient *ingredient);
    void addBeer(Beer *beer);
    void addRecipe(Recipe *recipe);
    void show();
};

#endif // REGISTER_H

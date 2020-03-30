#include "header/recipe.h"
Recipe::Recipe(int recipePreparationTime) : m_preparationTime(recipePreparationTime)
{

}



int Recipe::preparationTime() const
{
    return m_preparationTime;
}

vector< Ingredient *> Recipe::getListIngredient()
{
    return listIngredient;
}



void Recipe::setPreparationTime(int preparationTime)
{
    if (m_preparationTime == preparationTime)
        return;

    m_preparationTime = preparationTime;
    emit preparationTimeChanged(m_preparationTime);
}

void Recipe::addIngredient(Ingredient *ingredient)
{
    listIngredient.push_back(ingredient);
}

void Recipe::deleteIngredient(Ingredient *ingredient)
{
    for (int i = 0; i < (int)listIngredient.size(); ++i) {
        if (listIngredient[i] == ingredient)
            listIngredient.erase(listIngredient.begin()+i);
    }
}


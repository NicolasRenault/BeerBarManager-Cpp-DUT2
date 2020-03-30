#include "header/register.h"

Register::Register()
{

}

vector<Ingredient *> Register::getListIngredient() const
{
    return listIngredient;
}

void Register::setListIngredient(const vector<Ingredient *> &value)
{
    listIngredient = value;
}

vector<Recipe *> Register::getListRecipe() const
{
    return listRecipe;
}

void Register::setListRecipe(const vector<Recipe *> &value)
{
    listRecipe = value;
}

vector<Beer *> Register::getListBeer() const
{
    return listBeer;
}

void Register::setListBeer(const vector<Beer *> &value)
{
    listBeer = value;
}

void Register::addIngredient(Ingredient *ingredient)
{
    listIngredient.push_back(ingredient);
}

void Register::addBeer(Beer *beer){
    listBeer.push_back(beer);
}
void Register::addRecipe(Recipe *recipe){
    listRecipe.push_back(recipe);
}


/*void Register::show(){
    QTextStream(stdout) << "liste ingredient : " << endl;
    for (int i = 0; i < listIngredient.size(); ++i) {
        QTextStream(stdout) <<  "\t"+ QString::number(i)+ " "+ listIngredient[i]->toString() << endl;
    }
    QTextStream(stdout) << "liste beer : " << endl;
    for (int i = 0; i < listBeer.size(); ++i) {
        QTextStream(stdout) << "\t"+ QString::number(i)+ " "+ listBeer[i]->toString() << endl;
    }
    QTextStream(stdout) << "liste recipe : " << endl;
    for (int i = 0; i < listRecipe.size(); ++i) {
        QTextStream(stdout) << "\t"+ QString::number(i)+ " "+ listRecipe[i]->toString() << endl;
    }*/


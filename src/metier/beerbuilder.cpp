#include "header/beerbuilder.h"
#include <QString>
#include <QRandomGenerator>
#include <QDebug>
#include <vector>

Beer *buildBeer( QString hopIng,  QString maltyIng, int preparationTime, QString name)
{
    QString color = "";
    QString type = "";
    int density = 0;
    int IBU = 0;
    int alcohole = 0;
    Ingredient *hop = new Ingredient(hopIng,"plante");
    Ingredient *malty = new Ingredient(maltyIng,"céréale");

    Recipe * recipe = new Recipe(preparationTime);
    recipe->addIngredient(hop);
    recipe->addIngredient(malty);

    if(malty->name().toLower() == "extra malty"){
        color = "noir";
        type = "Stout";
        density = 1080;
        alcohole = QRandomGenerator::global()->bounded(40,80);
    }else if(malty->name().toLower() == "slightly malty"){
        color = "brun";
        type= "Ambré";
        density = 1060;
        alcohole = QRandomGenerator::global()->bounded(60,120);
    }else if(malty->name().toLower() == "evenly balanced" && preparationTime <= 90 ){
        color = "or pâle";
        type = "Blanche";
        density = 1030;
        alcohole = QRandomGenerator::global()->bounded(30,70);
    }else{
        color = "or";
        type = "Blonde";
        density = 1060;
        alcohole = QRandomGenerator::global()->bounded(40,110);
    }
    //--------------------------DEFINITION IBU--------------------------
    // IBU Stout
    if(type == "Stout" && (preparationTime == 180 || preparationTime == 170 || preparationTime == 190)){
        IBU = 20;
    }else if (type == "Stout" && preparationTime < 170) {
        IBU = 30;
    }else if(type == "Stout" && preparationTime > 190){
        IBU = 15;
    }

    //IBU Blonde
    if (type == "Blonde" && (preparationTime == 120 || preparationTime == 110 || preparationTime == 130)){
            IBU = 30;
    }else if (type == "Blonde" && preparationTime < 110) {
            IBU = 35;
    }else if(type == "Blonde" && preparationTime > 130){
            IBU = 25;
    }

    //IBU Blanche
    if (type == "Blanche" && (preparationTime == 60 || preparationTime == 50 || preparationTime == 70)){
            IBU = 30;
    }else if (type == "Blanche" && preparationTime < 50) {
            IBU = 35;
    }else if(type == "Blanche" && preparationTime > 70){
            IBU = 25;
    }

    //IBU Ambre
    if (type == "Ambré" && (preparationTime == 150 || preparationTime == 160 || preparationTime == 140)){
            IBU = 25;
    }else if (type == "Ambré" && preparationTime < 140) {
            IBU = 30;
    }else if(type == "Ambré" && preparationTime > 160){
            IBU = 20;
    }

    if(hop->name().toLower() == "vieux houblon"){
        IBU+=5;
    }


    return new Beer(name,alcohole,IBU,density,color,type,recipe);
}

#include "header/persistance.h"

void deleteAllTable(){

    QSqlQuery basesql;
    QString query1 = " DROP TABLE IF EXISTS Beer;";
    QString query2 = " DROP TABLE IF EXISTS Recipe;";
    QString query3 = " DROP TABLE IF EXISTS Ingredient;";
    QString query4 = " DROP TABLE IF EXISTS IngredientRecipe;";

    if(!basesql.exec(query1)){
        QTextStream(stdout) << "ERROR : not delete Beer" << endl;
    }
    if(!basesql.exec(query2)){
        QTextStream(stdout) << "ERROR : not delete Recipe" << endl;
    }
    if(!basesql.exec(query3)){
        QTextStream(stdout) << "ERROR : not delete Ingredient" << endl;
    }
    if(!basesql.exec(query4)){
        QTextStream(stdout) << "ERROR : not delete IngredientRecipe" << endl;
    }
    QTextStream(stdout) << "fin des suppression" << endl;

}
void createAllTable(){

    QSqlQuery basesql;
    QString query1 ="CREATE TABLE Beer( IDbeer INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR(20) NOT NULL, beerType VARCHAR(20) NOT NULL, alcoholLevels INTEGER NOT NULL, IBU INTEGER NOT NULL, density INTEGER NOT NULL, color VARCHAR(20) NOT NULL) ;";
    QString query2 ="CREATE TABLE Recipe( IDrecipe INTEGER PRIMARY KEY AUTOINCREMENT, beerID INTEGER NOT NULL, preperationTime INTEGER NOT NULL, FOREIGN KEY(beerID) REFERENCES Beer(IDbeer) );";
    QString query3 ="CREATE TABLE Ingredient( IDname VARCHAR(20) PRIMARY KEY, type VARCHAR(20) NOT NULL );";
    QString query4 ="CREATE TABLE IngredientRecipe( IDlink INTEGER PRIMARY KEY AUTOINCREMENT, IDrecipe INTEGER NOT NULL, name VARCHAR(20) NOT NULL, FOREIGN KEY(IDrecipe) REFERENCES Recipe(IDrecipe) , FOREIGN KEY(name) REFERENCES Ingredient(IDname) );";

    if(!basesql.exec(query1) ){
        QTextStream(stdout) << "ERROR : create table Beer" << endl;
    }
    if(!basesql.exec(query2) ){
        QTextStream(stdout) << "ERROR : create table Recipe" << endl;
    }
    if(!basesql.exec(query3) ){
        QTextStream(stdout) << "ERROR : create table Ingredient" << endl;
    }
   if(!basesql.exec(query4) ){
       QTextStream(stdout) << "ERROR : create table IngredientRecipe" << endl;
   }
}

void addBeer(Beer *b){

     QSqlQuery basesql;
     QString query ="INSERT INTO beer (name, beerType , alcoholLevels,IBU, density , color) VALUES( '"+ b->name() +"' , '" + b->type() +"' , '"+ QString::number(b->alcoholeLevels()) +"' , '"+ QString::number(b->IBU()) +"' , '"+ QString::number(b->density()) +"' , '"+ b->color() + "');";
     if(!basesql.exec(query) ){
         QTextStream(stdout) << "ERROR : add table Beer" << endl;
     }
}

void addIngredient(Ingredient *i){
    QSqlQuery basesql;
    QString query ="INSERT INTO Ingredient (IDname, type ) VALUES( '"+ i->name() +"' , '" + i->type() +"');";
    if(!basesql.exec(query) ){
        QTextStream(stdout) << "ERROR : add table Ingredient" << endl;
    }
}

void addRecipe(Recipe *r){
    QSqlQuery basesql;
    QString ask;// ="SELECT COUNT(*) FROM Beer WHERE IDbeer="+ QString::number(r->beerID())+";";
    basesql.exec(ask);
    int beer = 0;
    if(basesql.next() == true){
        beer = basesql.value(0).toInt();
        if(beer ==0){
             QTextStream(stdout) <<"Biere associe inexistante" << endl;
        }else{
            QString query;// ="INSERT INTO Recipe (beerID, preperationTime) VALUES( '"+ QString::number(r->beerID()) +"' , '" + QString::number(r->preparationTime()) +"');";
            basesql.exec(query);

            QString find ;//="SELECT IDrecipe FROM Recipe WHERE beerID ="+ QString::number(r->beerID())+";";
            basesql.exec(find);
            if(basesql.next() == true){
                beer = basesql.value(0).toInt();

                vector<Ingredient *> list = r->getListIngredient();
                for (int i = 0; i < list.size(); ++i) {
                    QSqlQuery basesql;
                    QString query ="INSERT INTO IngredientRecipe (IDrecipe, name ) VALUES( '"+ QString::number(beer) +"' , '" +  list[i]->name() +"');";
                    basesql.exec(query);
                }
            }
        }
    }
}

// probleme , ne réinitialise pas l'ID auto increments.
void deleteAllElement(){
    QSqlQuery basesql;
    QString query ="DELETE FROM Beer ;";
    QTextStream(stdout) << query << endl;
    if(!basesql.exec(query) ){
        QTextStream(stdout) << "ERROR : delete element Beer fail" << endl;
    }

    QString query2 ="DELETE FROM Ingredient ;";
    QTextStream(stdout) << query2 << endl;
    if(!basesql.exec(query2) ){
        QTextStream(stdout) << "ERROR : delete element Ingredient fail" << endl;
    }

    QString query3 ="DELETE FROM Recipe ;";
    QTextStream(stdout) << query3 << endl;
    if(!basesql.exec(query3) ){
        QTextStream(stdout) << "ERROR : delete element Recipe fail" << endl;
    }

    QString query4 ="DELETE FROM IngredientRecipe ;";
    QTextStream(stdout) << query4 << endl;
    if(!basesql.exec(query4) ){
        QTextStream(stdout) << "ERROR : delete element IngredientRecipe fail" << endl;
    }
}

int loadbeer(Register *reg){
    int lastBeer = 0;
    QSqlQuery basesql;
    QString query ="SELECT * FROM beer ;";
    if(!basesql.exec(query) ){
        QTextStream(stdout) << "ERROR : beer load fail " << endl;
    }
    while( basesql.next() ){
        Beer * b;//= new Beer( basesql.value(1).toString(),basesql.value(3).toInt(),basesql.value(4).toInt(),basesql.value(5).toInt(),basesql.value(6).toString(),basesql.value(2).toString());
        reg->addBeer(b);
        lastBeer++;
    }
    return lastBeer;
}

int loadingredient(Register *reg){
    int lastIngredient = 0;
    QSqlQuery basesql;
    QString query ="SELECT * FROM Ingredient ;";
    if(!basesql.exec(query) ){
        QTextStream(stdout) << "ERROR : ingredient load fail " << endl;
    }
    while( basesql.next() ){
         Ingredient * i =new Ingredient( basesql.value(0).toString(),basesql.value(1).toString());
         reg->addIngredient(i);
         lastIngredient++;
    }
    return lastIngredient;
}

int loadrecipe(Register *reg){
    int lastRecipe = 0;
    QSqlQuery basesql;
    QString query ="SELECT * FROM Recipe ;";
    if(!basesql.exec(query) ){
        QTextStream(stdout) << "ERROR : recipe load fail " << endl;
    }
    while( basesql.next() ){
         Recipe * r ;//= new Recipe( basesql.value(1).toInt(), basesql.value(2).toInt());
         QString idrecipe = basesql.value(0).toString();
         QSqlQuery chercheingredient;
         QString query ="SELECT * FROM IngredientRecipe WHERE IDrecipe = "+idrecipe+";";
         if( chercheingredient.exec(query) ){
             while( chercheingredient.next()){
                   Ingredient * i =new Ingredient( basesql.value(0).toString(),basesql.value(1).toString());
                   r->addIngredient(i);
             }
             reg->addRecipe(r);
             lastRecipe++;
         }else{
               QTextStream(stdout) << "ERRR : pas ingredient dans la recette" << endl;
         }
    }
    return  lastRecipe;
}

vector<int> load(Register *reg){
    vector<int> fin;
    int lRecipe;
    int lIngredient;
    int lbeer;
    lbeer = loadbeer(reg);
    lIngredient = loadingredient(reg);
    lRecipe = loadrecipe(reg);

    fin.push_back(lbeer);
    fin.push_back(lIngredient);
    fin.push_back(lRecipe);

    //reg->show();
    return fin;
}

void lastloadbeer(int max,Register *reg){
    vector<Beer*> list = reg->getListBeer();
    for(int i=max ; i < list.size() ; i++ ){
        addBeer(list[i]);
    }
}
void lastloadingredient(int max ,Register *reg){
    vector<Ingredient*> list = reg->getListIngredient();
    for(int i=max ; i < list.size() ; i++ ){
        addIngredient(list[i]);
    }
}
void lastloadrecipe(int max ,Register *reg){
    vector<Recipe*> list = reg->getListRecipe();
    for(int i=max ; i < list.size() ; i++ ){
        addRecipe(list[i]);
    }
}

void lastload(vector<int> list, Register *reg){
    int lbeer = list[0];
    int lIngredient = list[1];
    int lrecipe =list[2];
    lastloadbeer(lbeer,reg);
    lastloadingredient(lIngredient,reg);
    lastloadrecipe(lrecipe,reg);

    QTextStream(stdout) << "fin des enregistrements" << endl;

}

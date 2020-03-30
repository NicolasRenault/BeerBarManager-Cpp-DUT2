#ifndef PERSISTANCE_H
#define PERSISTANCE_H

#include <iostream>
#include<QString>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QTextStream>
#include <stdlib.h>
#include <QtDebug>
#include <QDir>
#include <vector>

#include "../../metier/header/beer.h"
#include "register.h"

void deleteAllTable();
void createAllTable();
void addBeer(Beer *b);
void addIngredient(Ingredient *i);
void addRecipe(Recipe *r);
void deleteAllElement();
int loadbeer(Register *reg);
int loadingredient(Register *reg);
int loadrecipe(Register *reg);
vector<int> load(Register *reg);
void lastloadbeer(int max,Register *reg);
void lastloadingredient(int max ,Register *reg);
void lastloadrecipe(int max ,Register *reg);
void lastload(vector<int> list, Register *reg);

#endif // PERSISTANCE_H

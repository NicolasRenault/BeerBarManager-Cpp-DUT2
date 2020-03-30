#include "header/game.h"
#include "metier/header/bar.h"
#include "metier/header/beerbuilder.h"
#include "fas/header/fasgame.h"
#include "../stub.h"

#include <QDebug>

#define FASTIME 120

Game::Game()
{

}

Game::~Game()
{
    delete m_bar;
    delete m_fas;
    delete m_modelBeer;
}

Game::Game(QQmlContext *context)
    : m_context(context)
{
}

void Game::init()
{

    m_bar = stubBar();
    m_fas = new FASGame(m_context, FASTIME);
    m_modelBeer = new ModelBeer();

    m_context->setContextProperty("modelBeer", m_modelBeer);
    m_context->setContextProperty("bar", m_bar);
}

FASGame *Game::fasgame()
{
    return m_fas;
}

void Game::start()
{

}

void Game::startFAS() {
    m_fas->start();
    emit switchToFAS();
}

void Game::startNotebook() {
    stubModel(m_modelBeer);
    emit switchToNotebook();
}

void Game::startGame() {
    emit switchToGame();
}

void Game::createBeer(QString hopIng, QString maltyIng, int preparationTime, QString name) {
    Beer *beer = buildBeer(hopIng, maltyIng, preparationTime, name);
    m_modelBeer->addBeer(beer);
}

void Game::fasGameEnd(int point)
{
    qDebug() << point;
}


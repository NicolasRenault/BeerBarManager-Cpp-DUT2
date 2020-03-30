#include "game/header/game.h"

int main(int argc, char *argv[])
{


    qmlRegisterUncreatableType<Beer>("beer",1,0,"Beer","Can't build a beer in QML");
    qmlRegisterType<Liquid>("liquid", 1, 0, "Liquid");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Game game(engine.rootContext());

    // Build all components of the game
    game.init();

    engine.rootContext()->setContextProperty("game", &game);

    const QUrl url(QStringLiteral("qrc:menu/mainGame.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    QObject::connect(&game,
                     &Game::switchToFAS,
                     [&engine]() {
                         engine.load("qrc:/fas/mainFAS.qml");
                     }
    );

    QObject::connect(&game, &Game::switchToNotebook,
                     [&engine]() {
                         engine.load("qrc:/notebook/mainNotebook.qml");
                     }
    );

    QObject::connect(&game, &Game::closeEvent, [](){
            //Fermer le fas
    });

    QObject::connect(&game, &Game::switchToGame,
                     [&engine](){
                            engine.load("qrc:game/gameGui.qml");
            //Lance la game
    });

    QObject::connect(game.fasgame(), &FASGame::endGame, &game, &Game::fasGameEnd);

    engine.load(url);

    return app.exec();
}


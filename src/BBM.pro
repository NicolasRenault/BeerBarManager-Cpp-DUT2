QT += quick
QT += sql

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS += -Wno-unused-function

SOURCES += \
        main.cpp \
    persistance/persistance.cpp \
    persistance/register.cpp \
    stub.cpp \
    game/game.cpp \
    metier/beerbuilder.cpp \
    metier/bar.cpp \
    metier/beer.cpp \
    metier/ingredient.cpp \
    metier/recipe.cpp \
    metier/modelBeer.cpp \
    model/eventmanager.cpp \
    model/time.cpp \
    model/randomeventfactory.cpp \
    model/eventlauncher.cpp \
    event/event.cpp \
    event/customer.cpp \
    event/unveilling.cpp \
    event/reception.cpp \
    event/fight.cpp \
    event/blaze.cpp \
    event/strike.cpp \
    event/dayoffemployee.cpp \
    event/competition.cpp \
    event/inspectorate.cpp \
    event/weather.cpp \
    event/fine.cpp \
    event/dismissial.cpp \
    event/tax.cpp \
    event/brokenequipement.cpp \
    event/deliveryproblem.cpp \
    event/nothing.cpp \
    fas/drink.cpp \
    fas/fasgame.cpp \
    fas/liquid.cpp \
    fas/player.cpp \
    fas/tap.cpp \
    fas/order.cpp \
    fas/ordergenerator.cpp

RESOURCES += \
    ../qml/qml.qrc

# Additional import path used to resolve QML modules in Qt Creators code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    persistance/header/persistance.h \
    persistance/header/register.h \
    stub.h \
    game/header/game.h \
    metier/header/bar.h \
    metier/header/beer.h \
    metier/header/ingredient.h \
    metier/header/recipe.h \
    metier/header/modelBeer.h \
    metier/header/beerbuilder.h \
    model/header/eventmanager.h \
    model/header/time.h \
    model/header/randomeventfactory.h \
    model/header/eventlauncher.h \
    event/header/event.h \
    event/header/customer.h \
    event/header/unveilling.h \
    event/header/reception.h \
    event/header/fight.h \
    event/header/blaze.h \
    event/header/strike.h \
    event/header/dayoffemployee.h \
    event/header/competition.h \
    event/header/inspectorate.h \
    event/header/weather.h \
    event/header/fine.h \
    event/header/dismissial.h \
    event/header/tax.h \
    event/header/brokenequipement.h \
    event/header/deliveryproblem.h \
    event/header/nothing.h \
    fas/header/drink.h \
    fas/header/fasgame.h \
    fas/header/liquid.h \
    fas/header/player.h \
    fas/header/tap.h \
    fas/header/order.h \
    fas/header/ordergenerator.h

DISTFILES += \

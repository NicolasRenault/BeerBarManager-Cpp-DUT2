import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtMultimedia 5.12

Window {
    visible: true
    width: maximumWidth
    height: maximumHeight
    visibility: "FullScreen"
    title: qsTr("Fast And Service")


    /*Audio {
        source: "ressources/background.mp3"
        autoPlay: true
        loops: Audio.Infinite
        audioRole: Audio.GameRole
        volume: 0.5
    }

    Audio {
        id: notifSound
        volume: 0.6
        audioRole: Audio.SonificationRole

        Connections {
            taget: player
            onFailed: {
                notifSound.source = "ressources/bad.mp3"
                notifSound.play()
            }
            onSuccess: {
                notifSound.source = "ressources/good.mp3"
                notifSound.play()
            }
        }
    }*/


    Rectangle {
        id: eventCatcher
        focus: true
        Keys.onPressed: {
            drink.moveDrink(event.key);
            if (!event.isAutoRepeat) fas.keyEventListener(event.key);
        }
    }

    Head {
        id: head
        anchors.top: parent.top
        z: 2
    }

    Rectangle {
        id: tap
        z: 2
        anchors.top: head.bottom
        height: tap1.height
        width: parent.width

        color: "#ffb59b"

        Row {
            leftPadding: parent.width / 10
            spacing: (parent.width - (leftPadding*2)) / 4

            Tap {

                id: tap1
                border.color: "red"
                border.width: {
                    if (fas.tapSelected == 0)
                        5
                    else 0
                }
                Liquid {
                    visible: tapObject0.actif
                    source: "qrc:ressources/beer-texture.jpg"
                }
            }
            Tap {
                id: tap2
                border.color: "red"
                border.width: {
                    if (fas.tapSelected == 1)
                        5
                    else 0
                }
                Liquid {
                    visible: tapObject1.actif
                    source: "qrc:ressources/beer-amber-texture.jpg"
                }
            }
            Tap {
                id: tap3
                border.color: "red"
                border.width: (fas.tapSelected == 2)? 5 : 0

                Liquid {
                    visible: tapObject2.actif
                    source: "qrc:ressources/beer-stout-texture.png"
                }
            }
            Tap {
                id: tap4
                border.color: "red"
                border.width: {
                    if (fas.tapSelected == 3)
                        5
                    else 0
                }
                Liquid {
                    visible: tapObject3.actif
                    source: "qrc:ressources/beer-white-texture.png"
                }
            }
        }
    }

    Image {
        id: workSpace
        z: 1

        anchors.top: tap.bottom
        anchors.bottom: parent.bottom
        width: parent.width

        source: "qrc:ressources/wood-texture.jpg"

        Glass {
            z: 11
        }
    }


}





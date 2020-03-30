import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.5

Window {
    id : wido
    width: maximumWidth
    height: maximumHeight
    visible: true
    visibility: "FullScreen"

    Column {
        id: column
        width: parent.width
        height: parent.height
        spacing : 20

        Column {
            id: column1
            width: parent.width/2
            height: button.height
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            spacing: parent.height/6

            Button {
                id: game1
                text: qsTr("Partie 1")
                font.pointSize: game1.width/10
                width: parent.width
                height: game1.width/4
                onClicked: {
                    var component = Qt.createComponent("qrc:game/bbm/gameGui.qml")
                    var window    = component.createObject(wido)
                    wido.close()
                    window.show()

                }

            }

            Button {
                id: game2
                text: qsTr("Partie 2")
                font.pointSize: game2.width/10
                width: parent.width
                height: game2.width/4



            }

            Button {
                id: game3
                text: qsTr("Partie 3")
                font.pointSize: game3.width/10
                width: parent.width
                height: game3.width/4



            }



        }
    }



}




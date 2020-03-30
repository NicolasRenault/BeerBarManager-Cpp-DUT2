import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Window {
    id : wido
    width: maximumWidth
    height: maximumHeight
    visibility: "FullScreen"
    visible: true

        Column {
            width: parent.width/2
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: parent.height/6

            Button {
                id: play
                text: qsTr("Jouer")
                font.pointSize: (play.width/10 == 0 ? 10 : play.width/10)
                width: parent.width
                height: play.width/4
                onClicked: {
                    let component = Qt.createComponent("qrc:menu/gameMenu.qml")
                    let window    = component.createObject(wido)
                    wido.close()
                    window.show()
                }

            }

            Button {
                id: apm
                text: qsTr("Fast & Service")
                font.pointSize: (apm.width/10 == 0 ? 10 : apm.width/10)
                width: parent.width
                height: apm.width/4

                onClicked:  {
                    wido.close()
                    game.startFAS()
                }

            }

            Button {
                id: notebook
                text: qsTr("NoteBook")
                font.pointSize: (notebook.width/10 == 0 ? 10 : notebook.width/10)
                width: parent.width
                height: notebook.width/4

                onClicked: {
                    wido.close()
                    game.startNotebook()
                }

            }
        }
}



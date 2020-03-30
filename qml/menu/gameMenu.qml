import QtQuick 2.13
import QtQuick.Dialogs 1.2
import QtQuick.Window 2.13
import QtQuick.Controls 2.5


Window{

    id : wido
    width: maximumWidth
    height: maximumHeight
    visibility: "FullScreen"
    visible: true

    Column {
        id: column
        width: parent.width
        height: parent.height


        Column {
            id: column1
            width: parent.width/2
            height: parent.height/2
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            spacing: parent.height/6

            Button {
                id: newGame
                text: qsTr("Nouvelle Partie")
                font.pointSize: newGame.width/10
                width: parent.width
                height: newGame.width/4
                onClicked: {
                    var component = Qt.createComponent("qrc:game/gameGui.qml")
                    var window    = component.createObject(wido)
                    wido.close()
                    window.show()


                }

            }


            /*MessageDialog {
                id: dialog
                title: "WIP"
                text: "This feature is not avaible yet !"
                standardButtons: StandardButton.OK
                Component.onCompleted: visible = true
            }*/

            Button {
                id: loadGame
                text: qsTr("Charger Partie")
                font.pointSize: loadGame.width/10
                width: parent.width
                height: loadGame.width/4
                onClicked: {
                    //var component = Qt.createComponent("qrc:menu/gameLoader.qml")
                    //var window    = component.createObject(wido)
                    //wido.close()
                    //window.show()

                }



            }


        }
    }
}



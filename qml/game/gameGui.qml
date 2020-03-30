import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.13

Window {
    id : wido
    width: maximumWidth
    height: maximumHeight
    visible: true


    Column{
        id : columnBar
        width: parent.width/2
        height: parent.height
        Button{
            id: menuBarButton
            text : "Action Bar"
            onClicked: {
                menuBar.open()
            }

        }

        Menu{
            id: menuBar
            y: menuBarButton.height

            MenuItem{
                text: "Catalogue"
            }

            MenuItem{
                text: "Paramètre du bar"
            }

            MenuItem{
                text: "Stock"
            }

            MenuItem{
                text: "Catalogue des bières"
            }
        }




        Row {
            id: rowDollar
            width: columnBar.width
            height: dollarImg.height

            Image {
                id: dollarImg
                width: 100
                height: 100
                source: "qrc:ressources/dollard.png"

            }

            Text {
                id: pognon
                text: bar.wallet
                font.pixelSize: 30
                anchors.verticalCenter: dollarImg.verticalCenter
            }
        }
        ScrollView{
            width: parent.width
            height: 50
            ScrollBar.horizontal.policy: ScrollBar.AlwaysOn
            ScrollBar.horizontal.interactive: true
            ScrollBar.vertical.interactive: true
            clip: true
        Row {
            id: rowCmd
            width: 100
            height: 50




                Text {
                    text: qsTr("Evènement : ")
                    font.pixelSize: 20
                }

                Text {
                    id: cmdToServ
                    text: qsTr("JE VEUX UNE BINOUSE!!!!!!!!!!!!!!!!")
                    font.pixelSize: 20

                    MouseArea{
                        anchors.fill: parent
                        onClicked: console.debug("oui")

                    }
                }

            }
        }


        StackView{
            id : stackBar
            width: columnBar.width
            height: columnBar.height
            Image {
                id: barImg
                width: stackBar.width
                height: stackBar.height
                source: "qrc:ressources/bar.jpg"
            }
            Rectangle{
                id: recBar
                width: stackBar.width
                height: stackBar.height
                border.color: "black"
                border.width: 10
                color: "transparent"
            }
        }
    }



    Column {
        id: columnBrass
        x : parent.width/2
        width: parent.width/2
        height: parent.height

        Row {
            id: rowTopRight
            width: parent.width
            height: menuBarButton.height


            Button{
                id: menuBrassButton
                text : "Action Brasserie"
                onClicked: {
                    menuBrass.open()
                }
            }

            Row{
                id: timeItem
                anchors.right: parent.right
                Text {
                    id: hour
                    text: qsTr("00")
                    font.pixelSize: 30
                    anchors.verticalCenter: menuBrassButton.verticalCenter
                }
                Text {
                    id: deuxPoint
                    text: qsTr(":")
                    font.pixelSize: 30
                    anchors.verticalCenter: menuBrassButton.verticalCenter

                }
                Text {
                    id: min
                    text: qsTr("00")
                    font.pixelSize: 30
                    anchors.verticalCenter: menuBrassButton.verticalCenter
                }

                Button{
                    width: 50
                    text: "||"
                }

                Button{
                    width: 50
                    text: ">>"
                }
            }
        }

        Row {
            id: popularRow
            width: columnBrass.width
            height: popularImg.height

            Image {
                id: popularImg
                width: 100
                height: 100
                source: "qrc:ressources/coonten.png"
            }
            Text {
                id: popularity
                text: bar.popularity
                font.pixelSize: 30
                anchors.verticalCenter: popularImg.verticalCenter
            }
        }

        Menu{
            id: menuBrass
            y: menuBrassButton.height

            MenuItem{
                text: "Créer une Bière"
                onClicked: {
                    var component = Qt.createComponent("qrc:game/beerForm.qml")
                    var window    = component.createObject(wido)
                    window.show()
                }
            }

            MenuItem{
                text: "Historique des bière"
            }


        }

        Row {
            id: rowLeastBeer
            width: 100
            height: 50

            Text {
                text: qsTr("Denière bière créer : ")
                font.pixelSize: 20
            }

            Text {
                id: lastBeer
                text: qsTr("Luffe")
                font.pixelSize: 20
            }
        }



        StackView {
            id: stackBrass
            width: columnBrass.width
            height: columnBrass.height
            Image {
                id: imageBrass
                width: stackBrass.width
                height: stackBrass.height
                source: "qrc:ressources/brasserie.jpg"
            }
            Rectangle{
                id: recBrass
                width: stackBrass.width
                height: stackBrass.height
                border.color: "black"
                border.width: 10
                color: "transparent"
            }

        }
    }
}

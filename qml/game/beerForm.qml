import QtQuick 2.13
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    visible: true
    width: 280
    height: 180
    maximumHeight: 180
    maximumWidth: 280
    minimumHeight: 180
    minimumWidth: 280
    title: qsTr("Atelier de création")


    Column {
        id: column
        spacing: 20

        Row {
            id: row

            ComboBox{
                id : comboMalty
                model: ["Extra Malty","Slightly Malty", "Evenly Balanced"]
            }

            ComboBox{
                id: comboHop
                model:["Houblon", "Vieux Houblon"]
            }
        }

        Column {
            id: column1

            Row {
                id: row2
                spacing :10

                Text {
                    id: nameBeerTxt
                    text: qsTr("Nom de la bière")
                    font.pixelSize: 12
                }

                Text {
                    id: prepTimeTxt
                    text: qsTr("Temps de cuisson")
                    font.pixelSize: 12
                }
            }

            Row {
                id: row1
                spacing: 10


                Rectangle {
                    id: rectangle
                    width: beerName.width
                    height: beerName.height
                    border.color: "black"
                    border.width: 1

                    TextInput {
                        id: beerName
                        width: nameBeerTxt.width
                        height: 20
                    }
                }

                Rectangle {
                    id: rectangle1
                    width: prepTime.width
                    height: prepTime.height
                    border.color: "black"
                    border.width: 1

                    TextInput {
                        id: prepTime
                        width: prepTimeTxt.width
                        height: 20
                        text: qsTr("000")
                        inputMask: "999"
                    }
                }
            }
        }
    }

    Button {
        id: button
        text: qsTr("valide")
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        onClicked: {
            game.createBeer(comboHop.currentText, comboMalty.currentText, prepTime.text, beerName.text)
            close() //TODO SA CLOSE TOUT
        }
    }

}


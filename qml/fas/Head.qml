import QtQuick 2.0

Rectangle {
    height: 50
    width: parent.width
    color: "#ffaa00"

    // POINT
    Rectangle {
        height: parent.height
        width: 200
        color: "#b96400"

        Text {
            id: points

            font.bold: true
            font.pointSize: 20

            text: "Points: " + player.point
            color: "white"

            Connections {
                target: player
                onSuccess:  {
                    points.color = "green";

                }

                onFailed: {
                    points.color = "red";
                }
            }
        }
    }


    // TIME
    Rectangle {
        id: time
        x: parent.width/2 - (width/2)
        height: parent.height
        width: 200
        color: "#b96400"

        Text {
            x: parent.width/2 - (width/2)

            font.bold: true
            font.pointSize: 20
            color: "white"

            text: Qt.formatTime(new Date(0, 0, 0, 0, 0, fas.time/60), "mm:ss")
        }
    }


    // INFO
    Rectangle {
        anchors.left: time.right
        height: parent.height
        width: 200

        color: "transparent"

        Text {
            id: info
            width: parent.width

            wrapMode: Text.Wrap

            font.bold: true
            font.pointSize: 12
            color: "white"

            Connections {
                target: fas
                onNoSwitch: {
                    info.text = "Tu ne peut pas changer de robinet !";
                }
            }
        }
    }


    // COMMANDE
    Order {
        anchors.right: parent.right
    }
}

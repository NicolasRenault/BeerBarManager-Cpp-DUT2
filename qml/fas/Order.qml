import QtQuick 2.0

Rectangle {
    id: container
    height: 50
    width: 150
    color: "#be7740"

    Rectangle {
        id: wait
        height: parent.height
        color: "#ff3030"

        Connections {
            target: order

            onTimeChanged: {
                wait.width = container.width * ( (order.maxtime- order.time )/ order.maxtime )
            }
        }

    }

    Text {
        id: title

        text: "Title: " + order.beer().name
        color: "white"
        font.pointSize: 15
    }

    Text {
        id: timeReaming
        anchors.top: title.bottom

        text: (order.time/60).toFixed(1) + " sec"
        color: "white"
        font.pointSize: 15
    }
}

import QtQuick 2.0

Rectangle {
    height: tap.height
    width: tap.width
    color: "transparent"

    Image {
        id: tap
        width: 100
        height: 100
        source: "qrc:/ressources/robinet.png"
    }
}

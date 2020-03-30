import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

RowLayout{
    id: bpLayout

    Button {

        id: bpSup
        objectName: "bpSup"
        text: "Suprimer"

        onClicked: {
        }
    }

    Button {

        id: bpVal
        objectName: "bpVal"
        text: "Valider"

        onClicked: {
        }
    }
}

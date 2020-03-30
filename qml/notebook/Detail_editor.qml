import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3


Column{
    spacing: columnSpacing
    width: parent.width
    height: parent.height


    property var txtInLgt: 20
    property var ht: {if (parent.height/5 > 15) parent.height/5; else 15}
    property var wd: {if (parent.width/4 > 15) parent.width/4; else 15}
    property var htRect: {if (children.height >= 15) children.height + 1; else 15}
    property var wdRect:  {if (children.width >= 11) children.width + 1; else 150}
    property var wdLabel: {if (Text.contentWidth >= 60) Text.contentWidth + 2 ; else 62} //parent.width/5
    property var bkgd: "#9B9B9B"
    property var rowSpacing: 2
    property var columnSpacing: 2

    Row{
        spacing: rowSpacing
        height: ht
        width: wd

        Text {
            width: wdLabel
            id: labelNameD
            objectName: "labelName"
            text: "<b>Nom</b>"
        }

        Rectangle{
            color: bkgd
            height: htRect
            width: wdRect
            border.width: 2
            border.color: "black"

            TextInput{
                id: nameD
                anchors.centerIn: parent
                objectName: "name"
                text: aleModel.beer?aleModel.beer.name:"null"
                maximumLength: txtInLgt
            }
        }


        Text {
            width: wdLabel
            id: labelTypeD
            objectName: "labelType"
            text: "<b>Type</b>"
        }

        Rectangle{
            border.width: 2
            border.color: "black"
            color: bkgd
            height: htRect
            width: wdRect

            TextInput{
                id: typeD
                objectName: "type"
                anchors.centerIn: parent
                text:aleModel.beer?aleModel.beer.type:"null"
                maximumLength: txtInLgt

            }
        }
    }

    Row{
        spacing: rowSpacing
        height: ht
        width: wd

        Text {
            width: wdLabel
            id: labelIBU
            objectName: "labelIBU"
            text: "<b>IBU</b>"
        }

        Rectangle{
            border.width: 2
            border.color: "black"
            color: bkgd
            height: htRect
            width: wdRect

            TextInput{
                id: ibu
                anchors.centerIn: parent
                objectName: "name"
                text: aleModel.beer?aleModel.beer.IBU:"null"
                maximumLength: txtInLgt
                inputMask: "999"
            }
        }


        Text {
            width: wdLabel
            id: labelColor
            objectName: "labelColor"
            text: "<b>Color</b>"
        }

        Rectangle{
            border.width: 2
            border.color: "black"
            color: bkgd
            height: htRect
            width: wdRect

            TextInput{
                id: color
                objectName: "color"
                anchors.centerIn: parent
                text:aleModel.beer?aleModel.beer.color:"null"
                maximumLength: txtInLgt

            }
        }
    }

    Row{
        spacing: parent.spacing
        height: ht
        width: wd

        Text {
            width: wdLabel
            id: labelVolD
            objectName: "labelVol"
            text: "<b>Vol %</b>"
        }
        Column{
            Rectangle{
                border.width: 2
                border.color: "black"
                color: bkgd
                height: htRect
                width: wdRect

                TextInput{

                    id: volD
                    objectName: "vol"
                    anchors.centerIn: parent
                    text: aleModel.beer?aleModel.beer.alcoholeLevels/10:"0"
                    inputMask: "99.99"

                    onTextChanged: {
                        //if(text != aleModel.beer?aleModel.beer.alcoholeLevels:"0") console.debug("textInput:",text);
                    }

                }
            }

            Slider {
                id: slideVol
                from:0
                to: 300
                stepSize: 1
                value: aleModel.beer?aleModel.beer.alcoholeLevels:0
                //onValueChanged: {if(value != aleModel.beer?aleModel.beer.alcoholeLevels:0) console.debug("slider:",value/10);}
            }
        }
        Text {
            width: wdLabel
            id: labelDensiteD
            objectName: "labelDensite"
            text: "<b>Densite</b>"
        }

        Rectangle{
            border.width: 2
            border.color: "black"
            color: bkgd
            height: htRect
            width: wdRect

            TextInput{
                id: densiteD
                objectName: "densite"
                anchors.centerIn: parent
                text: aleModel.beer?aleModel.beer.density:"null"
                maximumLength: txtInLgt                
                inputMask: "9999"

            }
        }
    }
}

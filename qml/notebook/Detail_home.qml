import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Row{

    spacing: columnSpacing
    antialiasing: true

    property var ht: {if (parent.height/6 >= 25) parent.height/6; else 25}
    property var wd: {if (parent.width/6 >= 25) parent.width/6; else 25}

    property var rowSpacing: 5
    property var columnSpacing: 5
    Column{
        Row{
            spacing: rowSpacing
            height: ht
            width: wd
            Label{
                width: wd
                id: labelName
                objectName: "labelName"
                text: "<b>Name</b>"
            }

            Text {
                id: name
                objectName: "name"
                text: aleModel.beer?aleModel.beer.name:"null"
            }

            Label{
                width: wd
                id: labelVol
                objectName: "labelVol"
                text: "<b>Vol %</b>"
            }

            Text {
                id: vol
                objectName: "vol"
                text: aleModel.beer?aleModel.beer.alcoholeLevels/10:"null"

            }

        }

        Row{
            spacing: rowSpacing
            height: ht
            width: wd
            Label{
                width: wd
                id: labelType
                objectName: "labelType"
                text: "<b>Type</b>"
            }

            Text {
                id: type
                objectName: "type"
                text:aleModel.beer?aleModel.beer.type:"null"
            }

            Label{
                width: wd
                id: labelDensite
                objectName: "labelDensite"
                text: "<b>Density</b>"
            }

            Text {
                id: densite
                objectName: "densite"
                text:aleModel.beer?aleModel.beer.density:"null"
            }
        }

        Row{
            spacing: rowSpacing
            height: ht
            width: wd

            Label{
                width: wd
                id: labelIBU
                objectName: "labelIBU"
                text: "<b>IBU</b>"
            }

            Text {
                id: ibu
                objectName: "ibu"
                text:aleModel.beer?aleModel.beer.IBU:"null"
            }

            Label{
                width: wd
                id: labelColor
                objectName: "labelcolor"
                text: "<b>Color</b>"
            }

            Text {
                id: color
                objectName: "color"
                text:aleModel.beer?aleModel.beer.color:"null"
            }
        }

        Row{
            spacing: rowSpacing
            height: ht
            width: wd

            Label{
                width: wd
                id: labelpreparation
                objectName: "labelPreparation"
                text: "<b>Prep time</b>"
            }

            Text {
                id: preparation
                objectName: "preparation"
                text:aleModel.beer?aleModel.beer.recipe.preparationTime:"null"
            }

            Label{
                width: wd
                id: labelingredient
                objectName: "labelIngredient"
                text: "<b>Ingredient(s)</b>"
            }
            ScrollView {
                width: parent.width
                height: parent.height
                ScrollBar.horizontal.policy: ScrollBar.AlwaysOn
                ScrollBar.vertical.policy: ScrollBar.AlwaysOn
                ScrollBar.horizontal.interactive: true
                ScrollBar.vertical.interactive: true
                clip: true
                ListView{
                    width: parent.width
                    height: parent.height
                    clip: true
                    model: aleModel.beer?aleModel.beer.recipe.getListIngredient:"null"


                    delegate: ItemDelegate {
                        Text {
                            id:item
                            text: " test"
                            width: parent.width
                        }
                    }
                }
            }
        }
    }
}


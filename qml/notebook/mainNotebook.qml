import QtQuick 2.12
import QtQuick.Window 2.11
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Window {
    visible: true
    width: 640
    height: 480
    minimumWidth: 480
    minimumHeight: 240
    title: qsTr("NoteBookBiere")

    Row{
        anchors.fill: parent
        focus: true
        spacing: 5
        id:aleModel
        property var beer : null

            Column{
                spacing: 5
                width: parent.width - detail.width
                id:master
                height: parent.height
                clip: true
                Master{
                    height: parent.height - bpAdd.height ;
                }

                Button{
                    width: parent.width
                    id: bpAdd
                    objectName: "bpAdd"
                    text: "Ajouter"

                    onClicked: {
                        //console.debug("Add Beer")
                        //  Beer(QString beerName, int beerAlcoholLevels, int beerIBU, int beerDensity, QString beerColor, QString beerType, Recipe* recipe);

                        // aleModel.addBeer(new aleModel.Beer("name",0,0,1000,"color","type",new aleModel.Recipe(0)))
                       // Qt.binding( function() { model.addBeer(new Beer("name",0,0,1000,"color","type",new aleModel.Recipe(0))) } )
                        model.addBeer(new Beer("name",0,0,1000,"color","type",new aleModel.Recipe(0)))
                    }
                }
            }


            Column{
                spacing: 5
                width: parent.width/(1.2)
                height: parent.height
                id:detail

                TabBar{
                    id: mybar
                    height: 42
                    width: parent.width


                    TabButton {
                        text: qsTr("Home")
                    }

                    TabButton {
                        text: qsTr("Editor")
                    }
                }
                StackLayout {
                    currentIndex: mybar.currentIndex
                    height: parent.height - mybar.height
                    width: parent.width


                    Item {
                        id: homeTab
                        Detail_home{}
                    }
                    Item {
                        id: editorTab

                        Column{
                            spacing: 2
                            width: parent.width
                            height: parent.height

                            Detail_editor{height: parent.height - bpEdit.height}
                            Button_editor{
                                id: bpEdit
                                anchors.right: parent.right
                            }
                        }
                    }
                }

            }
        }

}

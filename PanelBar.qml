import QtQuick 2.0
import QtQuick.Controls 2.2
import Models 1.0

Item {

    DirEntryModel {id: dirModel}

    TextField {
        id: diretory
        anchors.left: parent.left
        width: parent.width
        height: 30
    }

    ListView {
        id: directoryListView
        ScrollBar.vertical: ScrollBar {id: vbar}
        ScrollBar.horizontal: ScrollBar {id:hbar}
        anchors.left: parent.left
        anchors.top: diretory.bottom
        anchors.bottom: parent.bottom
        width: parent.width
        clip: true
        model: dirModel.model
        delegate: ItemDelegate {
            width: parent.width
            Text {
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 5
                text: edit
            }

            Component.onCompleted: {
                if(edit === ".") {
                    height = 0
                    visible = false
                }
            }
        }
    }
}

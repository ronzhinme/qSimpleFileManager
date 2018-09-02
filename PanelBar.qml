import QtQuick 2.0
import QtQuick.Controls 2.2
import Models 1.0

Item {

    DirEntryModel { id: dirModel }

    Connections {
        target: dirModel
        onCurDirChanged: {
            diretory.text = dirModel.curDir
        }
    }

    TextField {
        id: diretory
        anchors.left: parent.left
        width: parent.width
        height: 30
        text: dirModel.curDir
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
        model: dirModel

        delegate: ItemDelegate {
            width: parent.width
            height: 30

            Image {
                id: dirEntryImage
                width: 20
                height: 20
                anchors.verticalCenter: parent.verticalCenter
                source: edit.isDir ? "./images/Folder-Accept.png" : ""
            }

            Text {
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: dirEntryImage.right
                anchors.leftMargin: 5
                text: edit.fileName
            }

            Component.onCompleted: {
                if(edit.fileName === ".") {
                    height = 0
                    visible = false
                }
            }

            onDoubleClicked: {
                dirModel.doAction(edit)
            }
        }
    }


}

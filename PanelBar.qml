import QtQuick 2.11
import QtQuick.Controls 2.2
import Models 1.0

Item {

    property alias isTabFocused: directoryListView.focus

    DirEntryModel { id: dirModel }

    function onCurDirChanged() {
         diretory.text = dirModel.curDir
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
        highlight: Rectangle {
            color: isTabFocused ? "#aaaaaa" : "#dddddd";
            height: 20;
            width: directoryListView.width;
            y: directoryListView.currentItem ? directoryListView.currentItem.y : 0
            Behavior on y {
                SpringAnimation {
                    spring: 3
                    damping: 0.2
                }
            }
        }

        delegate: ItemDelegate {
            readonly property string fileName: edit.fileName
            width: directoryListView.width
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
                text: fileName
            }

            Component.onCompleted: {
                if(edit.fileName === ".") {
                    height = 0
                    visible = false
                }
            }

            onClicked: {
                directoryListView.currentIndex = index
            }

            onDoubleClicked: {
                dirModel.doAction(edit)
            }
        }

        onCurrentIndexChanged: {
            if(currentItem.fileName === ".") currentIndex = 1
        }

        Keys.onPressed: {
            if(event.key === Qt.Key_Return || event.key === Qt.Key_Enter) {
                dirModel.doAction(currentIndex)
                currentIndex = 0
                if(currentItem.fileName === ".") currentIndex = 1
            }
        }
    }
}

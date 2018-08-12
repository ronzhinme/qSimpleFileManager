import QtQuick 2.0
import QtQuick.Controls 2.2

Item {

    TextField {
        id: diretory
        anchors.left: parent.left
        width: parent.width
        height: 30
    }

    ListView {
        id: directoryListView
        anchors.left: parent.left
        anchors.top: diretory.bottom
        anchors.bottom: parent.bottom
        width: parent.width
    }
}

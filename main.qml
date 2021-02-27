import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.13

Window {
    id: appMainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("qSimpleFileManager")

    property bool isLeftTabActive: true
    property Window mainWindow: appMainWindow

    Rectangle {
        id: mainMenuBar
        anchors.top: parent.top
        width: parent.width
        height: 30
        color: "#aaaaaa"
    }

    SplitView {
        id: splitView
        anchors.top: mainMenuBar.bottom
        anchors.bottom: buttonsBar.top
        anchors.left: parent.left
        anchors.right: parent.right
        orientation: Qt.Horizontal
        handle: Rectangle {
            implicitWidth: 5
            implicitHeight: 5
            color: splitView.pressed ? "#999999" : SplitHandle.hovered ? Qt.lighter("#aaaaaa", 1.1): "#aaaaaa"
        }

        PanelBar {
            id: leftBar
            SplitView.preferredWidth: splitView.width / 2
            SplitView.minimumWidth: 100
            isTabFocused: isLeftTabActive
        }

        PanelBar {
            id: rightBar
            SplitView.preferredWidth: splitView.width / 2
            SplitView.minimumWidth: 100
            isTabFocused: !isLeftTabActive
        }
    }

    Rectangle {
        id: buttonsBar
        anchors.bottom: statusBar.top
        width: parent.width
        height: 30
        color: "#999999"
    }

    Rectangle {
        id: statusBar
        anchors.bottom: parent.bottom
        width: parent.width
        height: 30
        color: "#aaaaaa"
    }

    Shortcut {
        sequence: "Tab"
        context: "ApplicationShortcut"
        onActivated: {
            isLeftTabActive = !isLeftTabActive
        }
    }
}

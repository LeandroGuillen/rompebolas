import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Dialogs 1.1


ApplicationWindow {
    id: applicationWindow1
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    statusBar: StatusBar {
        Text {
            id: textStatusBar
            text: "Score: 0"
            onTextChanged: debuggerWindow.append(text)
        }
    }

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")

            MenuItem {
                text: qsTr("&New Game")
                onTriggered: reload();
            }

            MenuItem {
                text: qsTr("&Settings...")
                onTriggered: settingsDialog.open()
            }

            MenuItem {
                text: qsTr("Show &debugger")
                checkable: true
                checked: true
                onCheckedChanged: debuggerWindow.visible = checked

            }

            MenuItem {
                text: qsTr("&Exit")
                onTriggered: Qt.quit();
            }
        }
    }


    Tablero {
        id: tablero
        onScoreChanged: {
            textStatusBar.text = "Score: " + score
        }

        onClick: {
            textStatusBar.text = "clicked (" + x +", " + y + "): "+ type
            tablero.score = tablero.score + type
        }
    }

    DebuggerWindow {
        id: debuggerWindow
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 448
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 480
        Component.onCompleted: visible = true
    }

    MessageDialog {
        id: settingsDialog
        title: "Settings"
        text: "This is the settings dialog. Impressive."
        onAccepted: {
            console.log("Cliked Ok.")
        }
    }

    Button {
        id: button1
        x: 552
        y: 8
        text: qsTr("Button")
        onClicked: {
            tablero.score = tablero.score + 3
        }
    }

    function reload()
    {

    }
}

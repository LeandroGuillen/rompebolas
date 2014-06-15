import QtQuick 2.0
import QtGraphicalEffects 1.0

Image {

    property int type: 0
    property string state: "NORMAL"

    onStateChanged: {
        rect.state = state
    }

    source: {
        if(type == 0){
            "qrc:///bola/roja.png"
        } else if(type == 1) {
            "qrc:///bola/azul.png"
        } else if(type == 2) {
            "qrc:///bola/rosa.png"
        } else if(type == 3) {
            "qrc:///bola/verde.png"
        } else {
            "qrc:///bola/amarilla.png"
        }
    }

    Rectangle {
        id: rect
        anchors.fill: parent
        border.width: 0
        color: "transparent"
        state: "NORMAL"

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: rect.state = "HOVER"
            onExited: rect.state = "NORMAL"
        }

        states: [
            State {
                name: "NORMAL"
                PropertyChanges {
                    target: rect
                    border.width: 0
                    border.color: "black"
                }

            },
            State {
                name: "HOVER"
                PropertyChanges {
                    target: rect
                    border.width: 2
                    border.color: "white"
                }
            }
        ]

        transitions: [
            Transition {
                from: "NORMAL"
                to: "HOVER"
                PropertyAnimation{ target: rect; duration: 100}
                ColorAnimation{ target: rect; duration: 100}
            },
            Transition {
                from: "HOVER"
                to: "NORMAL"
                PropertyAnimation{ target: rect; duration: 100}
                ColorAnimation{ target: rect; duration: 100}
            }
        ]


    }




}

import QtQuick 2.2
import QtQuick.Controls 1.1

Rectangle {
    Text {
        id: text1
        x: 8
        y: 250
        text: qsTr("Debug info:")
        font.pixelSize: 12
    }

    TextArea {
        id: textArea1
        x: 8
        y: 269
        width: 624
        height: 203
        readOnly: true
        textColor: "#1e1b1a"
    }

    function setScore(score)
    {
        append("Score: " + score)
    }
    function append(text)
    {
        textArea1.append(text)
    }
}

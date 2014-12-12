import QtQuick 2.0
import QtQuick.Controls 1.0


ApplicationWindow {
    visible: true
    width: 1280
    height: 800
    Column {
        anchors.fill: parent
        anchors.margins: 4
        Repeater {
            model: maze.cells
            delegate: Row {
                id: innerView
                property int innerIndex: index
                width: parent.width
                height: childrenRect.height
                Repeater {
                    model: cells
                    delegate: Triangle {
                        col: index
                        row: innerView.innerIndex
                        width: lineLength / 2
                        lineLength: 48
                        cellValue: modelData
                        Component.onCompleted: console.log(col + ":" + row)
                    }
                }
            }
        }
    }
}

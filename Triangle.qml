import QtQuick 2.0

Item {
    property real lineLength: 32
    property int cellValue: 0
    property int row: 0
    property int col: 0

    x: col/2 * lineLength
    y: 0
    //y: (Math.sqrt(3)/2*lineLength * row)
    width: lineLength
    height: (Math.sqrt(3)/2*lineLength)

    property color lineColor: "#77000000"
    property real lineWidth: 4

    property real x1: lineLength / 2
    property real x2: 0
    property real x3: lineLength
    property real y1: ((col + row) % 2) ? 0 : Math.sqrt(3) / 2 * lineLength
    property real y2: ((col + row) % 2) ? Math.sqrt(3) / 2 * lineLength : 0
    property real y3: ((col + row) % 2) ? Math.sqrt(3) / 2 * lineLength : 0

    Line {
        id: left
        visible: parent.cellValue & 0x1
        height: parent.lineWidth
        color: parent.lineColor
        x1: parent.x1
        x2: parent.x2
        y1: parent.y1
        y2: parent.y2
    }
    Line {
        id: bottom
        visible: parent.cellValue & 0x2
        height: parent.lineWidth
        color: parent.lineColor
        x1: parent.x1
        x2: parent.x3
        y1: parent.y1
        y2: parent.y3
    }
    Line {
        id: right
        visible: parent.cellValue & 0x4
        height: parent.lineWidth
        color: parent.lineColor
        x1: parent.x2
        x2: parent.x3
        y1: parent.y2
        y2: parent.y3
    }
}

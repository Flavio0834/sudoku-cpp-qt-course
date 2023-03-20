import QtQuick

Window {
    width: 480
    height: 640
    visible: true
    title: qsTr("Hello World")

    Grid {
        id: grid
        x: 40
        y: 120
        width: 400
        height: 400
        verticalItemAlignment: Grid.AlignVCenter
        horizontalItemAlignment: Grid.AlignHCenter
        spacing: 3
        rows: 9
        columns: 9

        Rectangle {
            id: rectangle
            width: 40
            height: 40
            color: "#ffffff"
        }
    }
}

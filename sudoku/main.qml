import QtQuick

Window {
    width: 360
    height: 360
    visible: true
    title: qsTr("Hello World")

    Grid {
        id: sudokuGrid
        columns: 9
        rows: 9
        width: 360 // set the width of the grid (9 rectangles * 40 pixels per rectangle)
        height: 360 // set the height of the grid (9 rectangles * 40 pixels per rectangle)

        Repeater {
            id : repeater
            model: 81 // 9 rows * 9 columns
            Rectangle {
                width: 40
                height: 40
                color: "white"
                border.color: "black"
                border.width: 1

                MouseArea {
                    anchors.fill: parent
                    acceptedButtons: Qt.LeftButton
                    hoverEnabled: true
                    onClicked: {
                        grid.select(index) //index value = index of the rectangle
                    }
                }

                Text {
                    text: grid.getValue(index).toString() === "0" ? " " : grid.getValue(index).toString()
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                }
            }
        }
    }
}

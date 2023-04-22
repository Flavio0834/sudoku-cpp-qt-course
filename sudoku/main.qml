import QtQuick
import QtQuick.Window



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

        Keys.onPressed: {
                switch(event.key) {
                    case Qt.Key_Backspace:
                        grid.setValue("s");
                        break;
                    case Qt.Key_1:
                        grid.setValue("1");
                        break;
                    case Qt.Key_2:
                        grid.setValue("2");
                        break;
                    case Qt.Key_3:
                        grid.setValue("3");
                        break;
                    case Qt.Key_4:
                        grid.setValue("4");
                        break;
                    case Qt.Key_5:
                        grid.setValue("5");
                        break;
                    case Qt.Key_6:
                        grid.setValue("6");
                        break;
                    case Qt.Key_7:
                        grid.setValue("7");
                        break;
                    case Qt.Key_8:
                        grid.setValue("8");
                        break;
                    case Qt.Key_9:
                        grid.setValue("9");
                        break;
                }
            }



        Repeater {
            id : repeater
            model: 81 // 9 rows * 9 columns
            Rectangle {
                width: 40
                height: 40
                color: grid.qml_sudokuColors[index]
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
                    text: grid.qml_sudokuValues[index].toString() ==='0' ? ' ' : grid.qml_sudokuValues[index].toString()
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                    font.bold: grid.getIsSudokuValuesFixed()[index]



                }
            }
        }
    }
}

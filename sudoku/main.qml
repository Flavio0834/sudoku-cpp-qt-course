import QtQuick 2.15
import QtQuick.Window 2.15



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
        focus : true
        Keys.onPressed: {
                switch(event.key) {
                    case Qt.Key_Backspace:
                        grid.setValue(0);
                        break;
                    case Qt.Key_Delete:
                        grid.setValue(0);
                        break;
                    case Qt.Key_1:
                        grid.setValue(1);
                        break;
                    case Qt.Key_Ampersand:
                        grid.setValue(1);
                        break;
                    case Qt.Key_2:
                        grid.setValue(2);
                        break;
                    case Qt.Key_Eacute:
                        grid.setValue(2);
                        break;
                    case Qt.Key_3:
                        grid.setValue(3);
                        break;
                    case Qt.Key_QuoteDbl:
                        grid.setValue(3);
                        break;
                    case Qt.Key_4:
                        grid.setValue(4);
                        break;
                    case Qt.Key_Apostrophe:
                        grid.setValue(4);
                        break;
                    case Qt.Key_5:
                        grid.setValue(5);
                        break;
                    case Qt.Key_ParenLeft:
                        grid.setValue(5);
                        break;
                    case Qt.Key_6:
                        grid.setValue(6);
                        break;
                    case Qt.Key_Minus:
                        grid.setValue(6);
                        break;
                    case Qt.Key_7:
                        grid.setValue(7);
                        break;
                    case Qt.Key_Egrave:
                        grid.setValue(7);
                        break;
                    case Qt.Key_8:
                        grid.setValue(8);
                        break;
                    case Qt.Key_Underscore:
                        grid.setValue(8);
                        break;
                    case Qt.Key_9:
                        grid.setValue(9);
                        break;
                    case Qt.Key_Ccedilla:
                        grid.setValue(9);
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
                        grid.select(index); //index value = index of the rectangle
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

import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 6.3

Window {
    width: 360
    height: 442
    visible: true
    title: qsTr("Hello World")
    color: grid.qml_theme === 0 ? "#ffffff" : grid.qml_theme === 1 ? "#AAB7B8" : grid.qml_theme === 2 ? "#5D6D7E" : "#5DADE2"

    Grid {
        id: sudokuGrid
        x: 0
        y: 52
        columns: 9
        rows: 9
        width: 360 // Set the width of the grid (9 rectangles * 40 pixels per rectangle)
        height: 360 // Set the height of the grid (9 rectangles * 40 pixels per rectangle)
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
                id: rectangle6
                width: 40
                height: 40
                color: grid.qml_theme === 0 ? "#ffffff" : grid.qml_theme === 1 ? "#AAB7B8" : grid.qml_theme === 2 ? "#5D6D7E" : "#5DADE2"
                border.color: "black"
                border.width: 1

                MouseArea {
                    anchors.fill: parent
                    acceptedButtons: Qt.LeftButton
                    hoverEnabled: true
                    onClicked: {
                        grid.select(index); // Index value = index of the rectangle
                    }
                }

                Text {
                    text: grid.qml_sudokuValues[index].toString() ==='0' ? ' ' : grid.qml_sudokuValues[index].toString()
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                    font.bold: grid.qml_isSudokuValueFixed[index]
                }


            }
        }
    }

    Rectangle {
        id: rectangle1
        width: 360
        height: 52
        color: grid.qml_theme === 0 ? "#ffffff" : grid.qml_theme === 1 ? "#AAB7B8" : grid.qml_theme === 2 ? "#5D6D7E" : "#5DADE2"

        Rectangle {
            id: rectangle
            x: 1
            y: 3
            width: 178
            height: 20
            color: grid.qml_theme === 0 ? "#ffffff" : grid.qml_theme === 1 ? "#AAB7B8" : grid.qml_theme === 2 ? "#5D6D7E" : "#5DADE2"
            radius: 10
            border.width: 2

            MouseArea {
                id: mouseArea
                anchors.fill: parent
                onClicked: {
                    grid.loadGrid();
                }
            }

            Text {
                id: text1
                text: qsTr("Relancer une partie")
                anchors.fill: parent
                font.pixelSize: 12
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        Rectangle {
            id: rectangle2
            x: 181
            y: 3
            width: 178
            height: 20
            color: grid.qml_theme === 0 ? "#ffffff" : grid.qml_theme === 1 ? "#AAB7B8" : grid.qml_theme === 2 ? "#5D6D7E" : "#5DADE2"
            radius: 10
            border.width: 2

            MouseArea {
                id: mouseArea1
                anchors.fill: parent
                onClicked: {
                    grid.changeDifficulty();
                }
            }

            Text {
                id: text2
                text: grid.qml_difficulty === 0 ? "Débutant" : grid.qml_difficulty === 1 ? "Facile" : grid.qml_difficulty === 2 ? "Moyen" : "Difficile"
                anchors.fill: parent
                font.pixelSize: 12
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        Rectangle {
            id: rectangle3
            x: 1
            y: 29
            width: 178
            height: 20
            color: grid.qml_theme === 0 ? "#ffffff" : grid.qml_theme === 1 ? "#AAB7B8" : grid.qml_theme === 2 ? "#5D6D7E" : "#5DADE2"
            radius: 10
            border.width: 2
            MouseArea {
                id: mouseArea2
                anchors.fill: parent
                onClicked: {
                    grid.saveGrid();
                }
            }

            Text {
                id: text3
                text: qsTr("Sauvegarder")
                anchors.fill: parent
                font.pixelSize: 12
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        Rectangle {
            id: rectangle4
            x: 181
            y: 29
            width: 178
            height: 20
            color: grid.qml_theme === 0 ? "#ffffff" : grid.qml_theme === 1 ? "#AAB7B8" : grid.qml_theme === 2 ? "#5D6D7E" : "#5DADE2"
            radius: 10
            border.width: 2
            MouseArea {
                id: mouseArea3
                anchors.fill: parent
                onClicked: {
                    grid.loadSavedGrid();
                }
            }

            Text {
                id: text4
                text: qsTr("Charger")
                anchors.fill: parent
                font.pixelSize: 12
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
    }

    Rectangle {
        id: rectangle5
        x: 91
        y: 417
        width: 178
        height: 20
        color: grid.qml_theme === 0 ? "#ffffff" : grid.qml_theme === 1 ? "#AAB7B8" : grid.qml_theme === 2 ? "#5D6D7E" : "#5DADE2"
        radius: 10
        border.width: 2
        MouseArea {
            id: mouseArea4
            anchors.fill: parent
            onClicked: {
                grid.changeTheme();
            }
        }

        Text {
            id: text5
            text: qsTr("Thème")
            anchors.fill: parent
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }
}

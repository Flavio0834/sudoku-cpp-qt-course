#ifndef GRID_H
#define GRID_H

#include <QObject>
#include <QList>

class Grid : public QObject {
    Q_OBJECT
    Q_PROPERTY(QList<int> qml_sudokuValues READ getSudokuValues NOTIFY sudokuValuesChanged)
    Q_PROPERTY(QList<QString> qml_sudokuColors READ getSudokuColors NOTIFY sudokuColorsChanged)
public:
    Grid(QObject *parent = nullptr);
    Q_INVOKABLE void select(int id);
    Q_INVOKABLE QList<int> getSudokuValues() const {
        return sudokuValues;
    }
    Q_INVOKABLE QList<QString> getSudokuColors() const {
        return sudokuColors;
    }
    Q_INVOKABLE QList<bool> getIsSudokuValuesFixed() const {
        return isSudokuValuesFixed;
    }
    Q_INVOKABLE void setValue(char val);
    Q_INVOKABLE void setColor();
    Q_INVOKABLE void loadGrid();
    Q_INVOKABLE QList<int> getComparedCellsList(int id);
private:
    QList<int> sudokuValues;
    QList<bool> isSudokuValuesFixed;
    QList<QString> sudokuColors;
    int selected;
signals:
    void sudokuValuesChanged();
    void sudokuColorsChanged();
};

#endif // GRID_H

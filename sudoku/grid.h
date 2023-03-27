#ifndef GRID_H
#define GRID_H

#include <QObject>
#include <QList>

class Grid : public QObject {
    Q_OBJECT
    Q_PROPERTY(QList<int> cellValues READ getSudokuValues NOTIFY sudokuValuesChanged)
public:
    Grid(QObject *parent = nullptr);
    Q_INVOKABLE void select(int id);
    Q_INVOKABLE int getValue(int id);
    Q_INVOKABLE QList<int> getSudokuValues() const {
        return sudokuValues;
    }
    Q_INVOKABLE void setValue(int id,int val);
    Q_INVOKABLE void loadGrid();
private:
    QList<int> sudokuValues;
    int selected;
signals:
    void sudokuValuesChanged();
};

#endif // GRID_H

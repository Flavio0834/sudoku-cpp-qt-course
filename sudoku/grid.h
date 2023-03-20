#ifndef GRID_H
#define GRID_H

#include <QObject>

class Grid : public QObject {
    Q_OBJECT
public:
    Grid(QObject *parent = nullptr);
    Q_INVOKABLE int getValue(int row, int col);
    Q_INVOKABLE void setValue(int row, int col, int value);
private:
    int matrix[9][9];
signals:
    void valueChanged(int row, int col, int value);
};

#endif // GRID_H

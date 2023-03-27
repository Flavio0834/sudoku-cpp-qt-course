#include "grid.h"
#include <iostream>
#include <QList>

Grid::Grid(QObject *parent)
    : QObject(parent)
{
    QList<int> sudokuValues;
    sudokuValues.fill(0, 81);
    int selected = 0;
    std::cout << selected << std::endl;
}

void Grid::select(int id) {
    selected = id;
    std::cout << id << std::endl;
    emit sudokuValuesChanged();
}

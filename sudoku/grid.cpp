#include "grid.h"

Grid::Grid(QObject *parent)
    : QObject(parent)
{
    // Initialisation du tableau de la grille
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            matrix[i][j] = 0;
        }
    }
}

int Grid::getValue(int row, int col)
{
    return matrix[row][col];
}

void Grid::setValue(int row, int col, int value)
{
    matrix[row][col] = value;
    // Mettre à jour l'affichage de la grille dans l'interface utilisateur
    emit valueChanged(row, col, value);
}

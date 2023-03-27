#include "grid.h"

Grid::Grid(QObject *parent)
    : QObject(parent)
{
    // Initialisation du tableau de la grille
    for (int i = 0; i < 81;i++)
    {
            list[i] = 0;
        }
    }


int Grid::getValue(int id)
{
    return list[id];
}

void Grid::setValue(int id, int value)
{
    list[id] = value;
    // Mettre à jour l'affichage de la grille dans l'interface utilisateur
    emit valueChanged(id, value);
}
void Grid::select(int id)
{

}

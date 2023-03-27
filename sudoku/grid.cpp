#include "grid.h"
#include <iostream>
#include <QList>
#include <fstream>
#include <sstream>

Grid::Grid(QObject *parent)
    : QObject(parent)
{
    sudokuValues.fill(0, 81);
    int selected = 0;
    loadGrid();


}



void Grid::select(int id) {
    selected = id;
    std::cout << id << std::endl;
    emit sudokuValuesChanged();
}

void Grid::setValue(int id,int val)
{
    sudokuValues[id] = val;
    emit sudokuValuesChanged();
}

int Grid::getValue(int id)
{
    return sudokuValues[id];
}

void Grid::loadGrid()
{
    auto ss = std::ostringstream{};
    std::string filePath = "grilles\\grille" + std::to_string(rand() % 2) + ".csv"; // ici on a 2 car on a que 2 grilles
    std::ifstream input_file(filePath);
    if (!input_file.is_open()) {
        std::cerr << "Could not open the file - '" << filePath << "'" << std::endl;
        exit(EXIT_FAILURE);
    }
    ss << input_file.rdbuf();
    std::string file_contents = ss.str();
    //std::cout << file_contents;

    int i = 0;

    for (char c : file_contents) {
        if (c == '.') {
            sudokuValues[i] = 0;
            i++;
            //std::cout << i << std::endl;
        }
        else if (i == 81)
            {
                break;
        }
        else if (c != '|' and c!='\n') {
            sudokuValues[i] = c - '0';
            i++;
            //std::cout << i << std::endl;
        }
    }

    std::cout << "chargement de la grille terminé" << std::endl;



}

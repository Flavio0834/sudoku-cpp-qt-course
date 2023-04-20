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

void Grid::setValue(char val)
{

    std::cout << "oui" << std::endl;
    const int id = selected;
    if (val == 's') { // suppr
        sudokuValues[id] = 0;
    }
    else {
        sudokuValues[id] = std::stoi(std::string(1,val));
    }
    emit sudokuValuesChanged();
}

int Grid::getValue(int id)
{
    //std::cout << id + ' ' +sudokuValues[id]  << std::endl;
    return sudokuValues[id];
}

void Grid::loadGrid()
{
    auto ss = std::ostringstream{};
    std::string filePath = "..\\grilles\\grille" + std::to_string(rand() % 2) + ".csv"; // ici on a 2 car on a que 2 grilles
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
            //std::cout << c - '0' << std::endl;
        }
    }
    emit sudokuValuesChanged();
    std::cout << "chargement de la grille terminé" << std::endl;



}

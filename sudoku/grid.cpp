#include "grid.h"
#include <iostream>
#include <QList>
#include <fstream>
#include <sstream>


Grid::Grid(QObject *parent)
    : QObject(parent)
{
    sudokuValues.fill(0, 81);
    sudokuColors.fill("white",81);
    int selected = 0;
    loadGrid();


}


void Grid::select(int id) {
    selected = id;
    std::cout << "case sélectionnée : " << id << std::endl;
    //sudokuValues[id] = 9; //debug click
    //emit sudokuValuesChanged();
    setColor();
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

void Grid::setColor() {
    const int id = selected;
    sudokuColors.fill("white",81);

    int row = (id+1)/9;
    int column = id%9;
    std::cout << row << ' ' << column << std::endl;

    for (int i = 0 ; i < 9 ; i++){
        sudokuColors[9*row + i] = "#C1FFC8"; //colorize the row
        sudokuColors[i*9 + column] = "#C1FFC8"; //colorize the column
        std::cout << 9*row + i << ' ' << i*row + column << std::endl;
    }

    //indices of the block
    int row_block = row/3;
    int column_block = column/3;

    //colorizing the block

    for (int j = 0 ; j < 3 ; j++) {
        sudokuColors[9*(3*row_block) + 3*column_block + j] = "#C1FFC8";
        sudokuColors[9*(3*row_block+1) + 3*column_block + j] = "#C1FFC8";
        sudokuColors[9*(3*row_block+2) + 3*column_block + j] = "#C1FFC8";
    }

    sudokuColors[id] = "#77FF90";

    emit sudokuColorsChanged();
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

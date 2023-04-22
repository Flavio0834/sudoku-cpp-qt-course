#include "grid.h"
#include <iostream>
#include <QList>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>


Grid::Grid(QObject *parent)
    : QObject(parent)
{
    sudokuValues.fill(0, 81);
    sudokuColors.fill("white",81);
    isSudokuValuesFixed.fill(false,81);
    int selected = 0;
    loadGrid();


}


void Grid::select(int id) {
    if (!isSudokuValuesFixed[id]) {
        selected = id;
        //std::cout << "case sélectionnée : " << id << std::endl;
        setColor();
        //setValue(1); //debug click
    }
}

void Grid::setValue(int val)
{
    setColor();
    int id = selected;
    if (val == 0) { // suppr
        sudokuValues[id] = 0;
        std::cout << "suppr" << std::endl;
    }
    else {
        QList<int> comparedCellsList = getComparedCellsList(id);
        bool canModifyValue = true;
        QList<int> idCellInConflict;
        for (int i = 0 ; i < 20 ; i++) {
            if (sudokuValues[comparedCellsList[i]] == val) { //check if there is no conflict in modifying the value of the cell
                canModifyValue = false;
                idCellInConflict.append(comparedCellsList[i]);
            }
        }
        if (canModifyValue) {
            sudokuValues[id] = val;
        }
        else {
            for (int i = 0 ; i < idCellInConflict.length() ; i++){
                sudokuColors[idCellInConflict[i]] = "red";
            }
            emit sudokuColorsChanged();
        }
    }
    emit sudokuValuesChanged();
}

QList<int> Grid::getComparedCellsList(int id) {
    QList<int> comparedCellsList;

    int row = (id)/9;
    int column = id%9;
    int row_block = row/3;
    int column_block = column/3;

    for (int i = 0 ; i < 9 ; i++){ // adding cells of the row and collumn
        if (((i*9 + column )/9)/3 != row_block){
            comparedCellsList.append(i*9 + column);
        }
        if (((9*row + i)%9)/3 != column_block) {
            comparedCellsList.append(9*row + i);
        }
    }

    for (int i = 0 ; i < 3 ; i++) { //adding the 8 values of the block
        for (int j = 0 ; j < 3 ; j++) {
            if (9*(3*row_block+i) + 3*column_block + j != id){
                comparedCellsList.append(9*(3*row_block+i) + 3*column_block + j);
            }
        }
    }
    //for (int i = 0 ; i < 20 ; i++){
    //    std::cout << comparedCellsList[i] << ' ';
    //}
    //std::cout << std::endl;
    return comparedCellsList;
}

void Grid::setColor() {
    const int id = selected;
    sudokuColors.fill("white",81);
    QList<int> comparedCellsList = getComparedCellsList(id);

    for (int i = 0 ; i < 20 ; i++) {
        sudokuColors[comparedCellsList[i]] = "#C1FFC8";
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
            isSudokuValuesFixed[i] = true;
            i++;
            //std::cout << c - '0' << std::endl;
        }
    }
    emit sudokuValuesChanged();
    std::cout << "chargement de la grille terminé" << std::endl;



}

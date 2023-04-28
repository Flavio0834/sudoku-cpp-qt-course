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

    selected = new int;
    difficulty = new int;
    *selected = 0;
    *difficulty = 0; // Default = Beginner

    loadGrid(); // Start a game
}

Grid::~Grid() {
    delete selected;
    delete difficulty;
    selected = 0;
    difficulty = 0;
}


void Grid::select(int id) {
    if (!isSudokuValueFixed[id]) { // If the value of the cell is predefined, the player can't access it
        *selected = id;
        setColor();
    }
}

void Grid::setValue(int val)
{
    setColor();
    int id = *selected;
    if (val == 0) { // Emptying the cell
        sudokuValues[id] = 0;
    }
    else {
        QList<int> comparedCellsList = getComparedCellsList(id);
        bool canModifyValue = true;
        QList<int> idCellInConflict;
        if (isSudokuValueFixed[id]) {
            canModifyValue = false;
        }
        else {
            for (int i = 0 ; i < 20 ; i++) {
                if (sudokuValues[comparedCellsList[i]] == val) { // Check if there is no conflict in modifying the value of the cell
                    canModifyValue = false;
                    idCellInConflict.append(comparedCellsList[i]);
                }
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

    if (hasWon()) {
        setFinalColors();
        loadGrid();
    }
}

bool Grid::hasWon() {
    return !sudokuValues.count(0);
}

QList<int> Grid::getComparedCellsList(int id) {
    QList<int> comparedCellsList;

    int row = (id)/9;
    int column = id%9;
    int row_block = row/3;
    int column_block = column/3;

    for (int i = 0 ; i < 9 ; i++){ // Adding cells of the row and collumn
        if (((i*9 + column )/9)/3 != row_block){
            comparedCellsList.append(i*9 + column);
        }
        if (((9*row + i)%9)/3 != column_block) {
            comparedCellsList.append(9*row + i);
        }
    }

    for (int i = 0 ; i < 3 ; i++) { // Adding the 8 values of the block
        for (int j = 0 ; j < 3 ; j++) {
            if (9*(3*row_block+i) + 3*column_block + j != id){
                comparedCellsList.append(9*(3*row_block+i) + 3*column_block + j);
            }
        }
    }
    return comparedCellsList;
}

void Grid::setColor() {
    const int id = *selected;
    sudokuColors.fill("white",81);
    QList<int> comparedCellsList = getComparedCellsList(id);

    for (int i = 0 ; i < 20 ; i++) {
        sudokuColors[comparedCellsList[i]] = "#C1FFC8";
    }

    sudokuColors[id] = "#77FF90";

    emit sudokuColorsChanged();
}

void Grid::setFinalColors() {
    sudokuColors.fill("#C1FFC8",81);
    emit sudokuColorsChanged();
}

void Grid::loadGrid()
{
    // File reading
    auto ss = std::ostringstream{};
    std::string filePath = "..\\grilles\\grille" + std::to_string(*difficulty) + ".csv";
    std::ifstream input_file(filePath);
    if (!input_file.is_open()) {
        std::cerr << "Could not open the file - '" << filePath << "'" << std::endl;
        exit(EXIT_FAILURE);
    }
    ss << input_file.rdbuf();
    std::string file_contents = ss.str();

    // Creating the grid
    int i = 0;

    isSudokuValueFixed.fill(false,81); // Reset bold and unaccessable cells values

    for (char c : file_contents) {
        if (c == '.') {
            sudokuValues[i] = 0;
            i++;
        }
        else if (i == 81)
            {
                break;
        }
        else if (c != '|' and c!='\n') {
            sudokuValues[i] = c - '0';
            isSudokuValueFixed[i] = true;
            i++;
        }
    }

    if (selected) {
        *selected=NULL;
        sudokuColors.fill("white",81);
    }
    emit sudokuValuesChanged();
    emit sudokuColorsChanged();
    emit sudokuGridChanged(); // Reset bold and unaccessable cells QML side
}

Q_INVOKABLE QList<int> Grid::getSudokuValues() const {
    return sudokuValues;
}

Q_INVOKABLE QList<QString> Grid::getSudokuColors() const {
    return sudokuColors;
}

Q_INVOKABLE QList<bool> Grid::getIsSudokuValueFixed() const {
    return isSudokuValueFixed;
}

Q_INVOKABLE int Grid::getDifficulty() const {
    return *difficulty;
}

void Grid::changeDifficulty() {
    if (*difficulty < 3) {
        *difficulty += 1;
    }
    else {
        *difficulty = 0;
    }
    emit sudokuDifficultyChanged(); // Updates the text in the button, doesn't change the difficulty unless a new game is started
}

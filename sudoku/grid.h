#ifndef GRID_H
#define GRID_H

#include <QObject>
#include <QList>

class Grid : public QObject
{
    Q_OBJECT
    // QProperties allows qml to automatically update values when a signal is emitted
    Q_PROPERTY(QList<int> qml_sudokuValues READ getSudokuValues NOTIFY sudokuValuesChanged)
    Q_PROPERTY(QList<QString> qml_sudokuColors READ getSudokuColors NOTIFY sudokuColorsChanged)
    Q_PROPERTY(int qml_difficulty READ getDifficulty NOTIFY sudokuDifficultyChanged)
    Q_PROPERTY(QList<bool> qml_isSudokuValueFixed READ getIsSudokuValueFixed NOTIFY sudokuGridChanged)
    Q_PROPERTY(int qml_theme READ getTheme NOTIFY sudokuThemeChanged)
public:
    Grid(QObject *parent = nullptr); // Null by default
    ~Grid();
    Q_INVOKABLE void select(int id);
    Q_INVOKABLE QList<int> getSudokuValues() const;
    Q_INVOKABLE QList<QString> getSudokuColors() const;
    Q_INVOKABLE QList<bool> getIsSudokuValueFixed() const;
    Q_INVOKABLE int getDifficulty() const;
    Q_INVOKABLE int getTheme() const;
    Q_INVOKABLE void setValue(int val);
    Q_INVOKABLE void setColor();
    Q_INVOKABLE void loadGrid();
    Q_INVOKABLE QList<int> getComparedCellsList(int id);
    Q_INVOKABLE void changeDifficulty();
    Q_INVOKABLE void changeTheme();
    Q_INVOKABLE bool hasWon();
    Q_INVOKABLE void setFinalColors();
    Q_INVOKABLE void saveGrid();
    Q_INVOKABLE void loadSavedGrid();
    std::string getCurrentDateTimeString();

private: // All attributes are private for encapsulation
    QList<int> sudokuValues;
    QList<bool> isSudokuValueFixed;
    QList<QString> sudokuColors;
    int *selected;
    int *difficulty;
    int *theme;
signals: // Allows QML to update when emitted thanks to QProperties
    void sudokuValuesChanged();
    void sudokuColorsChanged();
    void sudokuDifficultyChanged();
    void sudokuGridChanged();
    void sudokuThemeChanged();
};

#endif // GRID_H

#ifndef GRID_H
#define GRID_H

#include <QObject>

class Grid : public QObject {
    Q_OBJECT
public:
    Grid(QObject *parent = nullptr);
    Q_INVOKABLE int getValue(int id);
    Q_INVOKABLE void setValue(int id, int value);
    Q_INVOKABLE void select(int id);
    Q_INVOKABLE void write(int id,int key);
private:
    QList<int> list;
    int selected;
signals:
    void valueChanged(int id, int value);
    //void selectionChanged(int id);
};

#endif // GRID_H

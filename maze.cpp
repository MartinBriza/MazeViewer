#include "maze.h"
#include <QDebug>
#include <iostream>
#include <fstream>
using namespace std;

Maze::Maze(QObject *parent, const QString &file) :
    QObject(parent) {
    int width = 0, height = 0;
    ifstream is(file.toLatin1(), std::ifstream::in);
    is >> height >> width;
    for (int i = 0; i < height; i++) {
        QStringList sL;
        for (int j = 0; j < width; j++) {
            int cell = 0;
            is >> cell;
            sL.append(QString("%1").arg(cell));
        }
        m_cells.append(new Line(this, sL));
    }

}

QQmlListProperty<Line> Maze::cells() {
    return QQmlListProperty<Line>(this, m_cells);
}


Line::Line(QObject *parent, QStringList &line)
    : QObject(parent), m_cells(line) {

}

QStringList Line::cells() {
    return m_cells;
}

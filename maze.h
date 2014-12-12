#ifndef MAZE_H
#define MAZE_H

#include <QObject>
#include <QFile>
#include <QQmlListProperty>

class Line: public QObject {
    Q_OBJECT
    Q_PROPERTY(QStringList cells READ cells CONSTANT)
public:
    explicit Line(QObject *parent, QStringList &line);
    QStringList cells();
private:
    QStringList m_cells;
};

class Maze : public QObject {
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Line> cells READ cells CONSTANT)
public:
    explicit Maze(QObject *parent, const QString &file);
    QQmlListProperty<Line> cells();
private:
    QList<Line*> m_cells;
};

#endif // MAZE_H

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "maze.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterUncreatableType<Maze>("ofc", 1, 0, "Maze", "You already have an instance!");
    qmlRegisterUncreatableType<Line>("ofc", 1, 0, "Line", "You already have an instance!");
    Maze maze(&app, argv[1]);
    engine.rootContext()->setContextProperty("maze", &maze);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

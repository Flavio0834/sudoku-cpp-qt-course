#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "grid.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    Grid grid;

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/sudoku/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.rootContext()->setContextProperty("grid", &grid);
    engine.load(url);

    return app.exec();
}

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>
#include "dangNhap.h"
#include <QQmlProperty>
#include <QApplication>
#include <QGuiApplication>
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    //QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
#endif

    //QGuiApplication app(argc, argv);
    //QQmlApplicationEngine app(argc, argv);
    //Login login;
    //qmlRegisterType<dangNhap>("com.examples.DangNhap", 1, 0, "DangNhap");
    app.setWindowIcon(QIcon(":/images/iconMain.jpg"));
    QQmlApplicationEngine engine;
    //engine.rootContext()->setContextProperty("Login", &login);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
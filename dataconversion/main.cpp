#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>

#include <QDate>
#include <QMetaObject>
#include <QVariant>
#include <QArgument>
#include <QQuickItem>
#include <QQmlContext>

#include "cmyclass.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView view;
    view.setSource(QUrl(QStringLiteral("qrc:///Main.qml")));
    view.setResizeMode(QQuickView::SizeRootObjectToView);

    QVariantList list;
    list << 10 << QColor(Qt::green) << "bottles";

    QVariantMap map;
    map.insert("language", "QML");
    map.insert("released", QDate(2010, 9, 21));

    QMetaObject::invokeMethod(view.rootObject(), "readValues",
            Q_ARG(QVariant, QVariant::fromValue(list)),
            Q_ARG(QVariant, QVariant::fromValue(map)));

    MyClass myclass;
    view.rootContext()->setContextProperty("myclass", &myclass);
    view.show();
    return app.exec();
}


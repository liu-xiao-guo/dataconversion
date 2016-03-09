#include "cmyclass.h"

#include <QDebug>

MyClass::MyClass(QObject *parent) :
    QObject(parent)
{
}

void MyClass::callingFromQml(QVariantList list, QVariantMap map) {
    qDebug() << "It is called from QML!";

    int count = list.count();
    qDebug() << "count: " << list.count();
    qDebug() << "The array values are: ";

    for ( int i = 0; i < count; i++ ) {
        QString value = list[i].toString();
        qDebug() << "value: " << value;
    }

    qDebug() << "The object values are: ";

    qDebug() << "map.from" << map["from"].toString();
    qDebug() << "map.to" << map["to"].toString();
    qDebug() << "map.message" << map["message"].toString();
}

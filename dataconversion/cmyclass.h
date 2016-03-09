#ifndef CMYCLASS_H
#define CMYCLASS_H

#include <QObject>
#include <QVariantList>
#include <QVariantMap>

class MyClass : public QObject
{
    Q_OBJECT
public:
    explicit MyClass(QObject *parent = 0);
    Q_INVOKABLE void callingFromQml(QVariantList list, QVariantMap map);

signals:

public slots:

};

#endif // CMYCLASS_H

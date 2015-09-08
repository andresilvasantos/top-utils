#include "jsonhelper.h"

#include <QtQml>

void JsonHelper::declareQML()
{
    qmlRegisterSingletonType<JsonHelper>("TOP.Utils", 1, 0, "JsonHelper", qmlJsonHelperSingleton);
}

void JsonHelper::modifyValue(QJsonObject &obj, const QString &path, const QJsonValue &newValue)
{
    const int indexOfDot = path.indexOf('.');
    const QString propertyName = path.left(indexOfDot);
    const QString subPath = indexOfDot>0 ? path.mid(indexOfDot+1) : QString();

    QJsonValue subValue = obj[propertyName];

    if(subPath.isEmpty()) {
        subValue = newValue;
    }
    else {
        QJsonObject obj = subValue.toObject();
        modifyValue(obj,subPath,newValue);
        subValue = obj;
    }

    obj[propertyName] = subValue;
}

void JsonHelper::modifyValue(QJsonDocument &doc, const QString &path, const QJsonValue &newValue)
{
    QJsonObject obj = doc.object();
    modifyValue(obj,path,newValue);
    doc = QJsonDocument(obj);
}

void JsonHelper::removeKey(QJsonObject &obj, const QString &path, const QString &key)
{
    const int indexOfDot = path.indexOf('.');
    const QString propertyName = path.left(indexOfDot);
    const QString subPath = indexOfDot>0 ? path.mid(indexOfDot+1) : QString();

    QJsonObject subObject = obj[propertyName].toObject();

    if(subPath.isEmpty()) {
        subObject.remove(key);
    }
    else {
        removeKey(subObject,subPath,key);
    }

    obj[propertyName] = subObject;
}

void JsonHelper::removeKey(QJsonDocument &doc, const QString &path, const QString &key)
{
    QJsonObject obj = doc.object();
    removeKey(obj,path,key);
    doc = QJsonDocument(obj);
}

QString JsonHelper::docToString(QJsonDocument doc)
{
    return doc.toJson();
}

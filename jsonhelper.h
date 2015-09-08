#ifndef JSONHELPER_H
#define JSONHELPER_H

#include <QObject>
#include <QJsonDocument>

class QJSEngine;
class QQmlEngine;
class JsonHelper : public QObject
{
    Q_OBJECT
public:
    static void declareQML();

    static void modifyValue(QJsonObject& obj, const QString& path, const QJsonValue& newValue);
    static void modifyValue(QJsonDocument& doc, const QString& path, const QJsonValue& newValue);

    static void removeKey(QJsonObject &obj, const QString &path, const QString &key);
    static void removeKey(QJsonDocument &doc, const QString &path, const QString &key);

    Q_INVOKABLE static QString docToString(QJsonDocument doc);

signals:

public slots:

};

static QObject *qmlJsonHelperSingleton(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    return new JsonHelper;
}

#endif // JSONHELPER_H

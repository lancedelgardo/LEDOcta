#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "WiFiData.h"
#include "WiFiModel.h"
#include "InputItem.h"
#include "InputDatas.h"

int main(int argc, char *argv[])
{
    QGuiApplication::setApplicationName("BeerpongMe");
    QGuiApplication::setOrganizationName("LuA");
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    qmlRegisterType< WiFiModel >("WiFi", 1, 0, "WiFiModel");
    qmlRegisterUncreatableType< WiFiData >("WiFi", 1, 0, "WiFiData", QStringLiteral("WifiList should not be created in QML"));

    qmlRegisterType< InputItem >("InputItem", 1, 0, "InputItem");
    qmlRegisterUncreatableType< InputItem >("InputItem", 1, 0, "InputItem", QStringLiteral("InputItem should not be created in QML"));

    qmlRegisterType< InputDatas >("InputDatas", 1, 0, "InputDatas");
    qmlRegisterUncreatableType< InputDatas >("InputDatas", 1, 0, "InputDatas", QStringLiteral("InputDatas should not be created in QML"));

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    WiFiData wifiData;
    engine.rootContext()->setContextProperty(QStringLiteral("wifiData"), &wifiData);

    InputItem inputItem;
    engine.rootContext()->setContextProperty(QStringLiteral("inputItem"), &inputItem);

    InputDatas datas;
    engine.rootContext()->setContextProperty(QStringLiteral("inputDatas"), &datas);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

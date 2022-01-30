#include "EngineReloaderWrapper.h"
//API
#include <QQmlContext>
#include <QGuiApplication>

//
#include "GlobalVariant.h"

EngineReloaderWrapper::EngineReloaderWrapper()
{

}

EngineReloaderWrapper::~EngineReloaderWrapper()
{

}

void EngineReloaderWrapper::setContextProperies(QQmlContext * pQmlContext)
{
    qDebug() << "EngineReloaderWrapper::setContextProperies()";

    //Engine
    pQmlContext->setContextProperty("engine", this);
    //Engine.Global
    pQmlContext->setContextProperty("Global",GlobalVariant::Instance());
}

void EngineReloaderWrapper::registerToQml()
{
    qDebug() << "EngineReloaderWrapper::registerToQml()";

}

void EngineReloaderWrapper::beforeLoad()
{
    qDebug() << "EngineReloaderWrapper::beforeLoad()";

    setContextProperies(m_qmlContext);
    registerToQml();
}

void EngineReloaderWrapper::afterLoad()
{
    qDebug() << "EngineReloaderWrapper::afterLoad()";

    QObject *rootObject = qobject_cast<QObject*>(m_instance->rootObjects().first());

    QVariant returnedValue;
    QVariant file = "Hello from C++";
    QMetaObject::invokeMethod(rootObject, "initQmlLoader",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, file));
}

void EngineReloaderWrapper::setReloadSubQml( QString qsFile )
{
    qDebug() << "EngineReloaderWrapper::setReloadSubQml" << qsFile;

}

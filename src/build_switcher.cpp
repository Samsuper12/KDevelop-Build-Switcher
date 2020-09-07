#include "build_switcher.h"

//ECM
#include <debug.h>

//KF5
#include <KPluginFactory>

//QT5
#include <QAction>
#include <QDebug>


K_PLUGIN_FACTORY_WITH_JSON(Build_SwitcherFactory, "build_switcher.json", registerPlugin<Build_Switcher>(); )

Build_Switcher::Build_Switcher(QObject *parent, const QVariantList& args)
    : KDevelop::IPlugin(QStringLiteral("build_switcher"), parent)
{
    Q_UNUSED(args);

    //qCDebug(PLUGIN_BUILD_SWITCHER) << "Hello world, my plugin is loaded!";
}

KDevelop::ContextMenuExtension Build_Switcher::contextMenuExtension(KDevelop::Context* context, QWidget* parent) {
    
    KDevelop::ContextMenuExtension ext = KDevelop::IPlugin::contextMenuExtension(context, parent);
    
    QAction* action = new QAction("Hello, Maxim.");

    qDebug() << "Debug message.";
    
    ext.addAction(ext.BuildGroup, action);

    return ext;
}

// needed for QObject class created from K_PLUGIN_FACTORY_WITH_JSON
#include "build_switcher.moc"

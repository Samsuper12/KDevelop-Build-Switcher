#include "build_switcher.h"

#include <debug.h>

#include <KPluginFactory>

K_PLUGIN_FACTORY_WITH_JSON(Build_SwitcherFactory, "build_switcher.json", registerPlugin<Build_Switcher>(); )

Build_Switcher::Build_Switcher(QObject *parent, const QVariantList& args)
    : KDevelop::IPlugin(QStringLiteral("build_switcher"), parent)
{
    Q_UNUSED(args);

    qCDebug(PLUGIN_BUILD_SWITCHER) << "Hello world, my plugin is loaded!";
}

// needed for QObject class created from K_PLUGIN_FACTORY_WITH_JSON
#include "build_switcher.moc"

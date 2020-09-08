#include "build_switcher.h"

//ECM
#include <debug.h>

//KF5
#include <KPluginFactory>
#include <KLocalizedString>

//QT5
#include <QAction>
#include <QDebug>
#include <QMenu>

//Build_Switcher
#include "tool_widget.hpp"

K_PLUGIN_FACTORY_WITH_JSON(Build_SwitcherFactory, "build_switcher.json", registerPlugin<Build_Switcher>(); )

Build_Switcher::Build_Switcher(QObject *parent, const QVariantList& args)
    : KDevelop::IPlugin(QStringLiteral("build_switcher"), parent)
{
    Q_UNUSED(args);
    
    auto* toolView = new ToolWidgetFactory();
    core()->uiController()->addToolView(QStringLiteral("Switcher"), toolView);
}

KDevelop::ContextMenuExtension Build_Switcher::contextMenuExtension(KDevelop::Context* context, QWidget* parent) {
    
    KDevelop::ContextMenuExtension ext = KDevelop::IPlugin::contextMenuExtension(context, parent);
    
    auto* actionMenu = new QMenu;
    actionMenu->setTitle("QMenu");
    
    auto* actionFirst = new QAction("First checkable");
    auto* actionSecond = new QAction("Second checkable");
    
    actionFirst->setCheckable(true);
    actionSecond->setCheckable(true);
    
    actionMenu->addAction(actionFirst);
    actionMenu->addAction(actionSecond);
    
    ext.addAction(ext.ExtensionGroup, actionMenu->menuAction());
    
    connect(actionFirst, &QAction::toggled, this, [&](bool checked) {
        qDebug() << "First action is: " << checked;
        /* Происходит взрыв, если снять комментарий. Сам по себе он не хочет ставить чекедом его.
         * Следовательно мы должны запоминать его состояние от вызова к вызову контекстного меню.
         * И если допустим, при первом запуске KDevelop у нас стоит debug, то setChecked на него.
         * Вроде бы придает вариативности + адаптивности, но всё равно чувствуется сырость.
         */
        
        //actionFirst->setChecked(checked);
    });
    
    connect(actionSecond, &QAction::toggled, this, [&](bool checked) {
        qDebug() << "Second action is: " << checked;
    });

    return ext;
}

// needed for QObject class created from K_PLUGIN_FACTORY_WITH_JSON
#include "build_switcher.moc"

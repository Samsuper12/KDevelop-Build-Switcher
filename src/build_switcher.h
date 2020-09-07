#ifndef BUILD_SWITCHER_H
#define BUILD_SWITCHER_H

#include <interfaces/iplugin.h>
#include <kdevplatform/interfaces/contextmenuextension.h>

class Build_Switcher : public KDevelop::IPlugin
{
    Q_OBJECT

public:
    // KPluginFactory-based plugin wants constructor with this signature
    explicit Build_Switcher(QObject* parent, const QVariantList& args);
    
    virtual KDevelop::ContextMenuExtension contextMenuExtension(KDevelop::Context* context, QWidget* parent) override;
};

#endif // BUILD_SWITCHER_H

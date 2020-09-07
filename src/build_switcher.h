#ifndef BUILD_SWITCHER_H
#define BUILD_SWITCHER_H

#include <interfaces/iplugin.h>

class Build_Switcher : public KDevelop::IPlugin
{
    Q_OBJECT

public:
    // KPluginFactory-based plugin wants constructor with this signature
    Build_Switcher(QObject* parent, const QVariantList& args);
};

#endif // BUILD_SWITCHER_H

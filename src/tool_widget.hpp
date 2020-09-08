#ifndef KDEVPLATFORM_TOOL_WIDGET
#define KDEVPLATFORM_TOOL_WIDGET
#include <QWidget>

#include <interfaces/iuicontroller.h>

class ToolWidget;
class ToolWidgetFactory;

class ToolWidget final : public QWidget {
  Q_OBJECT
public:
    explicit ToolWidget(QWidget* parent = nullptr);
    ~ToolWidget() = default;
};

class ToolWidgetFactory final : public KDevelop::IToolViewFactory {
public:
    explicit ToolWidgetFactory() = default;
    ~ToolWidgetFactory() = default;
    
    QWidget* create(QWidget* parent = nullptr) override;
    Qt::DockWidgetArea defaultPosition() const override;
    QString id() const override;
};

#endif // KDEV_PLATFORM_TOOL_WIDGET

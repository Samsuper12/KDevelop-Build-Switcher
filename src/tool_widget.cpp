#include "tool_widget.hpp"

//Qt5
#include <QDebug>
#include <QHBoxLayout>
#include <QPushButton>

ToolWidget::ToolWidget(QWidget* parent)
    : QWidget(parent)  
{
    qDebug() << "Tool Widget";
    auto* hlay = new QHBoxLayout;
    
    hlay->addWidget(new QPushButton("ClickMe!"));
    this->setLayout(hlay);
}

QWidget* ToolWidgetFactory::create(QWidget* parent) {
    return new ToolWidget(parent);
}

Qt::DockWidgetArea ToolWidgetFactory::defaultPosition() const {
    return Qt::DockWidgetArea::BottomDockWidgetArea;
}

QString ToolWidgetFactory::id() const {
    return QStringLiteral("org.name.Build_Switcher");
}

#ifndef WIDGET_H
#define WIDGET_H

#include "formtest.h"
#include "formvideo.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    FormVideo frmVideo;
    FormTest frmTest;
private slots:
    void onCloseClicked();
    void onMaxClicked();
    void onMinClicked();
    void mainMenuClicked();

};
#endif // WIDGET_H

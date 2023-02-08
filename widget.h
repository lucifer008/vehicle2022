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
    void loadStyle(const QString &qssFile);
private slots:
    void onCloseClicked();
    void onMaxClicked();
    void onMinClicked();
    void mainMenuClicked();
    void on_btnStyle_Lightblue_clicked();
    void on_btnStyle_Flatgray_clicked();
    void on_btnStyle_Blacksoft_clicked();
};
#endif // WIDGET_H

#ifndef WIDGET_H
#define WIDGET_H

#include "ffmpeg.h"
#include "formtest.h"
#include "formvideo.h"
#include "mapindex.h"
#include "videoffmpeg.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Home : public QWidget
{
    Q_OBJECT

public:
    Home(QWidget *parent = nullptr);
    ~Home();

private:
    bool mouse_press=false;
    QPoint mousePoint;
    Ui::Widget *ui;
    FormVideo frmVideo;
    FormTest frmTest;
    MapIndex mapIndex;
    FFmpegWidget ffWidget;
    VideoFFMpeg videoFFmpeg;
    void loadStyle(const QString &qssFile);
private slots:
    void onCloseClicked();
    void onMaxClicked();
    void onMinClicked();
    void mainMenuClicked();
    void on_btnStyle_Lightblue_clicked();
    void on_btnStyle_Flatgray_clicked();
    void on_btnStyle_Blacksoft_clicked();


protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
void mouseReleaseEvent(QMouseEvent *event);

};
#endif // WIDGET_H

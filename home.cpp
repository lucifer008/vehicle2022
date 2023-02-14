#include "home.h"
#include "./ui_widget.h"
#include <QList>
#include <QMessageBox>
#include <QAbstractButton>
#include <qelapsedtimer.h>
#include <qfile.h>
#include "map.h"
#include "formvideo.h"
#include "videotools.h"
//#include "test.h"

Home::Home(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    //设置无边框
    this->setWindowFlags(Qt::FramelessWindowHint);

    ui->setupUi(this);
    //绑定通用按钮槽处理:最大化，最小化，关闭
    connect(ui->pushButtonMin,&QPushButton::clicked,this,&Home::onMinClicked);
    connect(ui->pushButtonMax,&QPushButton::clicked,this,&Home::onMaxClicked);
    connect(ui->toolButtonClose,&QToolButton::clicked,this,&Home::onCloseClicked);

    //绑定主业务处理信号槽处理事件
    QList<QAbstractButton *> listBus=ui->widgetBusiness->findChildren<QAbstractButton *>();
    foreach (QAbstractButton *btn, listBus) {
        connect(btn,&QToolButton::clicked,this,&Home::mainMenuClicked);
    }

    //测试皮肤
    //this->on_btnStyle_Blacksoft_clicked();
    //this->on_btnStyle_Flatgray_clicked();
    this->on_btnStyle_Lightblue_clicked();
}

Home::~Home()
{
    delete ui;
}
void Home::onCloseClicked(){
//    QMessageBox msgBox;
//    msgBox.setText("关闭.");
//    msgBox.exec();
     exit(0);
}
void Home::onMinClicked() {
    QMessageBox msgBox;
    msgBox.setText("最小化.");
    msgBox.exec();
}
void Home::onMaxClicked(){
    QMessageBox msgBox;
    msgBox.setText("最大化.");
    msgBox.exec();
}

void Home::mainMenuClicked(){
    QAbstractButton *btn=(QAbstractButton *)sender();

    QString btnTxt=btn->text();
    QList<QAbstractButton *> tbtns = ui->widgetBusiness->findChildren<QAbstractButton *>();
    foreach (QAbstractButton *btnItem, tbtns) {
        btn->setChecked(btnItem == btn);
    }

    if (btnTxt == "首页") {
        //QObjectList qList=ui->stackedWidget->children();

        ui->stackedWidget->setCurrentIndex(0);

        //临时测试代码
        //测试QPushButton ico
        this->frmTest.setWindowModality(Qt::ApplicationModal);
        this->frmTest.show();
        return;
    } else if (btnTxt == "视频") {
        ui->stackedWidget->setCurrentIndex(1);
        this->ffWidget.setWindowModality(Qt::ApplicationModal);
        this->ffWidget.show();
        //设置默认视频地址
        this->ffWidget.setUrl("https://media.w3.org/2010/05/sintel/trailer.mp4");
        this->ffWidget.open();

        qDebug()<<"视频Demo.....";
        return;
    } else if (btnTxt == "设置") {
        ui->stackedWidget->setCurrentIndex(2);
        //子项目窗体调用演示
        //提升+手动增加控件展示
        this->frmVideo.setWindowModality(Qt::ApplicationModal);
        this->frmVideo.show();

        return;
    } else if (btnTxt == "地图") {
        ui->stackedWidget->setCurrentIndex(3);

        //测试地图
        this->mapIndex.setWindowModality(Qt::ApplicationModal);
        this->mapIndex.show();
        return;


    } else if (btnTxt == "情报") {
        ui->stackedWidget->setCurrentIndex(4);
        //提升+控件布局
        this->videoFFmpeg.setWindowModality(Qt::ApplicationModal);
        this->videoFFmpeg.show();

        return;
    }
    else if (btnTxt == "用户退出") {
        exit(0);
    }
    //   VideoTools videoTools;
    //   videoTools.play();
    //   Test test;
    //   test.hello();

    Map mapTest;
    mapTest.test();

    //子项目窗体调用演示
//    this->frmVideo.setWindowModality(Qt::ApplicationModal);
//    this->frmVideo.show();

}


void Home::loadStyle(const QString &qssFile)
{
    //开启计时
    QElapsedTimer time;
    time.start();

    //加载样式表
    QString qss;
    QFile file(qssFile);
    if (file.open(QFile::ReadOnly)) {
        //用QTextStream读取样式文件不用区分文件编码 带bom也行
        QStringList list;
        QTextStream in(&file);
        //in.setCodec("utf-8");
        while (!in.atEnd()) {
            QString line;
            in >> line;
            list << line;
        }

        file.close();
        qss = list.join("\n");
        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(paletteColor));
        //用时主要在下面这句
        qApp->setStyleSheet(qss);
    }

    qDebug() << "用时:" << time.elapsed();
}

void Home::on_btnStyle_Lightblue_clicked()
{
    loadStyle(":/qss/qss/lightblue.css");
}

void Home::on_btnStyle_Flatgray_clicked()
{
    loadStyle(":/qss/qss/flatgray.css");
}

void Home::on_btnStyle_Blacksoft_clicked()
{
    loadStyle(":/qss/qss/blacksoft.css");
}

//窗口拖动
void Home::mousePressEvent(QMouseEvent *event)
{

    if( (event->button() == Qt::LeftButton) ){
        mouse_press = true;
        mousePoint = event->globalPosition().toPoint()-this->pos();
//        event->accept();
    }
    else if(event->button() == Qt::RightButton){
        //如果是右键
       // this->close();

    }
}
void Home::mouseMoveEvent(QMouseEvent *event)
{


//    if(event->buttons() == Qt::LeftButton){  //如果这里写这行代码，拖动会有点问题
    if(mouse_press){
        move(event->globalPosition().toPoint() - mousePoint);
//        event->accept();
    }
}
void Home::mouseReleaseEvent(QMouseEvent *event)
{
    mouse_press = false;
}

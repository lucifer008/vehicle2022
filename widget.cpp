#include "widget.h"
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

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //绑定通用按钮槽处理:最大化，最小化，关闭
    connect(ui->pushButtonMin,&QPushButton::clicked,this,Widget::onMinClicked);
    connect(ui->pushButtonMax,&QPushButton::clicked,this,Widget::onMaxClicked);
    connect(ui->pushButtonClose,&QPushButton::clicked,this,Widget::onCloseClicked);

    //绑定主业务处理信号槽处理事件
    QList<QAbstractButton *> listBus=ui->widgetBusiness->findChildren<QAbstractButton *>();
    foreach (QAbstractButton *btn, listBus) {
        connect(btn,&QToolButton::clicked,this,Widget::mainMenuClicked);
    }

    //测试皮肤
    //this->on_btnStyle_Blacksoft_clicked();
    //this->on_btnStyle_Flatgray_clicked();
    this->on_btnStyle_Lightblue_clicked();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::onCloseClicked(){
    QMessageBox msgBox;
    msgBox.setText("关闭.");
    msgBox.exec();
}
void Widget::onMinClicked() {
    QMessageBox msgBox;
    msgBox.setText("最小化.");
    msgBox.exec();
}
void Widget::onMaxClicked(){
    QMessageBox msgBox;
    msgBox.setText("最大化.");
    msgBox.exec();
}

void Widget::mainMenuClicked(){
    QAbstractButton *btn=(QAbstractButton *)sender();

    QString btnTxt=btn->text();
    QList<QAbstractButton *> tbtns = ui->widgetBusiness->findChildren<QAbstractButton *>();
    foreach (QAbstractButton *btn, tbtns) {
        btn->setChecked(btn == btn);
    }

    if (btnTxt == "首页") {
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

        return;
    } else if (btnTxt == "地图") {
        ui->stackedWidget->setCurrentIndex(3);

        //测试地图
        this->mapIndex.setWindowModality(Qt::ApplicationModal);
        this->mapIndex.show();
        return;


    } else if (btnTxt == "情报") {
        ui->stackedWidget->setCurrentIndex(4);
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


void Widget::loadStyle(const QString &qssFile)
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

void Widget::on_btnStyle_Lightblue_clicked()
{
    loadStyle(":/qss/qss/lightblue.css");
}

void Widget::on_btnStyle_Flatgray_clicked()
{
    loadStyle(":/qss/qss/flatgray.css");
}

void Widget::on_btnStyle_Blacksoft_clicked()
{
    loadStyle(":/qss/qss/blacksoft.css");
}

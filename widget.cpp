#include "widget.h"
#include "./ui_widget.h"
#include <QList>
#include <QMessageBox>
#include <QAbstractButton>
#include "videotools.h"
#include "test.h"

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
   } else if (btnTxt == "视频") {
       ui->stackedWidget->setCurrentIndex(1);
   } else if (btnTxt == "设置") {
       ui->stackedWidget->setCurrentIndex(2);
   } else if (btnTxt == "地图") {
       ui->stackedWidget->setCurrentIndex(3);

} else if (btnTxt == "情报") {
    ui->stackedWidget->setCurrentIndex(4);
}
   else if (btnTxt == "用户退出") {
       exit(0);
   }
   VideoTools videoTools;
  videoTools.play();
   Test test;
   test.hello();
}

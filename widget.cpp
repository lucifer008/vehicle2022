#include "widget.h"
#include "./ui_widget.h"
#include <QMessageBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButtonMin,&QPushButton::clicked,this,Widget::onMinClicked);
    connect(ui->pushButtonMax,&QPushButton::clicked,this,Widget::onMaxClicked);
    connect(ui->pushButtonClose,&QPushButton::clicked,this,Widget::onCloseClicked);
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
void Widget::onMinClicked(){
    QMessageBox msgBox;
    msgBox.setText("最小化.");
    msgBox.exec();

}
void Widget::onMaxClicked(){
    QMessageBox msgBox;
    msgBox.setText("最大化.");
    msgBox.exec();
}

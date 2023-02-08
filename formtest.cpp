#include "formtest.h"
#include "ui_formtest.h"

FormTest::FormTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormTest)
{
    ui->setupUi(this);
    //测试资源图片
    QIcon icoClose;
    icoClose.addFile(tr(":/img/images/btn_close.png"));
   /* ui->pushButtonTest->resize(118, 120);
    ui->pushButtonTest->setFlat(true);
    ui->pushButtonTest->setStyleSheet("QPushButton{background-color:rgba(0,0,0,0);border:none;}"); // background-color 设置背景色透明；
*/
    ui->pushButtonTest->setIcon(icoClose);
//    ui->pushButtonTest->setIconSize(QSize(118, 120));//设置图标大小
}

FormTest::~FormTest()
{
    delete ui;
}

#include "videoffmpeg.h"
#include "ui_videoffmpeg.h"

VideoFFMpeg::VideoFFMpeg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoFFMpeg)
{
    ui->setupUi(this);
    QStringList urls;
    urls<<"https://media.w3.org/2010/05/sintel/trailer.mp4";
    urls << "http://www.w3school.com.cn/example/html5/mov_bbb.mp4";
    urls << "https://hls01open.ys7.com/openlive/6e0b2be040a943489ef0b9bb344b96b8.hd.m3u8";

    urls << "http://vfx.mtime.cn/Video/2019/02/04/mp4/190204084208765161.mp4";
    urls << "rtsp://admin:Admin123456@192.168.0.15:554/media/video1";
    ui->comboBoxVideoSource->addItems(urls);
    ui->comboBoxVideoSource->setCurrentIndex(0);
    connect(this->ui->pushButtonOpen,&QPushButton::clicked,this,[=](){
//         QString url = ui->comboBoxVideoSource->currentText().trimmed();
//        this->ui->widget->setUrl(url);
//        this->ui->widget->open();
        if (ui->pushButtonOpen->text() == "打开") {
            ui->pushButtonOpen->setText("关闭");
            //ui->pushButtonOpen->setVisible(true);
            QString url = ui->comboBoxVideoSource->currentText().trimmed();
            ui->widget->setUrl(url);
            ui->widget->open();
        } else {
            ui->pushButtonOpen->setText("打开");
            // ui->pushButtonOpen->setVisible(true);
            ui->widget->close();
        }
    });
}

VideoFFMpeg::~VideoFFMpeg()
{
    delete ui;
}

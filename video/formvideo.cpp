#include "formvideo.h"
#include "ui_formvideo.h"

FormVideo::FormVideo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormVideo)
{
    ui->setupUi(this);
}

FormVideo::~FormVideo()
{
    delete ui;
}

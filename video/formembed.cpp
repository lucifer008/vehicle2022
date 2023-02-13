#include "formembed.h"
#include "ui_formembed.h"

FormEmbed::FormEmbed(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormEmbed)
{
    ui->setupUi(this);
}

FormEmbed::~FormEmbed()
{
    delete ui;
}

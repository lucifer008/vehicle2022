#include "mapindex.h"
#include "ui_mapindex.h"

MapIndex::MapIndex(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapIndex)
{
    ui->setupUi(this);
}

MapIndex::~MapIndex()
{
    delete ui;
}

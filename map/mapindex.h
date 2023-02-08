#ifndef MAPINDEX_H
#define MAPINDEX_H

#include <QWidget>

namespace Ui {
class MapIndex;
}

class MapIndex : public QWidget
{
    Q_OBJECT

public:
    explicit MapIndex(QWidget *parent = nullptr);
    ~MapIndex();

private:
    Ui::MapIndex *ui;
};

#endif // MAPINDEX_H

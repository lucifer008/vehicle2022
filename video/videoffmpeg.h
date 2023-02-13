#ifndef VIDEOFFMPEG_H
#define VIDEOFFMPEG_H

#include <QWidget>

namespace Ui {
class VideoFFMpeg;
}

class VideoFFMpeg : public QWidget
{
    Q_OBJECT

public:
    explicit VideoFFMpeg(QWidget *parent = nullptr);
    ~VideoFFMpeg();

private:
    Ui::VideoFFMpeg *ui;
};

#endif // VIDEOFFMPEG_H

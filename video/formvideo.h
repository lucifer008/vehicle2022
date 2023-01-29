#ifndef FORMVIDEO_H
#define FORMVIDEO_H

#include <QWidget>

namespace Ui {
class FormVideo;
}

class FormVideo : public QWidget
{
    Q_OBJECT

public:
    explicit FormVideo(QWidget *parent = nullptr);
    ~FormVideo();

private:
    Ui::FormVideo *ui;
};

#endif // FORMVIDEO_H

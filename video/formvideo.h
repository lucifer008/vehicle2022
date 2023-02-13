#ifndef FORMVIDEO_H
#define FORMVIDEO_H

#include "ffmpeg.h"
#include <QWidget>


//#ifndef gcc45
//#include "libavutil/hwcontext.h"
//#include "libavutil/hwcontext_qsv.h"
//#endif

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
    FFmpegWidget *ffmpegWidget;
};

#endif // FORMVIDEO_H

#include "formvideo.h"
#include "ui_formvideo.h"
//引入ffmpeg头文件
//extern "C" {
//#include "libavutil/opt.h"
//#include "libavutil/time.h"
//#include "libavutil/frame.h"
//#include "libavutil/pixdesc.h"
//#include "libavutil/avassert.h"
//#include "libavutil/imgutils.h"
//#include "libavutil/ffversion.h"
//#include "libavutil/log.h"
//#include "libavcodec/avcodec.h"
//#include "libswscale/swscale.h"
//#include "libswresample/swresample.h"
//#include "libavformat/avformat.h"
//#include "libavfilter/avfilter.h"

//#ifdef ffmpegdevice
//#include "libavdevice/avdevice.h"
//#endif
//}

FormVideo::FormVideo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormVideo)
{
    ui->setupUi(this);
    // 设置控制台输出级别
    //const char *avcodecConfig =avcodec_configuration();

//    //printf("%s\n", avcodecConfig);
//        av_log_set_level(AV_LOG_DEBUG);

////        // 打印输出字符串Hello World ！
//        av_log(NULL, AV_LOG_DEBUG, "%s", "Hello World FFPEG!\n");
}

FormVideo::~FormVideo()
{
    delete ui;
}

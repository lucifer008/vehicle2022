#include "home.h"

#include <QApplication>
#include <qnetworkproxy.h>

int main(int argc, char *argv[])
{
    QNetworkProxyFactory::setUseSystemConfiguration(false);
    QApplication::setAttribute(Qt::AA_Use96Dpi);
    QApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::Floor);
    QApplication a(argc, argv);
    QFont font;
    //设置字体
    font.setFamily("Microsoft Yahei");
    font.setPixelSize(13);
    a.setFont(font);

    Home w;
    w.show();
    return a.exec();
}

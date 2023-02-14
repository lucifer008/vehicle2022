#include "mapindex.h"
#include "ui_mapindex.h"

#include <QtWebEngineCore/QWebEngineSettings>

MapIndex::MapIndex(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapIndex),
    m_view(new QWebEngineView(this))
{
    ui->setupUi(this);
    m_view->settings()->setAttribute(QWebEngineSettings::FullScreenSupportEnabled, true);
    m_view->load(QUrl("https://map.baidu.com/"));
    ui->tabWidget->addTab(m_view,QString("在线地图"));


//     connect(m_view->page(),
//             &QWebEnginePage::fullScreenRequested,
//             this,
//             &MapIndex::fullScreenRequested);

}

MapIndex::~MapIndex()
{
    delete ui;
}
void MapIndex::fullScreenRequested(){//(QWebEngineFullScreenRequest request){
//    if (request.toggleOn()) {
//        if (m_fullScreenWindow)
//            return;
//        request.accept();
//        m_fullScreenWindow.reset(new FullScreenWindow(m_view));
//    } else {
//        if (!m_fullScreenWindow)
//            return;
//        request.accept();
//        m_fullScreenWindow.reset();
//    }
}

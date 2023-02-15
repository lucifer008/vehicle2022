#ifndef MAPINDEX_H
#define MAPINDEX_H

#include <QWidget>

#include <QtWebEngineWidgets/QWebEngineView>

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
     QWebEngineView *m_view;
     QWebEngineView *offm_view;
      //QScopedPointer<FullScreenWindow> m_fullScreenWindow;

   private slots:
        //void fullScreenRequested(QWebEngineFullScreenRequest request);
     void fullScreenRequested();
};

#endif // MAPINDEX_H

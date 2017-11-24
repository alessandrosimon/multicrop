#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QString>
#include <QPixmap>
#include <QFileDialog>
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include "imageoverlay.h"
#include "overlaydialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void updateOverlayPos(QPointF pos);

private:
    Ui::MainWindow *m_ui;
    QPixmap *m_rawImage;
    QGraphicsScene *m_scene;
    QGraphicsPixmapItem *m_graphicsPixmap;
    QString m_filename;

    void clearScreen();

private slots:
    void loadImage();
    void zoomIn();
    void zoomOut();
    void addOverlay();
    void clearAll();
    void createImages();
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QString>
#include <QPixmap>
#include <QGraphicsPixmapItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPixmap *rawImage;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *graphicsPixmap;
    QString filename;

private slots:
    void loadImage();
    void zoomIn();
    void zoomOut();
    void addOverlay();
    void clearAll();
    void createImages();
};

#endif // MAINWINDOW_H

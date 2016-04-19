#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    rawImage(new QPixmap),
    scene(new QGraphicsScene(this)),
    graphicsPixmap(new QGraphicsPixmapItem)
{
    ui->setupUi(this);
    setWindowTitle("multicrop");

    // set up default welcome screen
    scene->addText("Please load an image.");
    ui->mainView->setScene(scene);
    ui->mainView->setCacheMode(QGraphicsView::CacheNone);

    // TODO connect slots and signals

}

MainWindow::~MainWindow()
{
    delete rawImage;
    delete graphicsPixmap;
    delete scene;
    delete ui;
}

void MainWindow::loadImage()
{

}

void MainWindow::zoomIn()
{

}

void MainWindow::zoomOut()
{

}

void MainWindow::addOverlay()
{

}

void MainWindow::clearAll()
{

}

void MainWindow::createImages()
{

}

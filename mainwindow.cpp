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
}

MainWindow::~MainWindow()
{
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

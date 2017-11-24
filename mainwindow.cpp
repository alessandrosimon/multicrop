#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow),
    m_rawImage(new QPixmap),
    m_scene(new QGraphicsScene(this)),
    m_graphicsPixmap(new QGraphicsPixmapItem)
{
    m_ui->setupUi(this);
    setWindowTitle("Multicrop");

    // Set up default welcome screen
    m_scene->addText("Please load an image.");
    m_ui->mainView->setScene(m_scene);
    m_ui->mainView->setCacheMode(QGraphicsView::CacheNone);

    // Connect slots and signals
    QObject::connect(m_ui->openPictureButton, &QPushButton::clicked,
                     this, &MainWindow::loadImage);
    QObject::connect(m_ui->createOverButton, &QPushButton::clicked,
                     this, &MainWindow::addOverlay);
    QObject::connect(m_ui->zoomInButton, &QPushButton::clicked,
                     this, &MainWindow::zoomIn);
    QObject::connect(m_ui->zoomOutButton, &QPushButton::clicked,
                     this, &MainWindow::zoomOut);
    QObject::connect(m_ui->createWallButton, &QPushButton::clicked,
                     this, &MainWindow::createImages);

}

MainWindow::~MainWindow()
{
    delete m_rawImage;
    delete m_graphicsPixmap;
    delete m_ui;
}

void MainWindow::clearScreen()
{
    foreach (QGraphicsItem* item, m_scene->items())
    {
        m_scene->removeItem(item);
    }
    m_ui->mainView->update();
}

void MainWindow::loadImage()
{
    clearScreen();
    m_filename = QFileDialog::getOpenFileName(this, tr("Open image"), "", tr("Files (*.*)"));

    m_rawImage->load(m_filename);
    m_graphicsPixmap->setPixmap(*m_rawImage);

    m_scene->addItem(m_graphicsPixmap);
    m_ui->mainView->setSceneRect(m_rawImage->rect());
}

// TODO: Zooming decreases image quality. Cache original picture or change scaling method
void MainWindow::zoomIn()
{
    m_ui->mainView->scale(1.25,1.25);
}

void MainWindow::zoomOut()
{
    m_ui->mainView->scale(0.75, 0.75);

}

void MainWindow::addOverlay()
{
    if (m_rawImage->isNull())
    {
        return;
    }

    OverlayDialog dialog(this);

    int x = 0;
    int y = 0;

    if (dialog.exec())
    {
        x = dialog.width();
        y = dialog.height();
    }

    // Evtl. check dimension, i.e. not larger than original picture
    if (x != 0 && y != 0)
    {
        new ImageOverlay(m_graphicsPixmap, m_scene, x, y);
    }
}

void MainWindow::clearAll()
{
    foreach (QGraphicsItem* item, m_scene->items())
    {
        m_scene->removeItem(item);
    }
    m_scene->addItem(m_graphicsPixmap);
}

void MainWindow::createImages()
{
    auto list = m_scene->items();

    // Potential source of bug. Assumes loaded image is first loaded
    if (list.length() == 1)
    {
        QMessageBox::warning(this, tr("Error"), tr("You need to load in image."), QMessageBox::Ok);
        return;
    }

    QString fullPath = QFileDialog::getSaveFileName(this, tr("Save Images"), "");

    if (fullPath.isEmpty()) return;

    QString path = fullPath.split(".").first();
    QString ending = fullPath.split(".").last();

    // TODO: Use same filetype as original image
    if (path == ending)
    {
        QMessageBox::warning(this, tr("Error"), tr("You forgot to specify a filetype."), QMessageBox::Ok);
        return;
    }

    qDebug() << path << ending;

    // Original picture is last element, therefore substract one
    for (int i = 0; i < list.count()-1; ++i)
    {
        QRectF rectParent = list[i]->mapRectToParent(list[i]->boundingRect());
        QImage image{m_filename};
        QImage copy = image.copy(rectParent.x(), rectParent.y(),
                                 rectParent.width(), rectParent.height());
        copy.save(path+QString::number(i)+QString(".")+ending);
    }
}

void MainWindow::updateOverlayPos(QPointF pos)
{
    qDebug() << pos;
}

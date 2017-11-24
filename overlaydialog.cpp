#include "overlaydialog.h"
#include "ui_overlaydialog.h"

OverlayDialog::OverlayDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OverlayDialog)
{
    ui->setupUi(this);
    setWindowTitle("Overlay");
}

OverlayDialog::~OverlayDialog()
{
    delete ui;
}

int OverlayDialog::width() const
{
    return ui->widthSpin->value();
}

int OverlayDialog::height() const
{
    return ui->heightSpin->value();
}

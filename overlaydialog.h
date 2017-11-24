#ifndef OVERLAYDIALOG_H
#define OVERLAYDIALOG_H

#include <QDialog>

namespace Ui {
class OverlayDialog;
}

class OverlayDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OverlayDialog(QWidget *parent = 0);
    ~OverlayDialog();

    int width() const;
    int height() const;

private:
    Ui::OverlayDialog *ui;
};

#endif // OVERLAYDIALOG_H
